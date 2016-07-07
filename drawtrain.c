#include <math.h>
#include <stdio.h>
#include "egg.h"
#include "drawtrain.h"
#include<time.h>
#define NUMBER_OF_EGG 5

extern TRAIN train1,train2,train3;
extern int commontrack1,commontrack2;
extern int controlstrategy; 
extern clock_t start, current;
extern clock_t begin1,begin31,begin2,begin32,end; 
EVENT_TYPE ev; 

void DrawTrain(void)
{
	HEGG hEggs[NUMBER_OF_EGG];
    int i,speed;
    int m,s,time=1;
    float temp1x,temp1y,temp2x,temp2y,temp3x,temp3y;
    SetAutoUpdate(0);
    for (i=0; i<NUMBER_OF_EGG; i++)
    {
        hEggs[i] = LayEgg();
        switch(i){
        	case 1:
        		MovePen((double)train1.xcoordinate-0.2,train1.ycoordinate+0.2);
				DrawBitmap("chartlet\\train1.bmp");
				break;
			case 2:
				MovePen((double)train2.xcoordinate-0.2,train2.ycoordinate+0.2);
				DrawBitmap("chartlet\\train2.bmp");
				break;
			case 3:
				MovePen((double)train3.xcoordinate-0.2,train3.ycoordinate+0.2);
				DrawBitmap("chartlet\\train3.bmp");
                break;
		}    
    }
    Update();
    temp1x=train1.xcoordinate;
    temp1y=train1.ycoordinate;
    temp2x=train2.xcoordinate;
    temp2y=train2.ycoordinate;
    temp3x=train3.xcoordinate;
    temp3y=train3.ycoordinate;
    while (1)
    {
    	SetActiveEgg(hEggs[0]);
    	end=clock();
    	/*监测点*/ 
    	if(commontrack1==0){
    	  SetPen(GREEN, 0.4);
    	  MovePen(train1.checkpoint[0][0],train1.checkpoint[0][1]+0.4);
    	  DrawLine(0, 0);
    	  MovePen(train1.checkpoint[1][0],train1.checkpoint[1][1]+0.4);
    	  DrawLine(0, 0);
		}
    	else{
    	  SetPen(RED, 0.4);
    	  MovePen(train1.checkpoint[0][0],train1.checkpoint[0][1]+0.4);
    	  DrawLine(0, 0);
    	  MovePen(train1.checkpoint[1][0],train1.checkpoint[1][1]+0.4);
    	  DrawLine(0, 0);
		}
    	if(commontrack2==0){
    	  SetPen(GREEN, 0.4);
    	  MovePen(train2.checkpoint[0][0]-0.4,train2.checkpoint[0][1]);
    	  DrawLine(0,0);
    	  MovePen(train2.checkpoint[1][0]-0.4,train2.checkpoint[1][1]);
    	  DrawLine(0,0);
		}
    	else{
    	  SetPen(RED, 0.4);
    	  MovePen(train2.checkpoint[0][0]-0.4,train2.checkpoint[0][1]);
		  DrawLine(0,0);
		  MovePen(train2.checkpoint[1][0]-0.4,train2.checkpoint[1][1]);
		  DrawLine(0,0);
		}
		
		/*控制策略输出*/ 
		if(controlstrategy==1)
		{
		 MovePen(25,7.8);
		 SetPen(RED, 0.4);
		 DrawLine(0,0);
		 SetPen(WHITE, 0.4);
		 MovePen(25,6.8);
		 DrawLine(0,0);
		 MovePen(25,5.8);
		 DrawLine(0,0);
		}
		else if(controlstrategy==2)
		{
		 MovePen(25,6.8);
		 SetPen(RED, 0.4);
		 DrawLine(0,0);
		 SetPen(WHITE, 0.4);
		 MovePen(25,7.8);
		 DrawLine(0,0);
		 MovePen(25,5.8);
		 DrawLine(0,0);
		}
		else if(controlstrategy==3)
		{
		 MovePen(25,5.8);
		 SetPen(RED, 0.4);
		 DrawLine(0,0);	
		 SetPen(WHITE, 0.4);
		 MovePen(25,7.8);
		 DrawLine(0,0);
		 MovePen(25,6.8);
		 DrawLine(0,0);
		}
		
		/*速度输出*/ 
		MovePen(26.5,5.3);
		switch(train1.speed/10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
		}
	    MovePen(27,5.3);
		switch(train1.speed%10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
		}
		MovePen(26.5,4.3);
		switch(train2.speed/10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
		}
	    MovePen(27,4.3);
		switch(train2.speed%10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
		}
		MovePen(26.5,3.3);
		switch(train3.speed/10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
		}
	    MovePen(27,3.3);
		switch(train3.speed%10){
			case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;		
	    }
	    
	    /*程序运行时间*/
	    current=clock();
	    time=(current-start)/CLOCKS_PER_SEC;
	    s=time%60;
	    m=time/60; 
	    MovePen(26,13);
	    switch(m/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		}
		MovePen(26.5,13);
		 switch(m%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		}
		MovePen(27.3,13);
	    switch(s/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		}
		MovePen(27.8,13);
		 switch(s%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		}
		    MovePen(24.3,11);
		    DrawBitmap("chartlet\\daojishi1.bmp");
		    MovePen(28.7,11);
		    DrawBitmap("chartlet\\0.bmp");
			MovePen(29.2,11);
		    DrawBitmap("chartlet\\0.bmp");
		    MovePen(24.3,10);
		    DrawBitmap("chartlet\\daojishi2.bmp");
		    MovePen(28.7,10);
		    DrawBitmap("chartlet\\0.bmp");
		    MovePen(29.2,10);
		    DrawBitmap("chartlet\\0.bmp");
		    SetPen(WHITE,0.1);
		    MovePen(28.6,10.8);
		    DrawLine(0,0);
		    MovePen(28.6,10.55);
		    DrawLine(0,0);
		    SetPen(WHITE,0.1);
		    MovePen(28.6,9.8);
		    DrawLine(0,0);
		    MovePen(28.6,9.55);
		    DrawLine(0,0);
		    MovePen(27.1,12.8);
		    DrawLine(0,0);
		    MovePen(27.1,12.55);
		    DrawLine(0,0);
		/*公轨停靠倒计时*/ 
		if(train1.state==0&&fabs(train1.xcoordinate-(train1.checkpoint[0][0]+train1.checkpoint[1][0])/2)<0.01&&fabs(train1.ycoordinate-(train1.checkpoint[0][1]+train1.checkpoint[1][1])/2)<0.01){
			MovePen(28.7,11);
		 switch((train1.stoptime-(end-begin1)/CLOCKS_PER_SEC)/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		    MovePen(29.2,11);
		    switch((train1.stoptime-(end-begin1)/CLOCKS_PER_SEC)%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		}
		if(train2.state==0&&fabs(train2.xcoordinate-(train2.checkpoint[0][0]+train2.checkpoint[1][0])/2)<0.01&&fabs(train2.ycoordinate-(train2.checkpoint[0][1]+train2.checkpoint[1][1])/2)<0.01){
			MovePen(28.7,10);
		 switch((train2.stoptime-(end-begin2)/CLOCKS_PER_SEC)/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		    MovePen(29.2,10);
		 switch((train2.stoptime-(end-begin2)/CLOCKS_PER_SEC)%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		}
		if(train3.state==0&&fabs(train3.xcoordinate-(train3.checkpoint[0][0]+train3.checkpoint[1][0])/2)<0.01&&fabs(train3.ycoordinate-(train3.checkpoint[0][1]+train3.checkpoint[1][1])/2)<0.01){
			MovePen(28.7,10);
		 switch((train3.stoptime-(end-begin32)/CLOCKS_PER_SEC)/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		    MovePen(29.2,10);
		 switch((train3.stoptime-(end-begin32)/CLOCKS_PER_SEC)%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		}
		if(train3.state==0&&fabs(train3.xcoordinate-(train3.checkpoint[2][0]+train3.checkpoint[3][0])/2)<0.01&&fabs(train3.ycoordinate-(train3.checkpoint[2][1]+train3.checkpoint[3][1])/2)<0.01){
			MovePen(28.7,11);
		 switch((train3.stoptime-(end-begin31)/CLOCKS_PER_SEC)/10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		    MovePen(29.2,11);
		 switch((train3.stoptime-(end-begin31)/CLOCKS_PER_SEC)%10){
	    	case 0:
			DrawBitmap("chartlet\\0.bmp");
			break;
			case 1:
			DrawBitmap("chartlet\\1.bmp");
			break;
			case 2:
			DrawBitmap("chartlet\\2.bmp");
			break;	
			case 3:
			DrawBitmap("chartlet\\3.bmp");
			break;
			case 4:
			DrawBitmap("chartlet\\4.bmp");
			break;
			case 5:
			DrawBitmap("chartlet\\5.bmp");
			break;
			case 6:
			DrawBitmap("chartlet\\6.bmp");
			break;
			case 7:
			DrawBitmap("chartlet\\7.bmp");
			break;
			case 8:
			DrawBitmap("chartlet\\8.bmp");
			break;
			case 9:
			DrawBitmap("chartlet\\9.bmp");
			break;
		    } 
		}
		if(fabs(train1.xcoordinate-train3.xcoordinate)<0.1&&fabs(train1.ycoordinate-train3.ycoordinate)<0.1&&(fabs(train1.xcoordinate-train1.checkpoint[0][0])>0.01||fabs(train1.ycoordinate-train1.checkpoint[0][1]>0.01)))
        {
		MovePen(26,12);
        DrawBitmap("chartlet\\zhuangchela.bmp");
	    }
	    else if(fabs(train2.xcoordinate-train3.xcoordinate)<0.1&&fabs(train2.ycoordinate-train3.ycoordinate)<0.1&&(fabs(train2.xcoordinate-train2.checkpoint[0][0])>0.01||fabs(train2.ycoordinate-train2.checkpoint[0][1]>0.01)))
        {
		MovePen(26,12);
        DrawBitmap("chartlet\\zhuangchela.bmp");
	    }
	    else 
	    {
	    MovePen(26,12);
	    DrawBitmap("chartlet\\xingshizhengchang.bmp");
		}
		SetActiveEgg(hEggs[1]);
        MoveEgg(train1.xcoordinate-temp1x,train1.ycoordinate-temp1y+15);
        SetActiveEgg(hEggs[2]);
        MoveEgg(train2.xcoordinate-temp2x,train2.ycoordinate-temp2y+15);
        SetActiveEgg(hEggs[3]);
        MoveEgg(train3.xcoordinate-temp3x,train3.ycoordinate-temp3y+15);
        Update();    
    }
}

void Eggcontrol(void)
{
	
	while ((ev = WaitForEvent())!= EXIT){
	    if (ev == KEYDOWN&&GetStruckKey()==VK_LBUTTON){//点击左键的情况 
            if((GetMouseX()-26)*(GetMouseX()-26)+(GetMouseY()-1)*(GetMouseY()-1)<0.16)
               	if(train1.state==1)
				  	train1.state=0;
				else
				  	train1.state=1;
            else if((GetMouseX()-27)*(GetMouseX()-27)+(GetMouseY()-1)*(GetMouseY()-1)<0.16)
               	if(train2.state==1)
				  	train2.state=0;
				else
				  	train2.state=1;
            else if((GetMouseX()-28)*(GetMouseX()-28)+(GetMouseY()-1)*(GetMouseY()-1)<0.16)
               	if(train3.state==1)
				  	train3.state=0;
				else
				  	train3.state=1;	
			else if((GetMouseX()-26)*(GetMouseX()-26)+(GetMouseY()-5)*(GetMouseY()-5)<0.04)
			    if(train1.speed==1);
			    else
				train1.speed--;
			else if((GetMouseX()-28)*(GetMouseX()-28)+(GetMouseY()-5)*(GetMouseY()-5)<0.04)
			    if(train1.speed==99);
			    else
				train1.speed++;
			else if((GetMouseX()-26)*(GetMouseX()-26)+(GetMouseY()-4)*(GetMouseY()-4)<0.04) 
			    if(train2.speed==1);
			    else
				train2.speed--;
			else if((GetMouseX()-28)*(GetMouseX()-28)+(GetMouseY()-4)*(GetMouseY()-4)<0.04)
			    if(train2.speed==99);
			    else
			    train2.speed++;
			else if((GetMouseX()-26)*(GetMouseX()-26)+(GetMouseY()-3)*(GetMouseY()-3)<0.04)
			    if(train3.speed==1);
			    else
				train3.speed--;
			else if((GetMouseX()-28)*(GetMouseX()-28)+(GetMouseY()-3)*(GetMouseY()-3)<0.04)
			    if(train3.speed==99);
			    else
			    train3.speed++;	
		    else if(GetMouseX()>26&&GetMouseX()<28.5&&GetMouseY()<8.2&&GetMouseY()>7.2)
		        controlstrategy=1;
		    else if(GetMouseX()>26&&GetMouseX()<28.5&&GetMouseY()<7.2&&GetMouseY()>6.2)
		        controlstrategy=2;
		    else if(GetMouseX()>26&&GetMouseX()<28.5&&GetMouseY()<6.2&&GetMouseY()>5.2)
		        controlstrategy=3;
		    PrintSpaInfo(); 
	   }  
	}
}
