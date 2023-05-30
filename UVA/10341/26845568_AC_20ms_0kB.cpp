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
#define LOG(b, x)        (log(x)/log(b))
#define EPS              (1e-7)

double p, q, r, s, t, u;

double f(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    while(cin >> p >> q >> r >> s >> t >> u){
        double low = 0;
        double high = 1;
        bool found = false;
        while(low < high){
            double mid = (high+low)/2.0;
            if(abs(f(mid)) <= 0.00000001){
                cout << dot(4) << mid << endl;
                found = true;
                break;
            }
            else if(f(mid) < 0) high = mid;
            else low = mid;
        }
        if(!found) cout << "No solution" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}