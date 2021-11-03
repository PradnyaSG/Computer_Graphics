//Implementation of Bresenham Circle drawing algorithm

#include <graphics.h>      
#include <iostream.h>     
#include <dos.h>         
#include <conio.h>

void circle(float x1,float y1,float r)
{
float x,y,p;
p=3-(2*r);
x=0;
y=r;
while(x<=y)
{
putpixel(x1+x,y1+y,14);
putpixel(x1+y,y1+x,14);
putpixel(x1-x,y1+y,14);
putpixel(x1-y,y1+x,14);
putpixel(x1+x,y1-y,14);
putpixel(x1+y,y1-x,14);
putpixel(x1-x,y1-y,14);
putpixel(x1-y,y1-x,14);
delay(1000);
x=x+1;
if(p<0)
{
p=p+(4*x)+6;
}
else
{
p=p+(4*(x-y))+10 ;
y=y-1;
}
}
}

void main()
{
float x2,y2,rd;
int i,gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cout<<"Enter the coordinates of the center of circle";
cin>>x2>>y2;
cout<<"Enter the radius";
cin>>rd;
circle(x2,y2,rd);
getch();
closegraph();
}