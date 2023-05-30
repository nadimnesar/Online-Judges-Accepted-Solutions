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

vector < llu > host;

llu decToBinary(llu num)
{
    string bits;
    for (int i = 31; i >= 0; i--) {
        int k = num >> i;
        if (k & 1) bits += '1';
        else bits += '0';
    }
    stringstream ss(bits);
    ss >> num;
    return num;
}

bool process(llu num, llu r){
    llu d = 0;
    while(num){
        if(num%10 == 1){
            d++;
        }
        num /= 10;
    }
    if(d == r) return true;
    else return false;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    for(llu i = 0; i < (1 << 16); i++){
        host.pb(decToBinary(i));
    }

    llu t;
    cin >> t;
    bool br = false;
    while(t--){
        if(br) cout << endl;
        br = true;

        llu len, one;
        cin >> len >> one;

        for(llu i = 1; i < (1 << len); i++){
            if(process(host[i], one)){
                llu z = len - ceil((double)log10(host[i])+0.000001);
                while(z--){
                    cout << '0';
                }
                cout << host[i] << endl;
            }
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
