/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define ins       insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+1)
#define MOD       (int)(1e7+1)

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int n, ans = 0;
    cin >> n;
    if(n == 2){
        for(int a = 0; a <= 9; a++){
            for(int b = 0; b <= 9; b++){
                if(a == b) ans++;
            }
        }
    }
    else if(n == 4){
        for(int a = 0; a <= 9; a++){
            for(int b = 0; b <= 9; b++){
                for(int c = 0; c <= 9; c++){
                    for(int d = 0; d <= 9; d++){
                        if(a+b == c+d) ans++;
                    }
                }
            }
        }
    }
    else if(n == 6){
        for(int a = 0; a <= 9; a++){
            for(int b = 0; b <= 9; b++){
                for(int c = 0; c <= 9; c++){
                    for(int d = 0; d <= 9; d++){
                        for(int e = 0; e <= 9; e++){
                            for(int f = 0; f <= 9; f++){
                                if(a+b+c == d+e+f) ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n == 8){
        for(int a = 0; a <= 9; a++){
            for(int b = 0; b <= 9; b++){
                for(int c = 0; c <= 9; c++){
                    for(int d = 0; d <= 9; d++){
                        for(int e = 0; e <= 9; e++){
                            for(int f = 0; f <= 9; f++){
                                for(int g = 0; g <= 9; g++){
                                    for(int h = 0; h <= 9; h++){
                                        if(a+b+c+d == e+f+g+h) ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}