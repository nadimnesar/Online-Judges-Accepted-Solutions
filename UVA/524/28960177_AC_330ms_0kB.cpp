#include<bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))


bool prime(int n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        for(llu i = 3; i*i <= n; i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
    else return false;
}

int n;

void BT(vector < int > data, vector < bool > checker, int index){
	/*for(int i = 0; i < data.size(); i++){
		cout << data[i] << ' ';
	}
	cout << endl;*/

	if(data.size() == n and prime(data[0]+data[n-1])){
		for(int i = 0; i < n; i++){
			if(i == n-1) cout << data[i] << endl;
			else cout << data[i] << ' ';
		}
		return;
	}
	for(int i = 2; i <= n; i++){
		if(checker[i] == false and prime(i+data[data.size()-1])){
			data.pb(i);
			checker[i] = true;
			BT(data, checker, index+1);
			checker[i] = false;
			data.pop_back();
		}
	}
}


int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	int t = 0;
	bool br = false;
	while (cin >> n){
		if(br) cout << endl;
		br = true; 
		cout << "Case " << ++t << ":" << endl;
		vector < bool > checker(18, false);
		vector < int > data;
		data.pb(1);
		checker[1] = true;
		BT(data, checker, 1);
	}
}