/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        double ab, ac, bc, ade_bdec, ad, ae, de, ce, bd;
        cin >> ab >> ac >> bc >> ade_bdec;
        double high = ab, low = 0;
        while(high >= low){
            ad = (low+high)/2.0;
            ae = (ad/ab)*ac;
            de = (ad/ab)*bc;
            bd = ab-ad;
            ce = ac-ae;
            double s1 = (ad+de+ae)/2.0;
            double ade = sqrt(s1*(s1-ad)*(s1-de)*(s1-ae));
            double bmplusnc = (bc-de);
            double s2 = (bd+bmplusnc+ce)/2.0;
            double h = (sqrt(s2*(s2-bd)*(s2-bmplusnc)*(s2-ce))/bmplusnc)*2.0;
            double bdec = ((bc+de)/2.0)*h;
            if(abs((ade/bdec)-ade_bdec) <= EPS){
                break;
            }
            else if((ade/bdec) > ade_bdec) high = ad;
            else low = ad;
        }
        cout << "Case " << ++cn << ": ";
        cout << dot(10) << ad << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}