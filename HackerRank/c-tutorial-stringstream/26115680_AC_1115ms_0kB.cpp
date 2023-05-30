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
    string x;
    getline(cin, x);
    stringstream ss(x);
    int n;
    char ch;
    while(ss >> n >> ch) cout << n << endl;
    reverse(all(x));
    stringstream sk(x);
    ss >> n;
    x = to_string(n);
    cout << x << endl;
}
/*ALHAMDULILLAH*/
