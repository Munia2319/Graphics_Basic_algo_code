#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
void draw(int*,int*,int);
void ReflectionOnXAxis(int*,int*,int);
void ReflectionOnYAxis(int*,int*,int);
void ReflectionOnOrigin(int*,int*,int);
void ReflectionOnLine(int*,int*,int);

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int ch;

    while(1)
    {
        cout<<"1.Reflection on x-axis:"<<endl;
        cout<<"2.Reflection on y-axis:"<<endl;
        cout<<"3.Reflection on Origin:"<<endl;
        cout<<"4.Reflection on line(y=x):"<<endl;
        cout<<"5.Break:"<<endl;
        cout<<"======================"<<endl;

        cin>>ch;

        if(ch==1)
        {
            int n, x[100],y[100];

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }

            getchar();

            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ReflectionOnXAxis(x,y,n);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end x-axis

        if(ch==2)
        {
            int n, x[100],y[100];

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }

            getchar();
            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ReflectionOnYAxis(x,y,n);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end y-axis

        if(ch==3)
        {
            int n, x[100],y[100];

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }
            getchar();
            //
            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ReflectionOnOrigin(x,y,n);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end origin

        if(ch==4)
        {
            int n, x[100],y[100];

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }

            getchar();

            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ReflectionOnLine(x,y,n);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end Line

        if(ch==5)
        {
            break;
        }
    }
    ///end while
    getchar();
    closegraph();

    return 0;
}

void draw(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {
        line(x[i],y[i],x[ (i+1)%n ], y[ (i+1)%n ]);
    }
}
void ReflectionOnXAxis(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        y[i]=-y[i]+200;

    }
}

void ReflectionOnYAxis(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        x[i]=-x[i]+200;

    }
}
void ReflectionOnOrigin(int x[],int y[],int n)
{
    for(int i =0; i<n; i++)
    {

        x[i]=-x[i]+200;
        y[i]=-y[i]+200;

    }
}

void ReflectionOnLine(int x[],int y[],int n)
{
    int tem[100];
    for(int i =0; i<n; i++)
    {

        //x[i]=y[i];
        tem[i]=x[i];

    }
    for(int i =0; i<n; i++)
    {

        x[i]=y[i];
        y[i]=tem[i];

    }
}


