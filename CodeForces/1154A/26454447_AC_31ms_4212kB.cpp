/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long int
#define llu       long long unsigned int
#define pb        push_back
#define ins       insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+1)
#define MOD       (int)(1e7+1)

int main(){


    long long unsigned int y1, y2, y3, y4, x1, x2, x3, x4, a, b, c, n1, n2, n3;
    cin >> y1 >> y2 >> y3 >> y4;
    if(x1=y1, x2=y2, x3=y3, x4=y4)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y1, x2=y2, x3=y4, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y1, x2=y3, x3=y2, x4=y4)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y1, x2=y3, x3=y4, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y1, x2=y4, x3=y2, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y1, x2=y2, x3=y3, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y1, x3=y3, x4=y4)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y1, x3=y4, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y3, x3=y2, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y3, x3=y1, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y4, x3=y3, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y2, x2=y4, x3=y1, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y1, x3=y2, x4=y4)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y1, x3=y4, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y2, x3=y1, x4=y4)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y2, x3=y4, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y4, x3=y2, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y3, x2=y4, x3=y1, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y1, x3=y3, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y1, x3=y2, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y2, x3=y3, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y2, x3=y1, x4=y3)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y3, x3=y2, x4=y1)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    if(x1=y4, x2=y3, x3=y1, x4=y2)
    {
        a=(x4-x3);
        b=(x1+x3-x4);
        c=(x4-x1);
        if((a+b)==x1 && (a+c)==x2 && (b+c)==x3 && (a+b+c)==x4)
        {
            n1=(x4-x3);
            n2=(x1+x3-x4);
            n3=(x4-x1);
        }
    }
    cout << n1 << " " << n2 << " " << n3 << endl;

    /*#ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif*/

}
