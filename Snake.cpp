/*
气死我了，这个版本，因为我没有规划好，耗费两天，搞得我自己思绪都乱了！
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define Map_X 660
#define Map_Y 500
typedef struct snake
{
	int mode;//蛇的运动模式，方向
	int x,y;
	struct snake *next;
}SNAKE;

SNAKE play;
SNAKE egg;
int flag=1;//判断游戏是否结束

void Draw_Map()
{
	initgraph(Map_X,Map_Y);
	//地图的网格绘制
	setcolor(RED); //设置前景色
	int A_x=10,A_y=10,B_x=10,B_y=10,i;
	setlinestyle(PS_DASHDOT);//设定画线的样式
	for(i=0;i<=16;i++)
	{
		line(A_x,10,B_x,490);
		A_x+=40; B_x+=40;
	}
	for(i=0;i<=12;i++)
	{
		line(10,A_y,650,B_y);
		A_y+=40; B_y+=40;
	}
	//地图的网格绘制结束
}
//用数组代替图形界面是，绘制图形的函数，调用频繁
void Draw_Box(int x,int y,int k)
{
	int left=10,top=10,right=50,bottom=50,i,j;
	setfillcolor(WHITE);
	for(i=0;i<y;i++)
	{ left+=40; right+=40; }
	for(j=0;j<x;j++)
	{ top+=40; bottom+=40; }
	//因为计算问题，我前期想的时候没考虑好，所以在进行绘制时需要减去一个像素值进行视觉上弥补
	if(k==0)
		solidroundrect(left+1,top+1,right-1,bottom-1,40,40);//画蛋
	else if(k==1)
		solidroundrect(left+1,top+1,right-1,bottom-1,15,15);//画方块
	else if(k==2)
	{
		setfillcolor(BLACK);
		solidrectangle(left+1,top+1,right-1,bottom-1);//填充
	}
}
int Check(int x,int y,SNAKE *p)
{
	int i,j;
	int s_x=0,s_y=0;
	for(i=0;i<y;i++)
		s_x+=40;
	for(j=0;j<x;j++)
		s_y+=40;
	s_x+=15; s_y-=15;//使坐标落到方格中
	if(getpixel(s_x,s_y)==WHITE)
		if(getpixel(s_x-14,s_y-14)==WHITE)
				return 1;
		else if(getpixel(s_x,s_y)==BLACK)
				return 2;
	else
		return 0;
	/*if(p!=NULL)//如果是蛇的身体，返回1
		if(x==p->x&&y==p->y)
			return 1;
		else if(x==egg.x&&y==egg.y)//如果是蛋，返回2
			return 2;
		else
			Check(x,y,p->next);//继续访问下一个链表成员
	else
		return 0;//链表已经查找完，确认正常模式
		
}
void Egg()
{
	int x,y;
	x=rand()%12; y=rand()%16;
	if(Check(x,y,&play))
		Egg();
	else
	{
		egg.x=x; egg.y=x;
		Draw_Box(x,y,0);
	}
}
//上下左右0123
void Botton()
{
	int key;
	if(kbhit() != 0)//检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
	{
		while(kbhit() != 0)  //可能存在多个按键,要全部取完,以最后一个为主  
		key = getch(); //将按键从控制台中取出并保存到key中  
		switch(key)  
		{
			case 72:  play.mode=0; break;
			case 80:  play.mode=1; break;
			case 75:  play.mode=2; break;
			case 77:  play.mode=3; break;
			default: play.mode=123;
		 }
	}
}
void Create()
{

}
void Move()
{
	int old_x=play.x,old_y=play.y;//对旧坐标进行备份
	switch(play.mode)
	{
	case 0: play.x-=1; break;
	case 1: play.x+=1; break;
	case 2: play.y-=1; break;
	case 3: play.y+=1; break;
	case 123:closegraph();//关闭游戏出口
	}
	//新坐标
	if(Check(play.x,play.y,&play)==1)
	{
		exit(1);
		Draw_Box(play.x,play.y,1);
	}
	else if(Check(play.x,play.y,&play)==2)
	{
		exit(1);
		Draw_Box(play.x,play.y,1);
	}
	else if(Check(play.x,play.y,&play)==0)
	{
		Draw_Box(play.x,play.y,1);
		Draw_Box(old_x,old_y,2);
	}
}
void start()
{
	
}
int main(void)
{
	Draw_Map();
	start();//因为蛇一开始需要随机出现，以及一些初始化的东西，所以需要额外写一个start来初始化和解决一些不好统一的步骤
	while(flag)
	{
		Botton();
		Move();
		Sleep(400);
	}
	getchar();
	closegraph();
	return 0;
}
*/