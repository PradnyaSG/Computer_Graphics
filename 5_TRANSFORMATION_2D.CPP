//2D Transformations

#include <iostream.h>
#include <math.h> 
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void display(float r[][3])    //Funcion to display triangle
{
	line(r[0][0],r[0][1],r[1][0],r[1][1]);
        line(r[0][0],r[0][1],r[2][0],r[2][1]); 
        line(r[1][0],r[1][1],r[2][0],r[2][1]);

}
void display(float r[][3],int n) //Function to display rhombus
{                                //An extra argument to differentiate between the two overloaded functions 
	line(r[0][0],r[0][1],r[1][0],r[1][1]);
        line(r[0][0],r[0][1],r[3][0],r[3][1]);
        line(r[1][0],r[1][1],r[2][0],r[2][1]);
        line(r[2][0],r[2][1],r[3][0],r[3][1]);
}
void translation(float p[][3])
	     {

		  int i,j,k;
		  float tl[3][3],r1[3][3];
		 for(i=0;i<3;i++)     
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     tl[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     tl[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
		 cout<<"Enter the translation in x direction"<<endl;
		 cin>>tl[2][0];
		 cout<<"Enter the translation in y direction"<<endl;
		 cin>>tl[2][1];
                 clrscr();
		 for (i = 0; i < 3; i++)    //carried out by row major
		 {
		    for (j = 0; j < 3; j++)
		    {
			r1[i][j] = 0;
			for (k = 0; k < 3; k++)
			     r1[i][j] += p[i][k] * tl[k][j]; //multiplication 
		    }

		 }
		display(r1);
	     }
void translation(float p[][3],int m)
	     {
		  int i,j,k;
		  float tl[3][3],r1[4][3];
		 for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     tl[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     tl[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
		 cout<<"Enter the translation in x direction"<<endl;
		 cin>>tl[2][0];
		 cout<<"Enter the translation in y direction"<<endl;
		 cin>>tl[2][1];
                 clrscr();
		 for (i = 0; i < 4; i++) //Performed by row major
		 {
		    for (j = 0; j < 3; j++) 
		    {
			r1[i][j] = 0;
			for (k = 0; k < 3; k++)
			     r1[i][j] += p[i][k] * tl[k][j];//matrix multiplication
		    }

		 }
		 display(r1,4);
	     }

void rotation(float p[][3])
{
     int i,j,k;
     float ro[3][3],r2[3][3],sn,cs,ang;
		 for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     ro[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     ro[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
                 cout<<"To rotate anticlockwise enter the angle in positive"<<endl;
		 cout<<"To rotate clockwise enter the angle in negative"<<endl;
		 cout<<"Enter the angle by which you want to rotate"<<endl;
		 cin>>ang; //Taking input in degrees
                 clrscr();
		 ang=(ang*3.14)/180; //converting degrees to radians
		 sn=sin(ang);
		 cs=cos(ang);
		 ro[0][0]=cs;   
		 ro[0][1]=sn;
		 ro[1][0]=(-sn);
		 ro[1][1]=cs;
		 for (i = 0; i < 3; i++) //carried by row major
		 {
		    for (j = 0; j < 3; j++)
		    {
			r2[i][j] = 0.0;
			for (k = 0; k < 3; k++)
			     r2[i][j] += p[i][k] * ro[k][j];//matrix multiplication
		    }

		 }
		  display(r2);


}
void rotation(float p[][3],int m)
{
     int i,j,k;
     float ro[3][3],r2[4][3],sn,cs,ang;
		 for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     ro[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     ro[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
		 cout<<"To rotate anticlockwise enter the angle in positive"<<endl;
		 cout<<"To rotate clockwise enter the angle in negative"<<endl;
		 cout<<"Enter the angle by which you want to rotate"<<endl;
		 cin>>ang;//Taking input in degrees
                 clrscr();
		 ang=(ang*3.14)/180;//converting degrees to radians
		 sn=sin(ang);
		 cs=cos(ang);
		 ro[0][0]=cs;
		 ro[0][1]=sn;
		 ro[1][0]=(-sn);
		 ro[1][1]=cs;
		 for (i = 0; i < 4; i++)//carried by row major
		 {
		    for (j = 0; j < 3; j++)
		    {
			r2[i][j] = 0.0;
			for (k = 0; k < 3; k++)
			     r2[i][j] += p[i][k] * ro[k][j];//matrix multiplication
		    }

		 }
		  display(r2,4);



}
void scaling(float p[][3])
{
    int i,j,k;
    float r3[3][3],sc[3][3];
		 for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     sc[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     sc[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
		 cout<<"Enter the scaling in x direction";
		 cin>>sc[0][0];
		 cout<<"Enter the scaling in y direction";
		 cin>>sc[1][1];
                 clrscr();
		  for (i = 0; i < 3; i++)//carried by row major
		 {
		    for (j = 0; j < 3; j++)
		    {
			r3[i][j] = 0.0;
			for (k = 0; k < 3; k++)
			     r3[i][j] += p[i][k] * sc[k][j];//matrix multiplication
		    }

		 }
		  display(r3);


}
void scaling(float p[][3],int m)
{
    int i,j,k;
    float r3[4][3],sc[3][3];
		 for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
			 if(i==j)
			 {
			     sc[i][j]=1.0;//initializing diagonal elements to 1.0
			 }
			 else
			 {
			     sc[i][j]=0.0;//initializing to 0.0 if not a diagonal element
			 }

		     }
		 }
		 cout<<"Enter the scaling in x direction";
		 cin>>sc[0][0];
		 cout<<"Enter the scaling in y direction";
		 cin>>sc[1][1];
		 clrscr();
		  for (i = 0; i < 4; i++)
		 {
		    for (j = 0; j < 3; j++)
		    {
			r3[i][j] = 0.0;
			for (k = 0; k < 3; k++)
			     r3[i][j] += p[i][k] * sc[k][j];//matrix multiplication
		    }

		 }
		 display(r3,4);


}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    char choice1;
    int choice2,choice3,i,j;
    float p1[3][3],p2[4][3];
    cout<<"Enter 1.for transforming triangle"<<endl;
    cout<<"Enter 2.for transforming rhombus"<<endl;
    cin>>choice1;//To choice between the two-triangle and rhombus
    switch(choice1)
    {
    case '1': for(i=0;i<3;i++)
		 {
		     for(j=0;j<3;j++)
		     {
		     p1[i][j]=1.0;
		     }
		 }
	     cout<<"Enter the coordinates of the triangle"<<endl;
	     for(i=0;i<3;i++)
		 {
		     cout<<"Enter x"<<i<<":"<<endl;
		     cin>>p1[i][0];
		     cout<<"Enter y"<<i<<":"<<endl;
		     cin>>p1[i][1];

		 }
	    clrscr();
	    display(p1);
	    cout<<"Enter 1.for Translation"<<endl;
	    cout<<"Enter 2.for Rotation"<<endl;
	    cout<<"Enter 3.for Scaling"<<endl;
	    cin>>choice2;//To choose the desired transformation
	    if(choice2==1)
	    {
		translation(p1);
	    }
	    else
	    {
		if(choice2==2)
		{
		    rotation(p1);
		}
		if(choice2==3)
		{
		    scaling(p1);
		}
	    }
	    break;
	case '2':for(i=0;i<4;i++)
		 {
		     for(j=0;j<3;j++)
		     {
		     p2[i][j]=1.0;
		     }
		 }
		 cout<<"Enter the coordinates of the rhombus"<<endl;
		 for(i=0;i<4;i++)
		 {
		     cout<<"Enter x"<<i<<":"<<endl;
		     cin>>p2[i][0];
		     cout<<"Enter y"<<i<<":"<<endl;
		     cin>>p2[i][1];

		 }
		 clrscr();
		 display(p2,4);
		 cout<<"Enter 1.for Translation"<<endl;
		 cout<<"Enter 2.for Rotation"<<endl;
		 cout<<"Enter 3.for Scaling"<<endl;
		cin>>choice3;//To choose the desired transformation
		if(choice3==1)
		{
		     translation(p2,4);
		 }
		else
		{
		if(choice3==2)
		{
		    rotation(p2,4);
		}
		if(choice3==3)
		{
		    scaling(p2,4);
		}
	    }
		break;
    }
    getch();
    closegraph();

    return 0;
}