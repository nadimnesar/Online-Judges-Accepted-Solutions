#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define dot(x)              fixed<<setprecision(x)
#define pb                  push_back

int main() {
    ll n;
    while(cin >> n){
        if(n == 0) break;
        vector < ll > arr;
        arr.pb(n);
        ll temp;
        while(cin >> temp){
            if(temp == 0) break;
            arr.pb(temp);
        }

        vector < ll > up;
        vector < ll > down;
        
        bool upbool = false;
        bool downbool = false;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] > arr[i]){
                downbool = true;
                break;
            }
            if(arr[i-1] < arr[i]){
                upbool = true;
                break;
            }
        }

        if(!upbool and !downbool){
            double x = 0;
            cout << "Nr values = " << arr.size() << ":  " << dot(6) << x << ' ' << dot(6) << x << endl;
            continue;
        }
        
        ll cntup = 0;
        ll cntdown = 0;
        for(int i = 1; i < arr.size(); i++){
            if(upbool){
                if(arr[i-1] <= arr[i]) cntup++;
                else{
                    up.pb(cntup);
                    cntup = 0;
                    cntdown++;
                    downbool = true;
                    upbool = false;
                }
            }
            else{
                if(arr[i-1] >= arr[i]) cntdown++;
                else{
                    down.pb(cntdown);
                    cntdown = 0;
                    cntup++;
                    downbool = false;
                    upbool = true;
                }
            }
        }
        if(cntup) up.pb(cntup);
        if(cntdown) down.pb(cntdown);
        
        double avgup = 0;
        double avgdown = 0;
        for(ll i = 0; i < up.size(); i++) avgup += up[i];
        for(ll i = 0; i < down.size(); i++) avgdown += down[i];
        avgup /= up.size();
        avgdown /= down.size();

        if(up.size() == 0) avgup = 0;
        if(down.size() == 0) avgdown = 0;
        cout << "Nr values = " << arr.size() << ":  " << dot(6) << avgup << " " << dot(6) << avgdown << endl;
    }
    return 0;
}
