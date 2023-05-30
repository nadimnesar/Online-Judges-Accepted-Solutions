#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)

#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (100000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

pair < double, double > stations[51];
int n;
double dis, tank_size, dis_per_gas, result;

double min_cost;
void BT(int pos, double spend, double at, double tank_status){
	if(tank_status*dis_per_gas >=  (dis-at)){
		min_cost = min(min_cost, spend);
		return;
	}
	if(pos == n) return;
	if((tank_status - ((stations[pos].first-at)/dis_per_gas)) < 0) return;
	tank_status = tank_status - ((stations[pos].first-at)/dis_per_gas);
	at = stations[pos].first;
	if(tank_status <= (tank_size/2.0)) BT(pos+1, spend+200+((tank_size - tank_status)*stations[pos].second), at, tank_size);
	BT(pos+1, spend, at, tank_status);
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int dsn = 0;
    while(cin >> dis){
    	if(dis == -1) break;
    	cin >> tank_size >> dis_per_gas >> result >> n;
    	for(int i = 0; i < n; i++) cin >> stations[i].first >> stations[i].second;
    	min_cost = LLONG_MAX;
    	BT(0, 0, 0, tank_size);
    	cout << "Data Set #" << ++dsn << endl << "minimum cost = $";
    	cout << dot(2) << result + (min_cost/100.00) << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
