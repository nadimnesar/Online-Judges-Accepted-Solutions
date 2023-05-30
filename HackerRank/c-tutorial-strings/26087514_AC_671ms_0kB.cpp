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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << s1.size() << ' ' << s2.size() << endl;
    cout << s1+s2 << endl;
    swap(s1[0], s2[0]);
    cout << s1 << ' ' << s2 << endl;
}
/*ALHAMDULILLAH*/
