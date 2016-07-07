#include<stdlib.h>
#ifndef FLAG
#define FLAG 

#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

/*定义火车结构*/ 
struct train{
	int number;//火车序号(取值为1,2,3) 
	int speed;//火车速度
	int rounddirection;//火车绕行方向,0表示顺时针运行，1表示逆时针运行 
	int state;//火车状态,1表示运动,0表示停止 
	int starttime;//火车发车前等待时间 
	int stoptime;//火车在公共轨道上的停靠时间 
	float xcoordinate;//火车位置横坐标 
	float ycoordinate;//火车位置纵坐标 
	float bend[4][2];//轨道弯道坐标 
	int direction;//火车的方向 
	float checkpoint[4][2];//监测点位置  
};

typedef struct train TRAIN;//自定义火车数据类型 

#endif



