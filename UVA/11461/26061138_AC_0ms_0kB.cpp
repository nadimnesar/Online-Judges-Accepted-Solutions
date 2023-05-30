/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0)

vector < int > sqnum;

int main()
{
    for(int i = 1; i <= 316; i++) sqnum.pb(i*i);
    int len = sqnum.size();
    while(1)
    {
        int a, b;
        scanf("%d %d" , &a, &b);
        if(a == 0 || b == 0) break;
        if(a > b) swap(a, b);
        int counter = 0;
        for(int i = 0; i <= len; i++)
        {
            if(sqnum[i] >= a && sqnum[i] <= b){
                counter++;
            }
        }
        printf("%d\n", counter);
    }
}
/*ALHAMDULILLAH*/