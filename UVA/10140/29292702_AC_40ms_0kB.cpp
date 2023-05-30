#include<bits/stdc++.h>
#include<iomanip>
typedef long long ll;
typedef unsigned long long ul;
#define to_lower(x)  transform(x.begin(), x.end(), x.begin(), ::tolower)
#define to_upper(x)  transform(x.begin(), x.end(), x.begin(), ::toupper)
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define vec vector<ll>
#define f1(x,n) for(i=x;i<n;i++)
#define input  ll n;cin>>n;ll ar[n];for(i=0;i<n;i++)cin>>ar[i];
#define test   ll ttt;cin>>ttt;while(ttt--)
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define faster2 ios_base::sync_with_stdio(0);
#define en '\n'
#define eps 1e-12
#define pb push_back
#define print(v) for(auto u:v)cout<<u<<" ";
#define mem(a,b) memset(a, b, sizeof(a) )
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define MAX              (10000007)
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
ll i,j;
using namespace std;
vector < ll > v;
vector < bool > ifprime(MAX);
void sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    v.pb(2);
    for(ll i = 3; i < MAX; i+=2) if(!ifprime[i]) v.pb(i);
}
void segement_sieve()
{
    sieve();
    ll first,last;
    while(cin>>first>>last)
    {
        ll sz=last-first;
        bool bol[sz];
        mem(bol,true);
        if(first==1||first==0)
            bol[0]=false;
        for(ll i=0; v[i]*v[i]<=last; i++)
        {


            ll prime=v[i],range1,range2;
            range1=prime*prime;
            if(prime*prime<first)
            {
                range1=((first+prime-1)/prime)*prime;
            }
            range2=last;
            for(ll j=range1; j<=range2; j+=prime)
            {
                bol[j-first]=false;
            }
        }
        vec ar;
        for(int i=0; i<=last-first; i++)
        {
            if(bol[i]==true&& i+first!=1)
                ar.pb(i+first);
        }
        ll s1=-1,s2,b1=-1,b2,x=0,y=1000001;
        for(int i=1; i<ar.size(); i++)
        {
            ll dif=ar[i]-ar[i-1];
            if(dif<y)
            {
                y=dif;
                s1=ar[i-1],s2=ar[i];
            }
            if(dif>x)
            {
                x=dif;
                b1=ar[i-1],b2=ar[i];
            }
        }

        if(b1>0&&s1>0)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",s1,s2,b1,b2);
        else
            printf("There are no adjacent primes.\n");
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        Clock;
        Freopen;
    #endif
        segement_sieve();
    #ifndef ONLINE_JUDGE
        Runtime;
    #endif
}
