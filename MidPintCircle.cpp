#include<iostream>
#include<graphics.h>
using namespace std;
void drawCircle(int x, int y, int xc, int yc);
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,(char*)"");

	int r, xc, yc, dk, x, y;
	cout<<" Enter the center co-ordinates"<<endl;
	cin>>xc>>yc;
	cout<<"Enter the radius of circle"<<endl;
	cin>>r;

	dk = 1 - r;
	x = 0;
	y = r;

	while(x < y)
	{
		drawCircle(x,y,xc,yc);
		x++;
		if(dk < 0)
		{
			dk = dk + (2*x) + 3;
		}
		else
		{
			y--;
			dk = dk + 2*(x-y) + 5 ;
		}
	}

	getch();
	closegraph();
	return 0;
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,WHITE);
	delay(10);
	putpixel(-x+xc,y+yc,WHITE);
	putpixel(x+xc, -y+yc,WHITE);
	putpixel(-x+xc, -y+yc, WHITE);
	putpixel(y+xc, x+yc, WHITE);
	putpixel(y+xc, -x+yc, WHITE);
	putpixel(-y+xc, x+yc, WHITE);
	putpixel(-y+xc, -x+yc, WHITE);
}
