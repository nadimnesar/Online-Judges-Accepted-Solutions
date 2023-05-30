#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (1e7+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

vector < int > primes;
vector < bool > ifprime(MAX);

void sieve(){
    for(int i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(int j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(int i = 3; i < MAX; i+=2) if(!ifprime[i]) primes.pb(i);
}

vector < int > number_of_fact(10000002);

void pera(){
    int ssize = primes.size();
    for(int i = 0; i < ssize; i++){
        int p = primes[i];
        for(int j = p; j < 10000002; j += p){
            int m = j;
            int cnt = 0;
            while(m%p == 0){
                m /= p;
                cnt++;
            }
            number_of_fact[j] += cnt;
        }
    }
}

vector < int > presaver(10000002);

void magic(){
    presaver[0] = 0;
    for(int i = 1; i < 10000002; i++) presaver[i] = presaver[i-1] + number_of_fact[i];
}

int binarysearch(int q){
    int right = 10000001;
    int left = 0;
    int index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if (presaver[mid] == q){
            index = mid;
            break;
        }
        else if(presaver[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

void solve(){
    int cn = 0;
    int n;
    while(scanf("%d", &n) != EOF){
        if(n < 0) break;
        if(n == 0) printf("Case %d: 0!\n", ++cn);
        else{
            int res = binarysearch(n);
            if(res == -1) printf("Case %d: Not possible.\n", ++cn);
            else printf("Case %d: %d!\n", ++cn, res);
        }
    }
}

int main(){

    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sieve();
    pera();
    magic();
    

    // ll t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
       solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}