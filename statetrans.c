#include "statetrans.h"
#include "trainrun.h"
#include <time.h>
#include <windows.h>
#define q1 1
#define q2 2

extern clock_t start, current;//时间控制的外部变量 

/*状态转移函数(顺时针运行)*/
void StateTrans(TRAIN *train)
{
	int State=q1;//初始状态为q1 
	start = clock();
	while(1){
	switch(State){
		case q1:
			current = clock();
			if ((current - start) / CLOCKS_PER_SEC >= train->starttime) {//当启动时间用完后火车状态转到q2(运行状态) 
				State = q2;
				train->state = 1;
			}
			else//否则状态仍为q1 
				State = q1;
			break;
		case q2://运行状态 
			TrainRun(train);
			State = q2;
			break;
	}
}
}

/*状态转移函数(逆时针运行)*/
void StateTrans2(TRAIN *train)
{
	int State=q1;
	while(1){
	switch(State){
		case q1:
			current = clock();
			if ((current - start) / CLOCKS_PER_SEC >= train->starttime) {//当启动时间用完后火车状态转到q2(运行状态) 
				State = q2;
				train->state = 1;
			}
			else//否则状态仍为q1 
				State = q1;
			break;
		case q2://运行状态 
			TrainRun2(train);
			State = q2;
			break;
	}
}
}
