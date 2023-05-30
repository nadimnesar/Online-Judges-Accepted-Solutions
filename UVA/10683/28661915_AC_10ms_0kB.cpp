/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0) //3.1415926535897932
#define fastio          ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define dot(x)          fixed << setprecision(x)

int k, d, o;

int main()
{
    fastio;
    string str;
    while(cin >> str)
    {
        int hh = (str[0]-48)*10+(str[1]-48);
        int mm = (str[2]-48)*10+(str[3]-48);
        int ss = (str[4]-48)*10+(str[5]-48);
        int cc = (str[6]-48)*10+(str[7]-48);

        int totalcc = (hh*60*60*100)+(mm*60*100)+(ss*100)+cc;
        printf("%07d\n", ((125*totalcc)/108));
    }
}
/*ALHAMDULILLAH*/
