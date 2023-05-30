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

void combination(vector < int > x, vector < int > data, int start, int end, int index){
    if(index == 6){
        for(int j = 0; j < 6; j++){
            if(j == 5) cout << data[j] << endl;
            else cout << data[j] << ' ';
        }
        return;
    }

    for(int i = start; i <= end; i++){
        data[index] = x[i];
        combination(x, data, i+1, end, index+1);
    }
}


int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int n;
    bool br = false;
    while(cin >> n and n){
        if(br) cout << endl;
        br = true;
        vector < int > x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        vector < int > data(6);
        combination(x, data, 0, n-1, 0);
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
