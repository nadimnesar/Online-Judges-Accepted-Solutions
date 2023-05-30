#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector< int >
#define vll             vector< ll >
#define vc              vector< char >
#define vs              vector< string >
#define pb              push_back
#define all(v)          v.begin(), v.end()
#define PI              acos(-1.0)  // 3.1415926535897932
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll len=s.length();
        if(len==1)
        {
            ll n=s[0]-'0';
            if(n%8==0)
                YES;
            else NO;
        }
        else if(len==2)
        {
            ll n1=10*(s[0]-'0')+(s[1]-'0');
            ll n2=10*(s[1]-'0')+(s[0]-'0');
            if(n1%8==0 || n2%8==0)
                YES;
            else NO;
        }
        else
        {
            ll i, j, k, temp=0;
            for(int i=0; i<len; i++)
            {
                for(int j=0; j<len; j++)
                {
                    for(int k=0; k<len; k++)
                    {
                        if(i!=j && i!=k && j!=k)
                        {
                            ll n=100*(s[i]-'0')+10*(s[j]-'0')+(s[k]-'0');
                            if(n%8==0)
                            {
                                temp=1;
                                break;
                            }
                            else continue;
                        }
                    }
                }
            }
            if(temp==1)
                YES;
            else NO;
        }
    }
}