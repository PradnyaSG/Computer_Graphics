//Snow flake generation using Koch curve

#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

class frac
{
	public:double x3,y3,x4,y4,x,y;
	       void koch_cur(double u1,double v1,double u2,double v2,int iter);
 };
void frac::koch_cur(double u1,double v1,double u2,double v2,int iter)
	   {
		  double x3,y3,x4,y4,x,y;
		x3=(2*u1+u2)/3;
		y3=(2*v1+v2)/3;
		x4=(u1+2*u2)/3;
		y4=(v1+2*v2)/3;
		x=x3+(x4-x3)*cos(60*3.14/180)+(y4-y3)*sin(60*3.14/180);
		y=y3-(x4-x3)*sin(60*3.14/180)+(y4-y3)*cos(60*3.14/180);
		line(u1,v1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,u2,v2);
		if(iter>0)
		{
			koch_cur(u1,v1,x3,y3,iter-1);
			koch_cur(x3,y3,x,y,iter-1);
			koch_cur(x,y,x4,y4,iter-1);
			koch_cur(x4,y4,u2,v2,iter-1);
		}
		line(u1,v1,x3,y3
	   }
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
frac obj;
obj.koch_cur(100,100,200,100,4);
obj.koch_cur(200,100,150,200,4);
obj.koch_cur(150,200,100,100,4);
getch();
closegraph();
return 0;
}