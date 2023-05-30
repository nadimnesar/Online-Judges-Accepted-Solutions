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

map < string , int > host;

int process(string temp){
    int len = temp.size();
    vector < int > x;
    for(int i = 0; i < len-1; i++){
        x.pb(abs(temp[i]-temp[i+1]));
    }
    return *min_element(all(x));
}

int main()
{

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    string str;
    while(cin >> str){
        string prestr = str;
        string poststr = str;
        vector < string > x;
        vector < string > y;
        int len = str.size();
        int i = 0;
        while(1){
            i++;
            prev_permutation(prestr.begin(), prestr.end());
            string temp;
            for(int i = 0; i < len; i++){
                temp += prestr[i];
            }
            host[temp];
            if(i == 10) break;
        }
        host[str];
        i = 0;
        while(1){
            i++;
            next_permutation(poststr.begin(), poststr.end());
            string temp;
            for(int i = 0; i < len; i++){
                temp += poststr[i];
            }
            host[temp];
            if(i == 10) break;
        }
        int maxi = 0;
        for (auto it = host.begin(); it != host.end(); ++it){
            it->second = process(it->first);
            maxi = max(maxi, process(it->first));
        }
        for (auto it = host.begin(); it != host.end(); ++it){
            if(it->second == maxi){
                cout << it->first << it->second << endl;
                break;
            }
        }
        host.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
