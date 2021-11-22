#include<stdio.h>
#include<time.h>
#include<omp.h>  //����ompͷ�ļ� 
using namespace std;
const int N = 1e8; //���廮�������� 
const int NUM_THREADS=4;
double pai = 0; //�洢����pai�Ľ�� 
int main() {
    clock_t startTime, endTime; //����ʱ��������ڼ�¼���̺ķ�ʱ�� 
    int i;  // i��Ϊ��ǰ�ֿ鴫���Ƶ���� 
    double tmpcal[NUM_THREADS]; //tmpcal����洢ÿһ�����̼���Ľ������ͨ�������������ܵ�pai 
    omp_set_num_threads(NUM_THREADS); //�����߳���Ŀ 
    startTime = clock(); //����ʼ 
    #pragma omp parallel private(i) // �����Ƶ���䣬���Ƶ���ʶ�����Ƶ����ƣ��Ӿ��Լ������ڴ��������
	{
    	int idnub = omp_get_thread_num(); //��ȡ��ǰ�̺߳ţ�������ⲿ����idnub�͵ô���������ֵ�Ҳ��� 
    	tmpcal[idnub]=0.0; //�Ե�ǰ�̴߳洢�����ʼ�� 
	    for (i = idnub; i < N; i += NUM_THREADS) {  //���i��0��ʼ��ô�͵�N-1������������׼ȷ 
	        double tmp = (i + 0.5) / N; //������ʾ��ʽ�е�( i + 0.5 ) / N
	        tmpcal[idnub] += 4 / (1 + tmp * tmp); //����ÿһ���������� 
	    }
			
	}
	
	for(int i=0;i<NUM_THREADS;i++) //��ÿһ���߳������ݽ��мӺ� 
		pai += tmpcal[i] ; 
		pai /= N; //����N,����pai����Ϊdouble���ͣ���������Է�ĸת��Ϊdouble���ͣ��Զ���߾��ȶ���
		endTime = clock(); //��¼�������ʱ�� 
		printf("Name:Chen Da\tStudent id:1004192118\n\n\n");
		printf("Calculation time:%ld ms\n pai is approximately:%.12f", endTime - startTime, pai);    //��ӡ��ʱ�ͽ�� 	
    return 0;
}
