#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int Combination(int n, int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}
int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    int i,n;
    float t,x,y,px[10],py[10];

    cout<<"Enter no of points: ";
    cin>>n;

    n = n-1;
    for(i = 0; i<=n; i++)
    {
        cout<<"\nP"<<i<<endl;
        cout<<"x=";
        cin>>px[i];
        cout<<"y=";
        cin>>py[i];
    }


    setcolor(YELLOW);
    for(i=0;i<=n;i++)
    {
        circle(px[i]*200,700+py[i]*-200,5);
        if(i!=n)
        {
            line(px[i]*200,700+py[i]*-200,px[i+1]*200,700+py[i+1]*-200);

        }

    }
    delay(10);
    for(t=0; t<=1; t=t+0.000001)
    {
        x=0;y=0;
        for(i=0;i<=n;i++)
        {
            x = x +(Combination(n,i)*pow(1-t,n-i)*pow(t,i)*px[i]);
            y = y +(Combination(n,i)*pow(1-t,n-i)*pow(t,i)*py[i]);
        }
        putpixel(x*200,700+y*-200,WHITE);
    }
    getchar();
    closegraph();
    return 0;
}

