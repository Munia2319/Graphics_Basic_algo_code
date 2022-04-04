#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
void Draw(int*,int*,int);
void Scale(int*,int*,int,int,int);;

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int n, x[100],y[100];
    float Sx, Sy;
    cout<<"Enter the no of sides of a polygon/line"<<endl;
    cin>>n;
    cout<<"Enter coordinates:(x,y)"<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>x[i]>>y[i];

    }
    cout<<"Enter the scale factors (Sx, Sy)"<<endl;
    cin>>Sx>>Sy;
    getchar();


    setcolor(YELLOW);
    Draw(x,y,n);
    Scale(x,y,n,Sx,Sy);
    setcolor(WHITE);
    Draw(x,y,n);
    getchar();




    return 0;
}

void Draw(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
}
void Scale(int x[],int y[],int n,int Sx, int Sy)
{
    for(int i =0; i<n; i++)
    {
        x[i] = x[2] + (int)( (float)(x[i]-x[2])*Sx );
        y[i] = y[2] + (int)( (float)(y[i]-y[2])*Sy );


    }
}
