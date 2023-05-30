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

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    ll hh, mm, ss, i = 0;
    double vv;


    ll second = 0;
    double speed = 0;
    double dis = 0;
    
    string str;
    while(getline(cin, str)){
        i++;
        ll len = str.size();
        if(len > 8 and i == 1){
            stringstream ssmain(str);
            char ch1, ch2;
            ssmain >> hh >> ch1 >> mm >> ch2 >> ss >> vv;
            second = (ll)(hh*3600 + mm*60 + ss);
            speed = (double)(vv/3.6);
        }
        else if(len > 8){
            stringstream ssmain(str);
            char ch1, ch2;
            ssmain >> hh >> ch1 >> mm >> ch2 >> ss >> vv;
            ll totalsecond = (ll)(hh*3600 + mm*60 + ss);
            ll cs = totalsecond - second;
            dis += double((cs*speed)/1000.00);
            second = totalsecond;
            speed = (double)(vv/3.6);
        }
        else{
            stringstream ssmain(str);
            char ch1, ch2;
            ssmain >> hh >> ch1 >> mm >> ch2 >> ss;
            ll totalsecond = (ll)(hh*3600 + mm*60 + ss);
            ll cs = totalsecond - second;
            dis += double((cs*speed)/1000.00);
            cout << str << ' ' << dot(2) << dis << " km" << endl;
            second = totalsecond;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}