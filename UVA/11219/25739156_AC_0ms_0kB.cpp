#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define MAX             15000
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    int t, cn=0;
    scanf("%d", &t);
    while(t--)
    {
        int d1, d2, m1, m2, y1, y2, y;
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);
        printf("Case #%d: ", ++cn);
        if(y1<y2)
        {
            printf("Invalid birth date\n");
        }
        else if(y1>y2)
        {
            y=y1-y2;
            if(m1>m2)
            {
                if(y>130)
                    printf("Check birth date\n");
                else printf("%d\n", y);
            }
            else if(m1<m2)
            {
                y=y-1;
                if(y>130)
                    printf("Check birth date\n");
                else printf("%d\n", y);
            }
            else
            {
                if(d1>=d2)
                {
                    if(y>130)
                        printf("Check birth date\n");
                    else printf("%d\n", y);
                }
                else
                {
                    y=y-1;
                    if(y>130)
                        printf("Check birth date\n");
                    else printf("%d\n", y);
                }
            }
        }
        else
        {
            if(m1>m2)
                printf("0\n");
            else if(m1<m2)
                printf("Invalid birth date\n");
            else
            {
                if(d1>=d2)
                    printf("0\n");
                else printf("Invalid birth date\n");
            }
        }
    }
}