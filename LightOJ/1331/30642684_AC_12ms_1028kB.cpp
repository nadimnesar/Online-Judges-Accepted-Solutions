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

int main()
{
    fastio;
    int t, cn = 0;
    double r1, r2, r3;
    cin >> t;
    while(t--){
        cin >> r1 >> r2 >> r3;
        double a = r1+r2, c = r1+r3, b = r2+r3;
        double s = (a+b+c)/2.0;
        double totalarea = sqrt(s*(s-a)*(s-b)*(s-c));
        double A, B, C;
        A = acos(((a*a)+(c*c)-(b*b))/(2.0*a*c));
        B = acos(((a*a)+(b*b)-(c*c))/(2.0*a*b));
        C = acos(((c*c)+(b*b)-(a*a))/(2.0*c*b));
        double area = (((A * (r1*r1))/2.0) + ((B *(r2*r2))/2.0) + ((C*(r3*r3))/2.0));
        cout << "Case " << ++cn << ": ";
        cout << dot(10) << totalarea - area << endl;
    }
}
/*ALHAMDULILLAH*/
