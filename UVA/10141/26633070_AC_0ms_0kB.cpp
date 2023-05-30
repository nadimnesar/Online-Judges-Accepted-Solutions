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

    llu req, proposal, cn = 0;
    bool br = false;
    while(cin >> req >> proposal and req and proposal){
        cin.ignore();
        for(llu i = 0; i < req; i++){
            string str2;
            getline(cin, str2);
        }
        string company = "XXX";
        double compliance = 0;
        double mainprice = DBL_MAX;
        for(llu i = 0; i < proposal; i++){
            string str;
            getline(cin, str);
            double price;
            double met;
            cin >> price >> met;
            cin.ignore();
            for(llu i = 0; i < met; i++){
                string temp;
                getline(cin, temp);
            }
            double newcompliance = (double)(met/req);
            if((newcompliance > compliance) or (newcompliance == compliance and mainprice > price)){
                company = str;
                compliance = newcompliance;
                mainprice = price;
            }
            else continue;
        }
        if(br) cout << endl;
        br = true;
        cout << "RFP #" << ++cn << endl;
        cout << company << endl;
    }


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}