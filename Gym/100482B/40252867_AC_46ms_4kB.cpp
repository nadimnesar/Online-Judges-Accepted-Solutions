#include "bits/stdc++.h"
using namespace std;

int main() {

    int t, cn = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++cn << ": ";
        double a, b, c, d, e, f, g, h, x;
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> x;

        double area = .5 * abs((( a * d + c * f + e * h + g * b ) - (c * b + e * d + g * f + a * h)));

        printf("%0.2lf\n", x/area);
    }

    return 0;
}