#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool game_over;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
enum edirection {STOP=0, LEFT, RIGHT, UP, DOWN};
edirection dir;
int tailX[100],tailY[100];
int ntail;

void setup()
{
	game_over=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand() % width;
	fruitY=rand() % height;
	score=0;
}

void draw()
{
	system("cls");
	for(int i=0;i<width+2;i++)
	{
		cout<<"@";
	}
	cout<<endl;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width+2;j++)
		{
			if(j==0 || j==width+1)
			{
				cout<<"@";
			}
			else if(i==y && j==x)
			{
				cout<<"O";
			}
			else if(i==fruitY && j==fruitX)
			{
				cout<<"F";
			}
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailX[k]==j && tailY[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
				if(!print)
				{
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	
	for(int i=0;i<width+2;i++)
	{
		cout<<"@";
	}
	cout<<endl;
	cout<<"SCORE:"<<score<<endl;
}

void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'x':
				game_over=true;
				break;				
		}
	}
}

void logic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X, prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
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
	}
//	if(x>width || x<0 || y<0 || y>height)
//	{
//		game_over=true;
//	}
	if(x>=width)
	{
		x=0;
	}
	else if(x<0)
	{
		x=width-1;
	}
	
	if(y>=height)
	{
		y=0;
	}
	else if(y<0)
	{
		y=height-1;
	}
	
	for(int i=0;i<ntail;i++)
	{
		if(tailX[i]==x && tailY[i]==y)
		{
			game_over=true;
		}
	}
	if(x==fruitX && y==fruitY)
	{
		score=score+50;
		fruitX=rand() % width;
	    fruitY=rand() % height;
	    ntail++;
	}
}

int main()
{
	setup();
 	while(!game_over)
 	{
		
 		draw();
 		input();
 		logic();
 		Sleep(50);
 	}
	return 0;
}
