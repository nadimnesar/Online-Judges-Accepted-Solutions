#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0) //3.1415926535897932
#define FASTIO          ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define dot(x)          fixed << setprecision(x)

int main() {
    FASTIO;
    int t, win, total = 0;
    cin >> t;
    win = ceil(t/2.0);
    vector < int > x(t);
    for(int i = 0; i < t; i++)
        cin >> x[i];
    sort(all(x));
    for(int i = 0; i < win; i++)
        total += ceil(x[i]/2.0);
    cout << total << endl;
}