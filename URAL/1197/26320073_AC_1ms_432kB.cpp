/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define eps       1e-9
#define MAX       100000
#define PI        acos(-1.0) //3.1415926535897932
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string str;
        cin >> str;
        int r = (str[1]-48), c = (str[0]-'a')+1, cn = 0, vr, vc;
        int limit = 1;
        while(1){
            if(limit == 1){
                vr = r+1;
                vc = c+2;
            }
            else if(limit == 2){
                vr = r-1;
                vc = c+2;
            }
            else if(limit == 3){
                vr = r+2;
                vc = c+1;
            }
            else if(limit == 4){
                vr = r+2;
                vc = c-1;
            }
            else if(limit == 5){
                vr = r-2;
                vc = c+1;
            }
            else if(limit == 6){
                vr = r-2;
                vc = c-1;
            }
            else if(limit == 7){
                vr = r+1;
                vc = c-2;
            }
            else if(limit == 8){
                vr = r-1;
                vc = c-2;
            }
            if((vr >= 1 && vr <= 8) && (vc >= 1 && vc <= 8)){
                cn++;
            }
            limit++;
            if(limit == 9) break;
        }
        cout << cn << endl;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}