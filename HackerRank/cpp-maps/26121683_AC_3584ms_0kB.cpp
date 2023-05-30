/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0)
int main()
{
    int n;
    cin >> n;
    map < string, int > x;
    while(n--)
    {
        int q, m;
        string str;
        cin >> q;
        cin.ignore();
        if(q == 1)
        {
            cin >> str >> m;
            x[str] += m;
        }
        else if(q == 2)
        {
            cin >> str;
            x.erase(str);
        }
        else
        {
            cin >> str;
            cout << x[str] << endl;
        }
    }
}
/*ALHAMDULILLAH*/
