#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        int ax, ay, bx, by, cx, cy, dx, dy, area;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        dx=ax-(bx-cx);
        dy=(cy-by)+ay;
        area=0.5*(((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)));
        cout << "Case " << j++ << ": " << dx << ' ' << dy << ' ' << (abs(area)) << endl;
    }
}