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
ll i,j;
using namespace std;

int main()
{
    int n,m,kop=0;
    bool bol = false;
    while(cin >> n >> m and n and m)
    {
        cin.ignore();
        for(i=0; i<n; i++)
        {
            string lol;
            getline(cin,lol);
        }
        string name;
        double compliance = 0;
        double tk_de = DBL_MAX;
        for(j=0; j<m; j++)
        {
            string str;
            getline(cin, str);
            double tk, t;
            cin >> tk >> t;
            cin.ignore();
            for(i = 0; i < t; i++)
            {
                string temp;
                getline(cin, temp);
            }
            double newcompliance = (double)(t/n);
            if((newcompliance > compliance) or (newcompliance == compliance and tk_de > tk))
            {
                name = str;
                compliance = newcompliance;
                tk_de = tk;
            }
        }
        if(bol) cout << endl;
        bol = true;
        cout << "RFP #" << ++kop << endl;
        cout << name << endl;
    }
}