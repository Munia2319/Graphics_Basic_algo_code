#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void Draw(int*,int*,int);

int main()
{
    int i,gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int n, xw[100],yw[100],xwmin,xwmax,ywmin,ywmax,xvmin,yvmin,xvmax,yvmax;
    float Sx, Sy;
    cout<<"Enter window coordinates(xmin,ymin,xmax,ymax): ";
    cin>>xwmin>>ywmin>>xwmax>>ywmax;
    getchar();
    rectangle(xwmin,ywmin,xwmax,ywmax);
    getchar();

    cout<<"Enter the no of sides of a polygon/line"<<endl;
    cin>>n;
    cout<<"Enter coordinates:x,y"<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>xw[i]>>yw[i];
        if( !((xw[i]>xwmin && xw[i]<xwmax) && (yw[i]>ywmin && yw[i]<ywmax) ))
        {
            cout<<" Values must be in window range !"<<endl;
            break;
        }



    }
    Draw(xw,yw,n);
    cout<<"Enter View port coordinates(xvmin,yvmin,xvmax,yvmax): ";
    cin>>xvmin>>yvmin>>xvmax>>yvmax;
    getchar();
    rectangle(xvmin,yvmin,xvmax,yvmax);
    getchar();
    Draw(xw,yw,n);
    Sx = ((float)(xvmax)-(float)(xvmin))/((float)(xwmax)-(float)(xwmin));
    Sy = ((float)(yvmax)-(float)(yvmin))/((float)(ywmax)-(float)(ywmin));
    cout<<Sx<<" "<<Sy<<endl;

    int vx[100],vy[100];
    for(int i =0; i<n; i++)
    {
        vx[i]= (float)xvmin + Sx*((float)xw[i]-(float)xwmin);
        vy[i]= (float)yvmin + Sy*((float)yw[i]-(float)ywmin);
    }
    Draw(vx,vy,n);

    getchar();
    closegraph();
    return 0;

}
void Draw(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
}

