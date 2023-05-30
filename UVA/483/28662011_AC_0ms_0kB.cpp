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
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    string str;
    while(getline(cin, str))
    {
        vector <char> x;
        x.pb(' ');
        ll l1=str.size();
        for(ll i=0; i<l1; i++)
        {
            x.pb(str[i]);
        }
        x.pb(' ');
        ll l2=x.size(), j;
        for(ll i=1; i<l2; i++)
        {
            if(x[i]==' ')
            {
                j=i-1;
                while(x[j]!=' ')
                {
                    printf("%c", x[j]);
                    j--;
                }
                if(i!=l2-1) printf(" ");
            }
        }
        printf("\n");
    }
}