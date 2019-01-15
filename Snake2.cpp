/*
编译器版本：Microsoft Visual C++ 2010 Express
电脑环境：Windows10专业版
第三方库：easyX
作者：Hexler
*/
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define Map_X 720
#define Map_Y 560
typedef struct snake
{
	int x,y;
	struct snake *next;
}SNAKE;
SNAKE play,egg,*head;
int flag=1;
int score=1;
int S_x,S_y,mode;
//XY轴二维图
void Start();
int main();
void Map()
{
	initgraph(Map_X,Map_Y);
	setcolor(BLUE);
	setfillcolor(BLACK);
	TCHAR s[]=_T("贪吃蛇 By Hexler");
	setlinestyle(PS_DASHDOT);
	solidrectangle(0,0,720,560);
	int A_x=40,A_y=40,B_x=40,B_y=40,i;
	
	for(i=0;i<=16;i++)
	{
		line(A_x,40,B_x,520);
		A_x+=40; B_x+=40;
	}
	for(i=0;i<=12;i++)
	{
		line(40,A_y,680,B_y);
		A_y+=40; B_y+=40;
	}
	settextcolor(GREEN);
	outtextxy(300,534,s);
}
//Plan模式0是画蛋，模式1是画方块，模式2是掩盖尾部，模式3是刷新上框提示
void Draw(int x,int y,int plan)
{
	setfillcolor(WHITE);
	setfillstyle(BS_SOLID);
	if(plan==0)
		solidcircle(x*40+20,y*40+20,18);
	else if(plan==1)
		solidroundrect(40*x+1,40*y+1,40*x+39,40*y+39,15,15);
	else if(plan==2)
	{
		setfillcolor(BLACK);
		solidroundrect(40*x+1,40*y+1,40*x+39,40*y+39,15,15);
	}
	else if(plan==3)
	{
		setfillcolor(BLACK);
		solidroundrect(80,0,600,39,40,40);
	}
}
//实时按钮反馈
void Botton()
{
	int key;
	if(kbhit()!=0)
	{
		while(kbhit()!=0)
		key = getch();
		TCHAR a[]=_T("向上");
		TCHAR b[]=_T("向下");
		TCHAR c[]=_T("向左");
		TCHAR d[]=_T("向右");
		TCHAR e[]=_T("暂停");
		switch(key)
		{
			case 72: if(mode==1&&score>1) break; outtextxy(10,534,a);  mode=0; break;
			case 80: if(mode==0&&score>1) break; outtextxy(10,534,b);  mode=1; break;
			case 75: if(mode==3&&score>1) break; outtextxy(10,534,c);  mode=2; break;
			case 77: if(mode==2&&score>1) break; outtextxy(10,534,d);  mode=3; break;
			case 32: outtextxy(10,534,e);getch(); Botton(); break;
			default: ;
		 }
	}
}
//随机生成蛋
void Egg()
{
	int x,y;
	SNAKE *p=head;
	x=rand()%16+1; y=rand()%12+1;
	while(p!=NULL)
	{
		if(p->x==x&&p->y==y)
		{
			x=rand()%16+1; y=rand()%12+1;
			p=head;
		}
		p=p->next;
	}
	Draw(x,y,0);
	egg.x=x; egg.y=y;
	
}
void move()
{
	TCHAR goal[5];
	_stprintf(goal,_T("得分：%d"),score);
	outtextxy(620,10,goal);
	switch(mode)
	{
	case 0:S_y-=1; break;
	case 1:S_y+=1; break;
	case 2:S_x-=1; break;
	case 3:S_x+=1; break;
	}
	if(S_x>16||S_y>12||S_x<1||S_y<1) flag=0;
	SNAKE *check=head;
	while(check!=NULL)
	{
		if(S_x==check->x&&S_y==check->y)
			flag=0;
		check=check->next;
	}
	if(flag)
		if(S_x==egg.x&&S_y==egg.y)
		{
			SNAKE *p,*temp;
			temp=(SNAKE *)malloc(sizeof(SNAKE));
			temp->next=head;
			temp->x=S_x; temp->y=S_y;
			head=temp;
			Draw(S_x,S_y,1);
			Egg();
			score++;
		}
		else
		{
			SNAKE *p,*q,*temp;
			temp=(SNAKE *)malloc(sizeof(SNAKE));
			temp->next=head;
			temp->x=S_x; temp->y=S_y;
			head=temp;
			Draw(S_x,S_y,1);
			q=p=head;
			while(p->next!=NULL)
			{
				q=p;
				p=p->next;
				if(p->next==NULL)
				Draw(p->x,p->y,2);
			}
			q->next=NULL;
		}
	else
	{
		settextcolor(RED);
		TCHAR s[]=_T("游戏结束 按空格重新开始 按其余键退出");
		outtextxy(230,10,s);
		if(' '==getch()) 
		{
			//Draw(0,0,3);
			flag=1;
			score=1;
			main();
		}
	}
}
void Start()
{
	int x,y;
	head=&play;
	play.next=NULL;
	Map();
	TCHAR s[]=_T("按任意键开始游戏");
	settextcolor(RED);
	srand((unsigned)time(NULL));
	x=rand()%16+1; y=rand()%12+1;
	play.x=x; play.y=y;
	S_x=x; S_y=y;
	Draw(x,y,1);
	Egg();
	outtextxy(290,15,s);
	getch();
	Draw(0,0,3);
}
int main()
{
	Start();
	while(flag)
	{
		Botton();
		move();
		Sleep(350);
	}
	getch();
	closegraph();
	return 0;
}