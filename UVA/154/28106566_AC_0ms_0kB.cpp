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

vector < vector < string > > dataset;

int main(){
 
	fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    string str;
    while(getline(cin, str)){
    	if(str[0] == '#') break;
    	if(str[0] == 'e'){
    		int minchange = INT_MAX, num;
    		int datasetsize = dataset.size();
    		for(int i = 0; i < datasetsize; i++){
    			int sumofchanges = 0;
    			for(int j = 0; j < datasetsize; j++){
    				for(int k = 0; k < 5; k++){
    					if(dataset[i][k] != dataset[j][k]) sumofchanges++;
    				}
    			}
    			if(sumofchanges < minchange){
    				minchange = sumofchanges;
    				num = i+1;
    			}
    		}
    		cout << num << endl;
    		dataset.clear();
    		continue;
    	}
    	vector < string > data;
    	string temp;
    	for(int i = 0; str[i]; i++){
    		if(str[i] == ','){
    			data.pb(temp);
    			temp.clear();
    			continue;
    		}
    		temp += str[i];
    	}
    	data.pb(temp);
    	sort(full(data));
    	dataset.pb(data);
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}