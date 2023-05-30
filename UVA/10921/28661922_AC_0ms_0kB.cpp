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
#define MAX             1000001
#define MOD             10000007
#define lend            '\n'
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FASTIO;
    string str;
    while(cin >> str)
    {
        ll len=str.size();
        for(int i=0; i<len; i++)
        {
            if(str[i]=='1')
            {
                cout << '1';
                continue;
            }
            else if(str[i]=='0')
            {
                cout << '0';
                continue;
            }
            else if(str[i]=='-')
            {
                cout << '-';
                continue;
            }
            else if(str[i]=='A' || str[i]=='B' || str[i]=='C')
            {
                cout << '2';
                continue;
            }
            else if(str[i]=='D' || str[i]=='E' || str[i]=='F')
            {
                cout << '3';
                continue;
            }
            else if(str[i]=='G' || str[i]=='H' || str[i]=='I')
            {
                cout << '4';
                continue;
            }
            else if(str[i]=='J' || str[i]=='K' || str[i]=='L')
            {
                cout << '5';
                continue;
            }
            else if(str[i]=='M' || str[i]=='N' || str[i]=='O')
            {
                cout << '6';
                continue;
            }
            else if(str[i]=='P' || str[i]=='Q' || str[i]=='R' || str[i]=='S')
            {
                cout << '7';
                continue;
            }
            else if(str[i]=='T' || str[i]=='U' || str[i]=='V')
            {
                cout << '8';
                continue;
            }
            else cout << '9';
        }
        cout << endl;
    }
}
