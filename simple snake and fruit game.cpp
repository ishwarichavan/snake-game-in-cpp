#include<iostream>
#include<stdlib.h>   //for rand function
#include<conio.h>   //for kbhit function
#include <Windows.h>  //for sleep function
using namespace std;
bool gameover;
int w=20,h=20; //w=width,h=height
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;
enum direction { STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;
	



void setup()    //set position of fruit
{
	gameover= false;
	dir=STOP;
	x=w/2;
	y=h/2;
	fruitx=rand() % w;  //rand()=return random integer value 
	fruity=rand() % h;
	score=0;
}
void draw()    //create a boundry
{
	system("cls");
	for(int i=0;i<w+2;i++)
	{
		cout<<"#";
		
	}
	cout<<endl;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(j==0)
				cout<<"#";
			if(i==y && j==x)
				cout<<"O";
			else if(i==fruity && j==fruitx)
				cout<<"*";	
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					
					if(tailx[k]==j &&taily[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
				if(!print)
					cout<<" ";
	     	}
			if(j==w-1)
			cout<<"#";
			
		}
		cout<<endl;
	}
	for(int i=0;i<w+2;i++)
	{
		cout<<"#";
		
	}
	cout<<endl;
    cout<<"Score: "<<score<<endl;
	
}
void input()      //taking input from keyboard
{
	if(_kbhit())         //kbhit()=use to determine if a key has been pressed or not	
	{
		switch(_getch())
		{
			case 'a':
				dir= LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'x':
				gameover=true;
				break;
			
		}
	}
}
void logic()   // control movement of snake
{
	
	int prex=tailx[0];
	int prey=taily[0];
	int pre2x,pre2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		pre2x=tailx[i];
		pre2y=taily[i];
		tailx[i]=prex;
		taily[i]=prey;
		prex=pre2x;
		prey=pre2y;
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;	
		default:
			break;
	}
	//if(x>w||x<0||y>h||y<0)   when snake strike to boundry it will over the game
		//gameover=true;
	
	if(x>=w)
	x=0;
	else if(x<0)
	x=w-1;
	if(y>=h)
	y=0;
	else if(y<0)
	y=h-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
			gameover=true;
	}
	if(x==fruitx && y==fruity)
	{
		
		score+=10;
		fruitx= rand() % w;
		fruity=rand() % h;
		ntail++;
	}
}
 int main()
 {
 	setup();
 	while(!gameover)
 	{
 		
		draw();
 		input();
 		logic();
 		Sleep(30);
 		
 		
	 }
 }
