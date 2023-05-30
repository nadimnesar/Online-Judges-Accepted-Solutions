/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert

#define all(x)           x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)

#define PI               acos(-1.0) //3.1415926535897932
#define Log(b, x)        (log(x)/log(b))

vector < string > y;

string process(vector < string > y)
{
    ll total = y.size();
    ll size = y[0].size();
    string str;
    str += '0';
    str += y[0];
    str += '-';
    bool notequal = false;
    for(ll i = 0; i < size; i++)
    {
        if(y[0][i] != y[total-1][i])
        {
            notequal = true;
        }
        if(notequal) str += y[total-1][i];
    }
    return str;
}

int main()
{

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    ll n, cn = 0;
    while(cin >> n and n)
    {
        if(n == 1)
        {
            cout << "Case " << ++cn << ':' << endl;
            ll temp;
            cin >> temp;
            cout << '0';
            cout << temp << endl;
        }
        else if(n == 2)
        {
            cout << "Case " << ++cn << ':' << endl;
            ll temp1, temp2;
            cin >> temp1;
            cin >> temp2;
            if(abs(temp1-temp2) == 1)
            {
                y.pb(to_string(temp1));
                y.pb(to_string(temp2));
                string compact = process(y);
                cout << compact << endl;
                y.clear();
            }
            else
            {
                cout << '0';
                cout << temp1 << endl;
                cout << '0';
                cout << temp2 << endl;
            }
        }
        else
        {
            cout << "Case " << ++cn << ':' << endl;
            vector < ll > x(n);
            for(ll i = 0; i < n; i++)
            {
                cin >> x[i];
            }
            if(x[1]-x[0] == 1)
            {
                y.pb(to_string(x[0]));
            }
            else
            {
                cout << '0';
                cout << x[0] << endl;
            }

            for(ll i = 1; i < n-1; i++)
            {
                ll up = 0, down = 0;
                if(abs(x[i] - x[i+1]) == 1)
                {
                    down++;
                }
                if(abs(x[i] - x[i-1]) == 1)
                {
                    up++;
                }
                if(down == 1 and up == 1)
                {
                    y.pb(to_string(x[i]));
                }
                else if(up == 0 and down == 1)
                {
                    y.pb(to_string(x[i]));
                }
                else if(up == 1 and down == 0)
                {
                    y.pb(to_string(x[i]));
                    string compact = process(y);
                    cout << compact << endl;
                    y.clear();
                }
                else
                {
                    cout << '0';
                    cout << x[i] << endl;
                }
            }
            if(x[n-1]-x[n-2] == 1)
            {
                y.pb(to_string(x[n-1]));
                string compact = process(y);
                cout << compact << endl;
                y.clear();
            }
            else
            {
                cout << '0';
                cout << x[n-1] << endl;
            }
        }
        cout << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
