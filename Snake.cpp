/*
�������ˣ�����汾����Ϊ��û�й滮�ã��ķ����죬������Լ�˼�������ˣ�
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define Map_X 660
#define Map_Y 500
typedef struct snake
{
	int mode;//�ߵ��˶�ģʽ������
	int x,y;
	struct snake *next;
}SNAKE;

SNAKE play;
SNAKE egg;
int flag=1;//�ж���Ϸ�Ƿ����

void Draw_Map()
{
	initgraph(Map_X,Map_Y);
	//��ͼ���������
	setcolor(RED); //����ǰ��ɫ
	int A_x=10,A_y=10,B_x=10,B_y=10,i;
	setlinestyle(PS_DASHDOT);//�趨���ߵ���ʽ
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
	//��ͼ��������ƽ���
}
//���������ͼ�ν����ǣ�����ͼ�εĺ���������Ƶ��
void Draw_Box(int x,int y,int k)
{
	int left=10,top=10,right=50,bottom=50,i,j;
	setfillcolor(WHITE);
	for(i=0;i<y;i++)
	{ left+=40; right+=40; }
	for(j=0;j<x;j++)
	{ top+=40; bottom+=40; }
	//��Ϊ�������⣬��ǰ�����ʱ��û���Ǻã������ڽ��л���ʱ��Ҫ��ȥһ������ֵ�����Ӿ����ֲ�
	if(k==0)
		solidroundrect(left+1,top+1,right-1,bottom-1,40,40);//����
	else if(k==1)
		solidroundrect(left+1,top+1,right-1,bottom-1,15,15);//������
	else if(k==2)
	{
		setfillcolor(BLACK);
		solidrectangle(left+1,top+1,right-1,bottom-1);//���
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
	s_x+=15; s_y-=15;//ʹ�����䵽������
	if(getpixel(s_x,s_y)==WHITE)
		if(getpixel(s_x-14,s_y-14)==WHITE)
				return 1;
		else if(getpixel(s_x,s_y)==BLACK)
				return 2;
	else
		return 0;
	/*if(p!=NULL)//������ߵ����壬����1
		if(x==p->x&&y==p->y)
			return 1;
		else if(x==egg.x&&y==egg.y)//����ǵ�������2
			return 2;
		else
			Check(x,y,p->next);//����������һ�������Ա
	else
		return 0;//�����Ѿ������꣬ȷ������ģʽ
		
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
//��������0123
void Botton()
{
	int key;
	if(kbhit() != 0)//��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
	{
		while(kbhit() != 0)  //���ܴ��ڶ������,Ҫȫ��ȡ��,�����һ��Ϊ��  
		key = getch(); //�������ӿ���̨��ȡ�������浽key��  
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
	int old_x=play.x,old_y=play.y;//�Ծ�������б���
	switch(play.mode)
	{
	case 0: play.x-=1; break;
	case 1: play.x+=1; break;
	case 2: play.y-=1; break;
	case 3: play.y+=1; break;
	case 123:closegraph();//�ر���Ϸ����
	}
	//������
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
	start();//��Ϊ��һ��ʼ��Ҫ������֣��Լ�һЩ��ʼ���Ķ�����������Ҫ����дһ��start����ʼ���ͽ��һЩ����ͳһ�Ĳ���
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