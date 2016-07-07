#include "statetrans.h"
#include "trainrun.h"
#include <time.h>
#include <windows.h>
#define q1 1
#define q2 2

extern clock_t start, current;//ʱ����Ƶ��ⲿ���� 

/*״̬ת�ƺ���(˳ʱ������)*/
void StateTrans(TRAIN *train)
{
	int State=q1;//��ʼ״̬Ϊq1 
	start = clock();
	while(1){
	switch(State){
		case q1:
			current = clock();
			if ((current - start) / CLOCKS_PER_SEC >= train->starttime) {//������ʱ��������״̬ת��q2(����״̬) 
				State = q2;
				train->state = 1;
			}
			else//����״̬��Ϊq1 
				State = q1;
			break;
		case q2://����״̬ 
			TrainRun(train);
			State = q2;
			break;
	}
}
}

/*״̬ת�ƺ���(��ʱ������)*/
void StateTrans2(TRAIN *train)
{
	int State=q1;
	while(1){
	switch(State){
		case q1:
			current = clock();
			if ((current - start) / CLOCKS_PER_SEC >= train->starttime) {//������ʱ��������״̬ת��q2(����״̬) 
				State = q2;
				train->state = 1;
			}
			else//����״̬��Ϊq1 
				State = q1;
			break;
		case q2://����״̬ 
			TrainRun2(train);
			State = q2;
			break;
	}
}
}
