#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string temp;
    vector < string > nums;
    for(int i = 0; i < n; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> temp;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; temp[j]; j++){
            if(nums[i][j] != temp[j]) cnt++;
        }
        if(cnt <= 1) cout << nums[i] << endl;
    }
}

int main(){
    int t, cn = 0; cin >> t;
    while(t--){
        cout << "Case " << ++cn << ":" << endl;
        solve();
    }
}