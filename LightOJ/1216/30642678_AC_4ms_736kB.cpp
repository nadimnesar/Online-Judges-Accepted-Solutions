#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        double r1, r2, h, p, r3, pi=2*acos(0.0), v;
        cin >> r1 >> r2 >> h >> p;
        r1=r1-(((h-p)*(r1-r2))/h);
        v=(pi*p*((r1*r1)+(r1*r2)+(r2*r2)))/3;
        cout << "Case " << j++ << ": " << fixed << setprecision(9) << v << endl;
    }
}