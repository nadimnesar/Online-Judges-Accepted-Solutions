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
    int t, cn = 0;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector < int > x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        while(m--)
        {
            char c;
            cin >> c;
            if(c == 'P'){
                int y, z;
                cin >> y >> z;
                swap(x[y], x[z]);
            }
            else if(c == 'R'){
                reverse(all(x));
            }
            else if(c == 'D'){
                cin >> k;
                for_each(all(x), [](int &q){ q = q/k; });
            }
            else if(c == 'M'){
                cin >> d;
                for_each(all(x), [](int &q){ q = q*d; });
            }
            else if(c == 'S'){
                cin >> o;
                for_each(all(x), [](int &q){ q = q+o; });
            }
        }
        cout << "Case " << ++cn << ':' << endl;
        for(int i = 0; i < n; i++){
            if(i == n-1) cout << x[i]  << endl;
            else cout << x[i] << ' ';
        }
    }
}
/*ALHAMDULILLAH*/
