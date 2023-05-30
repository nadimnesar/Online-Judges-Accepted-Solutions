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
#define Log(b, x)        (log(x)/log(b))

int n, ans, total = 0;
vector < int > x;

void process(int i, int sum){
    if(i == n){
        int pile2 = total - sum;
        ans = min(ans, abs(sum-pile2));
        return;
    }
    process(i+1, sum+x[i]);
    process(i+1, sum);
}

int main() {
    
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        total += temp;
        x.pb(temp);
    }
    ans = total;
    process(0, 0);
    cout << ans << endl;
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}