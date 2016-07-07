#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <winsock.h>
#include <winbase.h>
#include "train.h"
#include "output.h"
#include "trainrun.h"
#include "input.h"
#include "statetrans.h"
#include "control.h"
#include "drawtrack.h"
#include "drawtrain.h"

extern int controlstrategy;
clock_t start, current,begin1,begin31,begin2,begin32,end; 
TRAIN train1={1},train2={2},train3={3};

int main(int argc, char *argv[]) {
	start=clock();
	printf("在程序运行时可以执行以下操作\n");
	printf("1.修改火车速度\n");
	printf("2.改变控制策略\n");
	printf("3.输入命令(暂停\\运行)\n"); 
	printf("4.修改火车停靠时间\n");
	printf("请输入控制策略(1为快车优先，2为交替策略，3为人工控制):");
	scanf_s("%d",&controlstrategy);
	DWORD ThreadID1 = 1;
    DWORD ThreadID2 = 2;
	DWORD ThreadID3 = 3;
	DWORD ThreadID4 = 4;
	DWORD ThreadID5 = 5;
	DWORD ThreadID6 = 6;
	DWORD ThreadID7 = 7;
	initialize(&train1);
	initialize(&train2);
	initialize(&train3);
	DrawTrack();
	HANDLE hRead1,hRead2,hRead3,hRead4,hRead5,hRead6,hRead7;
	hRead1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PrintInfo, NULL, 0, &ThreadID1);
	hRead5 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DrawTrain, NULL, 0, &ThreadID5);
	hRead6 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Eggcontrol, NULL, 0, &ThreadID6);
	if(train1.rounddirection==0)
	   hRead2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans, &train1, 0, &ThreadID2);
	else
	   hRead2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans2, &train1, 0, &ThreadID2);
	if(train2.rounddirection==0) 
	   hRead3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans, &train2, 0, &ThreadID3);
	else
	   hRead3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans2, &train2, 0, &ThreadID3);
	if(train3.rounddirection==0)
	   hRead4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans, &train3, 0, &ThreadID4);
	else
	   hRead4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StateTrans2, &train3, 0, &ThreadID4);
	while(1){
		Operate();	
	}
	return 0;
}
