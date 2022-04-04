#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
void draw(int*,int*,int);
void ShearOnXAxis(int*,int*,int,int);
void ShearOnYAxis(int*,int*,int,int);

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int ch;

    while(1)
    {
        cout<<"1.Shearing on x-axis:"<<endl;
        cout<<"2.Shearing on y-axis:"<<endl;
        cout<<"3.Break:"<<endl;
        cout<<"======================"<<endl;
        cin>>ch;
        if(ch==1)
        {
            int n, x[100],y[100],shy;

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }
            cout<<"Enter the shearing factor(shy)"<<endl;
            cin>>shy;

            getchar();
            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ShearOnXAxis(x,y,n,shy);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end x-axis

        if(ch==2)
        {
            int n, x[100],y[100],shx;

            cout<<"Enter the no of sides of a polygon/line"<<endl;
            cin>>n;
            cout<<"Enter coordinates:x,y"<<endl;
            for(int i =0; i<n; i++)
            {
                cin>>x[i]>>y[i];

            }
             cout<<"Enter the shearing factor(shx): "<<endl;
            cin>>shx;

            getchar();
            cleardevice();
            setcolor(YELLOW);
            draw(x,y,n);
            ShearOnYAxis(x,y,n,shx);
            setcolor(WHITE);
            draw(x,y,n);

            getchar();
        }///end y-axis


        if(ch==3)
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
void ShearOnXAxis(int x[],int y[],int n,int shx)
{
    for(int i =0; i<n; i++)
    {

        x[i]=x[i]+shx*y[i];


    }
}

void ShearOnYAxis(int x[],int y[],int n,int shy)
{
    for(int i =0; i<n; i++)
    {

        y[i]=x[i]*shy + y[i];

    }
}
