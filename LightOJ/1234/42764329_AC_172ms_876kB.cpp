#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprevcision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))    

#define EPS              (1e-7)
#define MAX              (1e4+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

/*vector < int > result;
unordered < int, double > result;

void solve(){
    int t, n;
    scanf("%d", &t);
    int maxi = 0;
    for(int i = 0; i < t; i++){
        scanf("%d", &n);

        testcase.pb(n);
        result.insert(mp(n, 0.00));

        if(arr[i].num >= maxi) maxi = arr[i].num;
    }

    sort(arr, arr+t, cmp1);

    double x = 0.00;
    for(int i = 1; i <= maxi; i++){
        x += (1.00/(double)i);

        int index = binarysearch(i);
        if(index == -1) continue;

        while(arr[index].num == i){
            arr[index].res = x;
            index++;
        }

    }

    sort(arr, arr+t, cmp2);

    for(int i = 0; i < t; i++){
        printf("Case %d: ", arr[i].testcase);
        printf("%.8lf\n", arr[i].res);
    }
}*/

double result[10001];
vector < pair < int, int > > dp;

int main(){
    int t, n, maxi = 0;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d", &n);

        dp.pb(mp(n, i));

        if(n >= maxi) maxi = n;
    }
    sort(full(dp));

    int j = 0;
    double temp = 0.00;
    for(int i = 1; i <= maxi; i++){
        temp += (1.00/(double)i);
        while(dp[j].first == i){
            result[dp[j].second] = temp;
            j++;
        }
    }

    for(int i = 1; i <= t; i++){
        printf("Case %d: ", i);
        printf("%.8lf\n", result[i]);
    }
}