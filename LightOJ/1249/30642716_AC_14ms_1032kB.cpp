#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define YES             printf("YES\n")
#define NO              printf("NO\n")
#define PI              acos(-1.0)
#define MAX             1000001
#define MOD             10000007

vector < int > x;
vector < string > y;

int main(){
    int t, cn = 0;
    scanf("%d", &t);
    cin.ignore();
    while(t--){
        int n, a, b, c;
        scanf("%d", &n);
        cin.ignore();
        while(n--){
            string str;
            cin >> str >> a >> b >> c;
            x.pb(a*b*c);
            y.pb(str);
        }

        int maxi = *max_element(all(x));
        int mini = *min_element(all(x));
        int maxindx = max_element(all(x)) - x.begin();
        int minindx = min_element(all(x)) - x.begin();

        printf("Case %d: ", ++cn);
        if(maxi == mini){
            printf("no thief\n");
        }
        else{
            cout << y[maxindx] << " took chocolate from " << y[minindx] << endl;
        }
        x.clear(); y.clear();
    }
}