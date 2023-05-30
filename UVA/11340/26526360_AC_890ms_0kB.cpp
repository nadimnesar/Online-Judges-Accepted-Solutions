/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long int
#define llu       long long unsigned int
#define pb        push_back
#define inst      insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+1)
#define MOD       (int)(1e7+1)

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    int t;
    cin >> t;
    while(t--){
        int k, taka = 0;
        cin >> k;
        cin.ignore();
        map < char , int > x;
        while(k--){
            int tmp;
            char ch;
            cin >> ch >> tmp;
            cin.ignore();
            x.inst({ch, tmp});
        }
        int s;
        cin >> s;
        cin.ignore();
        while(s--){
            string str;
            getline(cin, str);
            int len = str.size();
            for(int i = 0; i < len; i++){
                for (auto it = x.begin(); it != x.end(); ++it){
                    if(str[i] == it->first){
                        taka += it->second;
                        break;
                    }
                } 
            }
        }
        cout << dot(2) << taka/100.00 << '$' << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}