#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

const float da=M_PI/20;

const int min=1;

const l0=300;

const int x0=320;
const int y0=240;



void draw(float d,float u)
{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	
	x1=floor(x0 + d * cos(u +   M_PI/4));
	y1=floor(y0 + d * sin(u +   M_PI/4));
	x2=floor(x0 + d * cos(u + 3*M_PI/4));
	y2=floor(y0 + d * sin(u + 3*M_PI/4));
	x3=floor(x0 + d * cos(u + 5*M_PI/4));
	y3=floor(y0 + d * sin(u + 5*M_PI/4));
	x4=floor(x0 + d * cos(u + 7*M_PI/4));
	y4=floor(y0 + d * sin(u + 7*M_PI/4));
	
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);	
}

int main(void)
{
	float l,a;
	int gdriver = DETECT, gmode, errorcode;
	
	initgraph(&gdriver, &gmode, "C:\\BC31\\BGI");
	
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	};
	setcolor(GREEN);
	l=l0;
	a=0;
	do
	{
		draw(l, a);
		a=a + da;
		l=l * sin(M_PI/4) / sin(3*M_PI/4 - da);
	}
	while(l>=min && !kbhit());
   
	getch();
	closegraph();
	return 0;
}

