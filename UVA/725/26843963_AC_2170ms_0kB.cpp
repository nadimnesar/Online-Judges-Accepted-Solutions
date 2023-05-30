/* Bismillahir Rahmanir Rahim
There is no god without Allah*/
#include<bits/stdc++.h>
#include<iomanip>
typedef long long ll;
typedef unsigned long long ul;
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define vec vector<ll>
#define f1(i,n) for(i=1;i<n;i++)
#define test   ll ttt;cin>>ttt;while(ttt--)
long long int i,j;
using namespace std;

int main()
{
    int n;
    bool br = false;
    while(cin>>n)
    {
        if(n==0)
            break;

        if(br) cout << endl;
        br = true;

        int c,x,y;
        int ar[10]= {0};
        bool flag=false;
        for(i=1234; i<=98765; i++)
        {
            int c,x,y;
            x=n*i;
            y=i;
            string s2,s1=to_string(x);
            s2=to_string(y);
            if(s1.size()>5)
                continue;
            int H[10]= {0};
            for(j=0; j<s1.size(); j++)
            {
                int l=s1[j]-'0';
                H[l]++;
            }
            for(j=0; j<s2.size(); j++)
            {
                int l=s2[j]-'0';
                H[l]++;

            }
            int t=0;
            for(j=1; j<=9; j++)
            {
                if(H[j]==1)
                    t++;
            }
            if(t==9)
            {
                if(s2.size()==4)
                {
                    printf("%d / 0%d = %d\n",x,y,n);
                }
                else
                    printf("%d / %d = %d\n",x,y,n);
                flag=true;
            }

        }
        if(flag==false) printf("There are no solutions for %d.\n",n);
    }

}