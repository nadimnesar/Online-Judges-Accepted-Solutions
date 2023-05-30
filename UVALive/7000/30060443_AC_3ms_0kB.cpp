#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define max(a,b)   (a>b?a:b)
#define min(a,b)   (a<b?a:b)
#define swap(a,b)  (a=a+b,b=a-b,a=a-b)
#define maxn 2017
#define N 100000000
#define INF 0x3f3f3f3f
#define mod 1001113
#define e  2.718281828459045
#define eps 1.0e18
#define PI acos(-1)
#define lowbit(x) (x&(-x))
#define read(x) scanf("%d",&x)
#define put(x) prllf("%d\n",x)
#define memset(x,y) memset(x,y,sizeof(x))
#define Debug(x) cout<<x<<" "<<endl
#define lson i << 1,l,m
#define rson i << 1 | 1,m + 1,r
#define ll long long
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
//const int maxn=;
using namespace std;
 
 
int n,m,l;
int b[100007];
int s[100007];
struct Node
{
    int x;
    int y;
}a[100007];
int cmp(Node a,Node b)
{
    if(a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l;
        for(int i=0;i<m;i++)
            cin>>a[i].x>>a[i].y;
        sort(a,a+m,cmp);
        for(int i=0;i<n;i++)
            b[i]=i;
        for(int i=0;i<m;i++)
        {
            int p=a[i].x,q=a[i].x+1;
            if(i<m-1&&a[i].x==a[i+1].x||q>=n)
                continue;
            swap(b[p],b[q]);
        }
        for(int i=0;i<n;i++)
        {
            s[b[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            cout<<s[i]<<endl;
        }
    }
    return 0;
}