#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#define round(a) ((int)(a+0.5))
using namespace std;

void bezier_curve(const int[8]);
double nCr(int,int);
double factorial(int);
void dashed_line(const int,const int,const int,const int,const int=0);


int k;
float xmin,ymin,xmax,ymax,arr[20],m;

//clip left
void clipl(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 >= xmin && x2 >= xmin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 < xmin && x2 >= xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 >= xmin  && x2 < xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        k+=2;
    }
}
//clip top
void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}

//clip right
void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

//clip bottom
void clipb(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
    }
}

float polyy[20] ;
int poly[20];

void translation( int k )
{
    int dx=400,dy=0;

    for(int i=0; i < k; i+= 2)
    {
        poly[i]+= dx;
        poly[i+1] +=dy;
    }
    xmin += dx ,ymin += dy ,xmax += dx ,ymax += dy ;
}


void translation1( int k )
{
    int dx=-200,dy=150;
    for(int i=0; i < k; i+= 2)
    {
        poly[i]+= dx;
        poly[i+1] +=dy;
    }
    xmin += dx ,ymin += dy ,xmax += dx ,ymax += dy ;
}

int main()
{
    int gdriver=DETECT,gmode,n;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

    int xxx, yyy ;
    xxx = getmaxx() ;
    yyy = getmaxy() /2 ;

    setcolor(WHITE) ;

    line(0, yyy, xxx, yyy ) ;
    setcolor(WHITE) ;
    line(xxx/2, 0, xxx/2, yyy ) ;

    float xi,yi,xf,yf;
    cout<<"Coordinates of rectangular clip window :\nxmin,ymin             :";
    cin>>xmin>>ymin;
    cout<<"xmax,ymax             :";
    cin>>xmax>>ymax;
    cout<<"\n\nPolygon to be clipped :\nNumber of sides       :";
    cin>>n;
    cout<<"Enter the coordinates :";
    int i;
    for(i=0; i < 2*n; i++)
        cin>>polyy[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    for(i=0; i < 2*n+2; i++)
        poly[i]=round(polyy[i]);




    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);
    cout<<"\t\tUNCLIPPED POLYGON";
    setcolor(WHITE);
    // fillpoly(n,poly);
    //cleardevice();
    k=0;
    for(i=0; i < 2*n; i+=2)
        clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0; i < k; i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0; i < 2*n; i+=2)
        clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0; i < k; i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0; i < 2*n; i+=2)
        clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0; i < k; i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0; i < 2*n; i+=2)
        clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    for(int i=0, u = 1; i < k; i+=2 , u++)
    {
        poly[i]=round(arr[i]);
        poly[i+1]=round(arr[i+1]);
         cout << "point " << u << " : " << poly[i] << " " << poly[i+1] << endl ;
    }

    translation(k) ;

    //lets fill the poly after translation

    if(k){
        setcolor(WHITE) ;
        fillpoly(k/2,poly);
        setcolor(RED) ;
        rectangle(xmin,ymax,xmax,ymin);
    }
    cout<<"\tCLIPPED POLYGON";

    translation1(k) ;
     int control_points[8]= {0};
     for(int count=0 , u = 0 ; count<=k/2; count++)
    {
        control_points[(count*2)] = poly[ u++ ];
        control_points[((count*2)+1)] = poly[ u++ ];
    }
    setcolor(15);
    bezier_curve(control_points);
    getch();
    closegraph();


    return 0;
}



void bezier_curve(const int cp[8])
{
    int color=getcolor();
    setcolor(7);
    for(int count=0; count<3; count++)
        dashed_line(cp[(count*2)],cp[((count*2)+1)],cp[((count+1)*2)],cp[(((count+1)*2)+1)]
                   );
    float x;
    float y;
    for(float u=0.0005; u<=1; u+=0.0005)
    {
        float x=0;
        float y=0;
        for(int k=0; k<=3; k++)
        {
            x+=(cp[(k*2)]*nCr(3,k)*pow(u,k)*pow((1-u),(3-k)));
            y+=(cp[((k*2)+1)]*nCr(3,k)*pow(u,k)*pow((1-u),(3-k)));
        }
        putpixel((int)(x+0.5),(int)(y+0.5),color);
    }
}
double nCr(int n,int r)
{
    double nf,rf,nrf,ncr;
    nf=factorial(n);
    rf=factorial(r);
    nrf=factorial((n-r));
    ncr=(nf/(rf*nrf));
    return ncr;
}
double factorial(int number)
{
    double factorial=1;
    if(number==0 || number==1);
    else
    {
        for(int count=1; count<=number; count++)
            factorial=factorial*count;
    }
    return factorial;
}
void dashed_line(const int x_1,const int y_1,const int x_2,const int y_2,const int
                 line_type)
{
    int count=0;
    int color=getcolor();
    int x1=x_1;
    int y1=y_1;
    int x2=x_2;
    int y2=y_2;
    if(x_1>=x_2)
    {
        x1=x_2;
        y1=y_2;
        x2=x_1;
        y2=y_1;
    }
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int inc_dec=((y2>=y1)?1:-1);
    if(dx>dy)
    {
        int two_dy=(2*dy);
        int two_dy_dx=(2*(dy-dx));
        int p=((2*dy)-dx);
        int x=x1;
        int y=y1;
        putpixel(x,y,color);
        while(x<x2)
        {
            x++;
            if(p<0)
                p+=two_dy;
            else
            {
                y+=inc_dec;
                p+=two_dy_dx;
            }
            if((count%2)!=0 && line_type==0)
                putpixel(x,y,color);
            else if((count%5)!=4 && line_type==1)
                putpixel(x,y,color);
            else if((count%10)!=8 && (count%10)!=9 && line_type==2)
                putpixel(x,y,color);
            else if((count%20)!=18 && (count%20)!=19 && line_type==3)
                putpixel(x,y,color);
            else if((count%12)!=7 && (count%12)!=8 && (count%12)!=10 &&
                    (count%12)!=11 && line_type==4)
                putpixel(x,y,color);
            count++;
        }
    }
    else
    {
        int two_dx=(2*dx);
        int two_dx_dy=(2*(dx-dy));
        int p=((2*dx)-dy);
        int x=x1;
        int y=y1;
        putpixel(x,y,color);
        while(y!=y2)
        {
            y+=inc_dec;
            if(p<0)
                p+=two_dx;
            else
            {
                x++;
                p+=two_dx_dy;
            }
            if((count%2)!=0 && line_type==0)
                putpixel(x,y,color);
            else if((count%5)!=4 && line_type==1)
                putpixel(x,y,color);
            else if((count%10)!=8 && (count%10)!=9 && line_type==2)
                putpixel(x,y,color);
            else if((count%20)!=18 && (count%20)!=19 && line_type==3)
                putpixel(x,y,color);
            else if((count%12)!=7 && (count%12)!=8 && (count%12)!=10 &&
                    (count%12)!=11 && line_type==4)
                putpixel(x,y,color);
            count++;
        }
    }
}
