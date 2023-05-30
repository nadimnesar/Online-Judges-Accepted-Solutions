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
#define MAX             15000
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FASTIO;
    ll n, taxi=0;
    cin >> n;
    vll x(n);
    ll xsize=x.size();
    for(ll i=0; i<xsize; i++)
        cin >> x[i];
    sort(all(x), greater<int>());
    for(ll i=0; i<xsize; i++)
    {
        if(x[i]==4)
            continue;
        if(x[i]==-1)
            break;
        ll dif=4-x[i];
        ll limit=(xsize-1);
        for(ll j=limit; j!=i; j--)
        {
            if(x[j]==-1)
                continue;
            else if(x[j]==dif)
            {
                x[j]=-1;
                break;
            }
            else if(x[j]>dif) break;
            else if(x[j]<dif)
            {
                dif=dif-x[j];
                x[j]=-1;
                continue;
            }
        }
    }
    for(ll i=0; i<xsize; i++)
    {
        if(x[i]>0) taxi++;
    }
    cout << taxi << endl;
}