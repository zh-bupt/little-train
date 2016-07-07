#include "egg.h"
#include "drawtrack.h"
#include<math.h>
extern TRAIN train1,train2,train3;
void DrawTrack(void)
{
   
    EggStart(30,15);
    DrawBitmap("chartlet\\back3.bmp");
    //���ƻ�1�Ĺ�� 
        SetPen(WHITE,0.03);
    	MovePen((double)train1.bend[0][0],train1.bend[0][1]+0.2);
	    DrawLine((train1.bend[1][0]-train1.bend[0][0]), 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train1.bend[2][1]-train1.bend[1][1]));
	    DrawArc(0.2, 0, -90); 
	    DrawLine((train1.bend[3][0]-train1.bend[2][0]), 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train1.bend[0][1]-train1.bend[3][1]));
		DrawArc(0.2, 180, -90); 	
		MovePen(train1.bend[0][0]+0.4,train1.bend[0][1]-0.2);
	    DrawLine((train1.bend[1][0]-train1.bend[0][0])-0.8, 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train1.bend[2][1]-train1.bend[1][1])+0.8);
	    DrawArc(0.2, 0, -90);
	    DrawLine((train1.bend[3][0]-train1.bend[2][0])+0.8, 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train1.bend[0][1]-train1.bend[3][1])-0.8); 
	    DrawArc(0.2, 180, -90); 
	//���ƻ�2�Ĺ�� 
    	MovePen(train2.bend[0][0],train2.bend[0][1]+0.2);
	    DrawLine((train2.bend[1][0]-train2.bend[0][0]), 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train2.bend[2][1]-train2.bend[1][1]));
	    DrawArc(0.2, 0, -90); 
	    DrawLine((train2.bend[3][0]-train2.bend[2][0]), 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train2.bend[0][1]-train2.bend[3][1]));
		DrawArc(0.2, 180, -90); 	
		MovePen(train2.bend[0][0]+0.4,train2.bend[0][1]-0.2);
	    DrawLine((train2.bend[1][0]-train2.bend[0][0])-0.8, 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train2.bend[2][1]-train2.bend[1][1])+0.8);
	    DrawArc(0.2, 0, -90);
	    DrawLine((train2.bend[3][0]-train2.bend[2][0])+0.8, 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train2.bend[0][1]-train2.bend[3][1])-0.8); 
	    DrawArc(0.2, 180, -90); 
    //���ƻ�3�Ĺ�� 
        MovePen(train3.bend[0][0],train3.bend[0][1]+0.2);
	    DrawLine((train3.bend[1][0]-train3.bend[0][0]), 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train3.bend[2][1]-train3.bend[1][1]));
	    DrawArc(0.2, 0, -90); 
	    DrawLine((train3.bend[3][0]-train3.bend[2][0]), 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train3.bend[0][1]-train3.bend[3][1]));
		DrawArc(0.2, 180, -90); 	
		MovePen(train3.bend[0][0]+0.4,train3.bend[0][1]-0.2);
	    DrawLine((train3.bend[1][0]-train3.bend[0][0])-0.8, 0);
	    DrawArc(0.2, 90, -90); 
	    DrawLine(0, (train3.bend[2][1]-train3.bend[1][1])+0.8);
	    DrawArc(0.2, 0, -90);
	    DrawLine((train3.bend[3][0]-train3.bend[2][0])+0.8, 0);
	    DrawArc(0.2, 270, -90); 
	    DrawLine(0,(train3.bend[0][1]-train3.bend[3][1])-0.8); 
	    DrawArc(0.2, 180, -90);
	//���ƹ������ 
		SetPen(RED, 0.4);
	    MovePen(train1.checkpoint[0][0]-0.2,train1.checkpoint[0][1]);
	    DrawLine((train1.checkpoint[1][0]-train1.checkpoint[0][0]+0.4), (train1.checkpoint[1][1]-train1.checkpoint[0][1])); 
	    MovePen(train2.checkpoint[0][0],train2.checkpoint[0][1]-0.2);
	    DrawLine((train2.checkpoint[1][0]-train2.checkpoint[0][0]), (train2.checkpoint[1][1]-train2.checkpoint[0][1]+0.4));
	    MovePen(24.3,15);
		DrawBitmap("chartlet\\kongzhitai.bmp");
	//����ͣ/�п��ư�ť
	    SetPen(RED, 0.8);
	    MovePen(26,1);
	    DrawLine(0,0);
	    SetPen(BLUE, 0.8);
	    MovePen(27,1);
	    DrawLine(0,0);
	    SetPen(YELLOW, 0.8);
	    MovePen(28,1);
	    DrawLine(0,0);
	//����վ̨
	if(fabs(train1.checkpoint[0][1]-train1.checkpoint[1][1])<0.01)
	{
		MovePen((train1.checkpoint[1][0]+train1.checkpoint[0][0])/2-0.6,train1.checkpoint[0][1]+1.7);
		DrawBitmap("chartlet\\zhantai.bmp");
	}
	else
	{
		MovePen(train1.checkpoint[0][0]-1.7,(train1.checkpoint[1][1]+train1.checkpoint[0][1])/2+0.6);
		DrawBitmap("chartlet\\zhantai.bmp");
	} 
	if(fabs(train2.checkpoint[0][1]-train2.checkpoint[1][1])<0.01)
	{
		MovePen((train2.checkpoint[1][0]+train2.checkpoint[0][0])/2-0.6,train2.checkpoint[0][1]+1.7);
		DrawBitmap("chartlet\\zhantai.bmp");
	}
	else
	{
		MovePen(train2.checkpoint[0][0]-1.7,(train2.checkpoint[1][1]+train2.checkpoint[0][1])/2+0.6);
		DrawBitmap("chartlet\\zhantai.bmp");
	}	
	//�����ٶȿ��ư�ť
	   	SetPen(RED, 0.4);
	    MovePen(26,5);
	    DrawLine(0,0);
	    MovePen(28,5);
	    DrawLine(0,0);
	    SetPen(BLUE, 0.4);
	    MovePen(26,4);
	    DrawLine(0,0);
	    MovePen(28,4);
	    DrawLine(0,0);
	    SetPen(YELLOW, 0.4);
	    MovePen(26,3);
	    DrawLine(0,0);
	    MovePen(28,3);
	    DrawLine(0,0);
	    //��ɫ��ť���� 
	    SetPen(BLACK,0.05);
		MovePen(25.85,5);
		DrawLine(0.3,0);
		MovePen(27.85,5);
		DrawLine(0.3,0);
		MovePen(28,4.85);
		DrawLine(0,0.3);
		//��ɫ��ť���� 
		MovePen(25.85,4);
		DrawLine(0.3,0);
		MovePen(27.85,4);
		DrawLine(0.3,0);
		MovePen(28,3.85);
		DrawLine(0,0.3);
		//��ɫ��ť���� 
		MovePen(25.85,3);
		DrawLine(0.3,0);
		MovePen(27.85,3);
		DrawLine(0.3,0);
		MovePen(28,2.85);
		DrawLine(0,0.3);
	//���ƿ��Ʋ��԰�ť 
		MovePen(25.8,8.2);
		DrawBitmap("chartlet\\FastFirst.bmp");
		MovePen(25.8,7.2);
		DrawBitmap("chartlet\\Alternate.bmp");
		MovePen(25.8,6.2);
		DrawBitmap("chartlet\\ManualOperation.bmp");
}
