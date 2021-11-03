//Cohen Sutherland Line Clipping Algorithm

#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>


class clip
{
    public:float pt1[4],pt2[4],i,x1,y1,x2,y2,nx1,ny1,xl,yl,in,out,xh,yh,skip,t;
	   float m1,m2,dx,dy;
	   void input();         //for taking input
	   void draw_before();     //line before clipping
	   void alloc1(int x1,int y1);  //to assign the code in array for pt1
	    void alloc2(int x2,int y2);//to assign the code in array for pt2
	   void check();      //clipping the liine
	   void draw_after();   //line after clipping

};
void clip::input()
	   {
	       cout<<"Enter the x-low and y-low"<<endl;
	       cin>>xl>>yl;
	       cout<<"Enter the x-high and y-high"<<endl;
	       cin>>xh>>yh;
	       cout<<"Enter the x-coordinates of first point "<<endl;
	       cin>>x1;
	       cout<<"Enter the y-coordinates of first point"<<endl;
	       cin>>y1;
	       cout<<"Enter the x-coordinates of the secod point"<<endl;
	       cin>>x2;
	       cout<<"Enter the y-coordinates of the secod point"<<endl;
	       cin>>y2;
	       draw_before();
	       delay(1000);
	       alloc1(x1,y1);
	       alloc2(x2,y2);       //functions called
	       check();
	   }
void clip::draw_before()
		{
			line(xl,yl,xh,yl);
			line(xl,yl,xl,yh);
			line(xh,yl,xh,yh);
			line(xl,yh,xh,yh);        //line before clipping
			line(x1,y1,x2,y2);
			delay(2000);
		}
void clip::alloc1(int x1,int y1)
	   {
		   if(y1>yh)
		       pt1[0]=1;

		   else            //checking the conditions for each region
			pt1[0]=0;
				  //alloting 1 if present in that region or 0
		   if(y1<yl)
		       pt1[1]=1;

		   else
			pt1[1]=0;

		   if(x1>xh)
		       pt1[2]=1;

		   else
			pt1[2]=0;

		   if(x1<xl)
		       pt1[3]=1;

		   else
			pt1[3]=0;


	   }
void clip::alloc2(int x2,int y2)
	   {
	       if(y2>yh)
		       pt2[0]=1;

		   else               //for point 2 alloting the code
			pt2[0]=0;

		   if(y2<yl)
		       pt2[1]=1;

		   else
			pt2[1]=0;

		   if(x2>xh)
		       pt2[2]=1;

		   else
			pt2[2]=0;

		   if(x2<xl)
		       pt2[3]=1;

		   else
			pt2[3]=0;

	   }
void clip::check()
	    {
	     dy=y2-y1;
	     dx=x2-x1;
	     m1=dy/dx;
	     m2=dx/dy;          //calculating the slope
	     in=0;
	     out=0;
	     t=0;                //initializing the variables
	     skip=0;
	     if((pt1[0]||pt2[0])==0 && ((pt1[1]||pt2[1])==0) && (pt1[2]||pt2[2])==0 && (pt1[3]||pt2[3])==0)
		{
			 in=1;     //checking the condition for completely inside
			 skip=1;   //oring should be 0000
		}
	     if(((pt1[0]&&pt2[0])!=0) || ((pt1[1]&&pt2[1])!=0) || ((pt1[2]&&pt2[2])!=0) || ((pt1[3]&&pt2[3])!=0))
		  {
			out=1;    //condition for completely outside
			skip=1;  //ANDING should be zero
		  }
	     if(in!=1 && out!=1) // if the line parally inside
	     {
		 for(i=3;i>=0;i--)
			 {
				 if(pt1[i]==1)  //for point 1 checking the intersection point
				 {
					 if(i==0)  //for above boundary intersection
					 {
						 nx1=((yh-y1)*m2)+x1;
						 ny1=yh;
						 x1=nx1;         //reinitializing the points
						 y1=ny1;
						 alloc1(x1,y1); //modifying the code

					 }
					 if(i==1) //intersection for below boundary
					 {
						 nx1=((yl-y1)*m2)+x1;
						 ny1=yl;
						 x1=nx1;
						 y1=ny1;
						 alloc1(x1,y1);
					 }
					 if(i==2)  //interection for right boundary
					 {
						 ny1=y1+m1*(xh-x1);
						 nx1=xh;
						 x1=nx1;
						 y1=ny1;
						 alloc1(x1,y1);

					 }
					 if(i==3)     //intesection for left boundary
					 {
						 ny1=y1+m1*(xl-x1);
						 nx1=xl;
						 x1=nx1;
						 y1=ny1;
						 alloc1(x1,y1);

					 }
				 }
		     }
		     for(i=3;i>=0;i--)
		     {           //for point2 checking intersection
			 if(pt2[i]==1)
			 {
				 if(i==0)
				 {
					nx1=((yh-y2)*m2)+x2;
					ny1=yh;
					x2=nx1;   //reinitializing
					y2=ny1;
					alloc2(x2,y2);  //modifying the code

				  }
				if(i==1)
				{
					nx1=((yl-y2)*m2)+x2;
					ny1=yl;
					x2=nx1;
					y2=ny1;
					alloc2(x2,y2);
				 }
				if(i==2)
				{
					ny1=y2+m1*(xh-x2);
					nx1=xh;
					x2=nx1;
					y2=ny1;
					alloc2(x2,y2);

				}
				if(i==3)
				{
					ny1=y2+m1*(xl-x2);
					nx1=xl;
					x2=nx1;
					y2=ny1;
					alloc2(x2,y2);
				}
			}

		 }

	}

 }
void clip::draw_after()
	    {   cleardevice();
		line(xl,yl,xl,yh);    //drawing the final clipped line
		line(xh,yl,xh,yh);
		line(xl,yl,xh,yl);
		line(xl,yh,xh,yh);
		if(in==1)       //if the line is completely inside
		line(x1,y1,x2,y2);
		else
		{       if(out==1)
			{
			 line(x1,y1,x2,y2);
			 delay(2000);
			 cleardevice();
			 cout<<"Line completely outside";
			 }
			else
			{
			line(x1,y1,x2,y2);

			 }
		}
		delay(100);
	    }
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    clip obj;             //object creation
    obj.input();
    obj.draw_after();
    getch();
    closegraph();
    return 0;
}