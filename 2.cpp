



#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class pixel  
{
   protected: int x1,y1;
   public: 
          pixel() 
          {
	    x1=0;y1=0;
          }

          void setoff(int xx,int yy) 
          {
            x1=xx;
            y1=yy;
          }
};

class dcircle: public pixel 
{
     private: int r; 
     public:
           
     dcircle():pixel() 
     {
	  r=0;
     }

     void setrad(int z)  
     {
         r=z;
     }

     
     void drawbc()
     { 
        int i,x,y;
        float d;

        x=0, y=r;
        d = 3 - 2*r;
        
        do
        {
           putpixel(x1+x, y1+y,15);
           putpixel(x1+y, y1+x,15);
           putpixel(x1+y, y1-x,15);
           putpixel(x1+x, y1-y,15);
           putpixel(x1-x, y1-y,15);
           putpixel(x1-y, y1-x,15);
           putpixel(x1-y, y1+x,15);
           putpixel(x1-x, y1+y,15);

           if(d<=0)
           {
              x = x + 1;
              d = d + (4*x) + 6;
           }
           else
           {
              x = x + 1;
              y = y - 1;
              d = d + (4*x-4*y) + 10;
           }

        }while(x<=y);

    }


   
};

int main()
{
	int gd=DETECT,gm=VGAMAX;
	int i, x, y, r,ch, xmax,ymax,xmid,ymid;
	float a,b;
	char ans;
	dcircle c1;
        initgraph(&gd, &gm, NULL);
 	
        xmax = getmaxx();
	ymax = getmaxy();
	xmid = xmax /2;
	ymid = ymax /2;

	line(xmid,0,xmid,ymax); 
	line(0,ymid,xmax,ymid); 
	 	   
	  
	cout<<"\n Enter x: "; cin>>x;
	cout<<"\n Enter y: "; cin>>y;
	cout<<"\n Enter radius: "; cin>>r;
        c1.setoff(xmid+x, ymid-y);
        c1.setrad(r);
        c1.drawbc();
                 

        delay(3000);
	getch();
	closegraph();
	return 0;
}
