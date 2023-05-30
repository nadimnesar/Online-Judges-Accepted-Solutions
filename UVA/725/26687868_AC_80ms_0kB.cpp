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

vector < int > host;

bool nozero(int num){
    int zero = 0;
    while(num){
        if(num%10 == 0){
            zero++;
        }
        num = num/10;
    }
    if(zero == 0) return true;
    else return false;
}

bool process(int num){
    set < int > set;
    int d = 0;
    int zero = 0;
    while(num){
        d++;
        set.inst(num%10);
        if(num%10 == 0){
            zero++;
        }
        num = num/10;
    }
    if(set.size() == 5) return true;
    else if(set.size() == 4 and d == 4){
        if(zero == 0) return true;
        else return false;
    }
    else return false;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    for(int i = 1000; i <= 99999; i++){
        if(process(i)){
            host.pb(i);
        }
    }

    int n;
    int size = host.size();
    bool br = false;
    while(cin >> n and n){
        if(br) cout << endl;
        br = true;
        bool noans = true;
        for(int i = 0; i < size; i++){
            if(host[i]%n == 0){
                bool comon = false;
                string str1 = to_string(host[i]);
                string str2 = to_string(host[i]/n);
                for(int i = 0; i < str1.size(); i++){
                    for(int j = 0; j < str2.size(); j++){
                        if(str1[i] == str2[j]){
                            comon = true;
                            break;
                        }
                    }
                }
                if(comon == false and process(host[i]/n)){
                    int left = ceil(double(log10(host[i])));
                    int right = ceil(double(log10(host[i]/n)));
                    if(left == 4 and right == 5){
                        if(nozero(host[i]/n)){
                            noans = false;
                            cout << 0 << host[i] << " / " << host[i]/n << " = " << n << endl;
                        }
                    }
                    else if(left == 5 and right == 4){
                        if(nozero(host[i])){
                            noans = false;
                            cout << host[i] << " / " << 0 << host[i]/n << " = " << n << endl;
                        }
                    }
                    else if(left == 5 and right == 5){
                        noans = false;
                        cout << host[i] << " / " << host[i]/n << " = " << n << endl;
                    }
                }
            }
        }
        if(noans) cout << "There are no solutions for " << n << '.' << endl;
    }


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
