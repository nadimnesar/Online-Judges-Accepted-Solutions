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
 
#define MAX              (101)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){
 
	//fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t, cn = 0;
    scanf("%d", &t);
    while(t--){
    	int n;
    	scanf("%d", &n);
    	int maxi = 0, cnt = 0, at = 0;
    	vector < int > data;
    	for(int i = 0; i < n; i++){
    		int temp;
    		scanf("%d", &temp);
    		data.pb(temp);
    		if((temp-at) == maxi){
    			cnt++;
    		}
    		else if((temp-at) > maxi){
    			maxi = (temp-at);
    			cnt = 1;
    		}
    		at = temp;
    	}
    	if(cnt > 1) printf("Case %d: %d\n", ++cn, maxi+1);
    	else{
    		int k = maxi;
    		at = 0; cnt = 0;
    		for(int i = 0; i < n; i++){
    			if(k == 0) break;
    			if((data[i]-at) < k){
    				at = data[i];
    				cnt++;
    			}
    			else{
    				k--;
    				at = data[i];
    				cnt++;
    			} 
    		}
    		if(cnt == n) printf("Case %d: %d\n", ++cn, maxi);
    		else printf("Case %d: %d\n", ++cn, maxi+1);
    	}
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
