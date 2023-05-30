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

int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	double hor, lob;
	while(cin >> lob >> hor){
		double Lhor = 1, Llob = 0;
		double Rhor = 0, Rlob = 1;
		bool flag = false;
		while(true){
			double nhor = (Lhor+Rhor);
			double nlob = (Llob+Rlob);
			double n = nlob/nhor;
			if(n == (lob/hor)) break;
			else if(n > (lob/hor)){
				flag = true;
				cout << 'L';
				Rhor = nhor, Rlob = nlob;
			}
			else{
				flag = true;
				cout << 'R';
				Lhor = nhor, Llob = nlob;
			}
		}
		if(flag) cout << endl;
	}
}
