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

vector < pair < ll , vector < ll > > > host;

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    ll range, num;
    while(cin >> range >> num){
        vector < ll > x(num);
        for(ll i = 0; i < num; i++){
            cin >> x[i];
        }

        ll targetsum = 0;
        ll targetlen = 0;
        for(ll mask = 1; mask < (1 << num); mask++){
            vector < ll > temp;
            ll sum = 0;
            for(ll i = 0; i < num; i++){
                if(mask&(1 << i)){
                    temp.pb(x[i]);
                    sum += x[i];
                }
            }
            ll temptergetsum = targetsum;
            if(sum <= range){
                targetsum = max(targetsum, sum);
                if(temptergetsum != targetsum){
                    targetlen = temp.size();
                }
                host.pb({sum, temp});
            }
            temp.clear();
        }

        ll hostlen = host.size();

        for(int i = 0; i < hostlen; i++){
            if(host[i].first == targetsum and host[i].second.size() == targetlen){
                vector < ll > subnums;
                subnums = host[i].second;
                ll len = subnums.size();
                for(ll i = 0; i < len; i++){
                    cout << subnums[i] << ' ';
                }
                cout << "sum:" << host[i].first << endl;
                break;
            }
        }
        
        host.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
