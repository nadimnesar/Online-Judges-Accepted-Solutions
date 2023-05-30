#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int atR, atC;
int R, C;
int b;
vector < pair < int, int > > data;
vector < int > ans;

void distance(){
	int tempans = 0;
	for(int i = 0; i < b; i++){
    	int x, y;
    	x = data[i].first;
    	y = data[i].second;
    	tempans += abs(atR - x);
    	tempans += abs(atC - y);
    	atR = x;
    	atC = y;
    }
    tempans += abs(atR - R);
    tempans += abs(atC - C);
    ans.pb(tempans);
    atR = R;
    atC = C;
}

void allpermutations(int start, int end){
    if(start == end){
    	distance();
        return;
    }
    for(ll i = start; i <= end; i++){
        swap(data[i], data[start]);
        allpermutations(start+1, end);
        swap(data[i], data[start]);
    }
}

int main(){
 
	fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--){
    	int n, m;
    	cin >> n >> m;
    	cin >> atR >> atC;
    	R = atR, C = atC;
    	cin >> b;
    	for(int i = 0; i < b; i++){
    		int x, y;
    		cin >> x >> y;
    		data.pb(mp(x,y));
    	}
    	allpermutations(0, b-1);
    	cout << "The shortest path has length " << *min_element(full(ans)) << endl;
    	ans.clear();
    	data.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}