//Implementation of Digital Differential Analyzer(DDA) Line algorithm

#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

void main()
{
float x,y,x1,y1,x2,y2,dx,dy,step;
int i,gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOCS\\BGI");
cout<<"Rnter the value of x1 and y1";
cin>>x1>>y1;
cout<<"Enter the value of x2 and y2";
cin>>x2>>y2;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
{
step=dx;
}
else
{
step=dy;
}
dx=dx/step;
dy=dy/step;
x=x1;
y=y1;
i=1;
while(i<=step)
{
putpixel(x,y,12);
x=x+dx;
y=y+dx;
i=i+1;
}
getch();
closegraph();
}