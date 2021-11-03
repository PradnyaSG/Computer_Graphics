//Scan Line Polygon filling algorithm

#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void swap_num(int *n1,int *n2)    //function to swap two integer numbers
{
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}
void swap_nm(float *m1,float *m2)  //function to swap two float numbers
{
	float tempy=*m1;
	*m1=*m2;
	*m2=tempy;
}
class polyg                  //class polyg to draw the polygon and fill it
{
  public:int x[20],y[20],s1x[10],s2x[10],s1y[10],s2y[10],ver,cl,ymin,ymax,xmin,xmax,i,k,l,j,s,c;
	 float m,inter[10],ptx,xd,yd;
	 void get();          //functions of class declared
	 void sort();
	 void scan_l();
	 void interc(int);
	 void show(int);
};
void polyg::get()           //function to take the input from the user
	    {
		cout<<"Enter the no. of vertices of the polygon";
		cin>>ver;
		for(i=0;i<ver;i++)
		{
		    cout<<"Enter x"<<(i+1)<<endl;
		    cin>>k;
		    cout<<"Enter y"<<(i+1)<<endl;
		    cin>>l;
		    x[i]=k;
		    y[i]=l;
		}
		cout<<"Enter the color integer from 1 to 15";
		cin>>cl;
		setcolor(cl);         //setcolor function is to set current
		ymax=y[0];            //drawing color to new color
		ymin=y[0];
		xmin=x[0];            //initializing the min and max to
		xmax=x[0];            //first variable in the array
		for(i=0;i<ver;i++)
		{
			if(y[i]>ymax)
			{
				ymax=y[i];    //calculating max and min values
			}
			if(y[i]<ymin)
			{
				ymin=y[i];
			}
			if(x[i]>xmax)
			{
			       xmax=x[i];
			}
			if(x[i]<xmin)
			{
				xmin=x[i];
			}
		}
		for(i=0;i<ver;i++)
		{
		    s1x[i]=x[i];    //s1x and s1y  to store the intial point
		    s1y[i]=y[i];
		    if(i==0)
		    {
			s2x[ver-1]=x[i];  //for the last edge the end point is
			s2y[ver-1]=y[i];  //first point in the array
		    }
		    else
		    {
			s2x[i-1]=x[i];  //s2x and s2y to store the end points
			s2y[i-1]=y[i];
		    }
		}
	    }
void polyg::sort()
	    {   for(i=0;i<ver;i++)
		{
			if(s1y[i]<s2y[i]) //sorting the elements so that s1y>s2y
			{
				swap_num(&s1y[i],&s2y[i]);
				swap_num(&s1x[i],&s2x[i]);
			}
		}

		for(i=ver-1;i>0;i--)
		{
		    for(j=0;j<i;j++)
		    {
			if(s1y[j]<s1y[j+1]) //sorting the y1 in descending order
			{
			    swap_num(&s1y[j],&s1y[j+1]);
			    swap_num(&s2y[j],&s2y[j+1]);
			    swap_num(&s1x[j],&s1x[j+1]);
			    swap_num(&s2x[j],&s2x[j+1]);
			}
			if(s1y[j]==s1y[j+1])  //if the two s1y elememnts are same
			{                     //than sort s2y in descending order for that
			    if(s2y[j]<s2y[j+1])
			    {
				swap_num(&s1y[j],&s1y[j+1]);
				swap_num(&s2y[j],&s2y[j+1]);
				swap_num(&s1x[j],&s1x[j+1]);
				swap_num(&s2x[j],&s2x[j+1]);
			    }
			}
			if(s1y[j]==s1y[j+1] && s2y[j]==s2y[j+1])
			{
			    if(s1x[j]>s1x[j+1])   //if the two s1y and s2y are same
			    {                    //than sort s1x in ascending oeder
				swap_num(&s1y[j],&s1y[j+1]);
				swap_num(&s2y[j],&s2y[j+1]);
				swap_num(&s1x[j],&s1x[j+1]);
				swap_num(&s2x[j],&s2x[j+1]);
			    }
			}
		    }
		}
	    }
void polyg::scan_l()
	    {
		s=ymax;  //setting the initial value to ymax
		while(s>=ymin)
		{
		    interc(s);
		    show(s);
		    s--;
		}

	    }
void polyg::interc(int u)
	    {
	       c=0;
	       for (i=0;i<ver;i++)
	       {
		   if(u<=s1y[i] && u>s2y[i] && s1y[i]!=s2y[i])
		   {                        //checking if the scan line is within
			xd=s2x[i]-s1x[i];  //the given line
			yd=s2y[i]-s1y[i];
			m=xd/yd;
			ptx=s1x[i]-(m*(s1y[i]-u));//calculating the intersection
			inter[c++]=ptx;

		    }
	       }
	       for(i=c-1;i>0;i--)   //sorting the intersection points in ascending order
	       {
		for(j=0;j<i;j++)
		{
			if(inter[j]>inter[j+1])
			{
			swap_nm(&inter[j],&inter[j+1]);
			}
		}
		}
	     }
void polyg::show(int v)
	    {
		for(i=0;i<ver;i++)  //drawing the boundary of the polygon
		{   if(i==ver-1)
		    {
		    line(x[ver-1],y[ver-1],x[0],y[0]);
		    }
		    else
		    {
		    line(x[i],y[i],x[i+1],y[i+1]);
		    }
		}
		for(i=0; i<c;i+=2)  //drawing the scan line using the line function
		{
		    delay(100);
		    line(inter[i],v,inter[i+1],v);
		}
	    }




int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    polyg obj;    //creating the  object
    obj.get();   //calling the function
    obj.sort();
    obj.scan_l();
    getch();
    closegraph();
    return 0;
}
