#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
void Draw(int*,int*,int);
void ClockWiseRotatation(int*,int*,int,float);
void AntiClockWiseRotatation(int*,int*,int,float);

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int ch;


    while(1)
    {
        cout<<"1.Rotation on Clockwise:"<<endl;
        cout<<"2.Rotation on AntiClockwise:"<<endl;
        cout<<"3.Break:"<<endl;
        cout<<"======================"<<endl;
        cin>>ch;
        if(ch==1)
        {
            cleardevice();
            int n, x[100],y[100];

            float angle=0;

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }
            setcolor(YELLOW);
            Draw(x,y,n);
            cout<<"Enter the rotation angle:"<<endl;
            cin>>angle;

            angle=(angle*3.1416)/180;
            getchar();

            ClockWiseRotatation(x,y,n,angle);
            setcolor(WHITE);
            Draw(x,y,n);

            getchar();
        }

        if(ch==2)
        {
            cleardevice();
            int n, x[100],y[100];

            float angle=0;

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }
            setcolor(YELLOW);
            Draw(x,y,n);
            cout<<"Enter the rotation angle:"<<endl;
            cin>>angle;

            angle=(angle*3.1416)/180;
            getchar();

            AntiClockWiseRotatation(x,y,n,angle);
            setcolor(WHITE);
            Draw(x,y,n);

            getchar();
        }

        if(ch==3)
        {
            break;
        }
    }
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


void ClockWiseRotatation(int x[],int y[],int n, float radian)
{
    float t1,t2;
    int xp,yp;
    cout<<" Enter pivot point(x,y):"<<endl;
    cin>>xp>>yp;
    for(int i=0; i<n; i++)
    {
        t1=x[i]-xp;
        t2=y[i]-yp;
        x[i]=xp+floor(t1*cos(radian)-t2*sin(radian));
        y[i]=yp+floor(t1*sin(radian)+t2*cos(radian));
    }
}


void AntiClockWiseRotatation(int x[],int y[],int n, float radian)
{
    float t1,t2;
    int xp,yp;
    cout<<" Enter pivot point(x,y):"<<endl;
    cin>>xp>>yp;
    for(int i=0; i<n; i++)
    {
        t1=x[i]-xp;
        t2=y[i]-yp;
        x[i]=xp+floor(t1*cos(radian)+t2*sin(radian));
        y[i]=yp+floor(-t1*sin(radian)+t2*cos(radian));
    }
}
