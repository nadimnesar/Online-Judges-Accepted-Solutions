#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FastIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FastIO;
    string str;
    cin >> str;
    ll c=0, d=0, len=str.size();
    for(int i=0; i<len; i++)
    {
        if(str[i]=='1')
            c=0;
        else if(str[i]=='0')
            c++;
        if(c==7) break;
    }
    for(int i=0; i<len; i++)
    {
        if(str[i]=='0')
            d=0;
        if(str[i]=='1')
            d++;
        if(d==7) break;
    }
    if(c==7 || d==7) YES;
    else NO;
}