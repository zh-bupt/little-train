#include<stdlib.h>
#ifndef FLAG
#define FLAG 

#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

/*����𳵽ṹ*/ 
struct train{
	int number;//�����(ȡֵΪ1,2,3) 
	int speed;//���ٶ�
	int rounddirection;//�����з���,0��ʾ˳ʱ�����У�1��ʾ��ʱ������ 
	int state;//��״̬,1��ʾ�˶�,0��ʾֹͣ 
	int starttime;//�𳵷���ǰ�ȴ�ʱ�� 
	int stoptime;//���ڹ�������ϵ�ͣ��ʱ�� 
	float xcoordinate;//��λ�ú����� 
	float ycoordinate;//��λ�������� 
	float bend[4][2];//���������� 
	int direction;//�𳵵ķ��� 
	float checkpoint[4][2];//����λ��  
};

typedef struct train TRAIN;//�Զ������������ 

#endif



