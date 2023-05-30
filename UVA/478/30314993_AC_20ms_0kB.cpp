#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout << "!***!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

typedef struct node{
    string id;
    double rx1, ry1, rx2, ry2;
    double cx, cy, cr;
    double tx1, ty1, tx2, ty2, tx3, ty3;
} node;

double dis(double x1, double y1, double x2, double y2){
    double x = x2 - x1, y = y2 - y1;
    return sqrt((x * x) + (y * y));
}

node shapes[11];

void solve(){
    int n = 0;
    string type;
    while(cin >> type){
        if(type == "*") break;
        if(type == "r"){
            cin >> shapes[n].rx1 >> shapes[n].ry1 >> shapes[n].rx2 >> shapes[n].ry2;
            shapes[n++].id = type;
        }
        else if(type == "c"){
            cin >> shapes[n].cx >> shapes[n].cy >> shapes[n].cr;
            shapes[n++].id = type;
        }
        else{
            cin >> shapes[n].tx1 >> shapes[n].ty1 >> shapes[n].tx2 >> shapes[n].ty2 >> shapes[n].tx3 >> shapes[n].ty3;
            shapes[n++].id = type;
        }
    }
    int j = 1;
    double x, y;
    while(cin >> x >> y){
        if(x == 9999.9 and y == 9999.9) break;
        bool found = false;
        for(int i = 0; i < n; i++){
            if(shapes[i].id == "r"){
                bool in = true;
                if(x <= shapes[i].rx1 or y >= shapes[i].ry1) in = false;
                if(x >= shapes[i].rx2 or y <= shapes[i].ry2) in = false;
                if(in){
                    found = true;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
            if(shapes[i].id == "c"){
                bool in = true;
                double ptoxy = dis(shapes[i].cx, shapes[i].cy, x, y);
                if(ptoxy > shapes[i].cr) in = false;
                if(abs(shapes[i].cr - ptoxy) <= EPS) in = false;
                if(in){
                    found = true;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
            if(shapes[i].id == "t"){
                bool in = true;
                double p1x = shapes[i].tx1, p1y = shapes[i].ty1;
                double p2x = shapes[i].tx2, p2y = shapes[i].ty2;
                double p3x = shapes[i].tx3, p3y = shapes[i].ty3;

                double p1_p2 = dis(p1x, p1y, p2x, p2y);
                double p1_p3 = dis(p1x, p1y, p3x, p3y);
                double p2_p3 = dis(p2x, p2y, p3x, p3y);

                double p1_xy = dis(p1x, p1y, x, y);
                double p2_xy = dis(p2x, p2y, x, y);
                double p3_xy = dis(p3x, p3y, x, y);

                double mainangle, subangle;
                //work with p1 using law of cos
                mainangle = (acos(((p1_p2*p1_p2)+(p1_p3*p1_p3)-(p2_p3*p2_p3))/(2.0*p1_p2*p1_p3))*180)/PI; 
                subangle = (acos(((p1_p2*p1_p2)+(p1_xy*p1_xy)-(p2_xy*p2_xy))/(2.0*p1_p2*p1_xy))*180)/PI;
                subangle += (acos(((p1_xy*p1_xy)+(p1_p3*p1_p3)-(p3_xy*p3_xy))/(2.0*p1_xy*p1_p3))*180)/PI;
                if(abs(mainangle - subangle) > EPS) in = false;
                
                //work with p2 using law of cos
                mainangle = (acos(((p1_p2*p1_p2)+(p2_p3*p2_p3)-(p1_p3*p1_p3))/(2.0*p1_p2*p2_p3))*180)/PI; 
                subangle = (acos(((p1_p2*p1_p2)+(p2_xy*p2_xy)-(p1_xy*p1_xy))/(2.0*p1_p2*p2_xy))*180)/PI;
                subangle += (acos(((p2_xy*p2_xy)+(p2_p3*p2_p3)-(p3_xy*p3_xy))/(2.0*p2_xy*p2_p3))*180)/PI;
                if(abs(mainangle - subangle) > EPS) in = false;

                //work with p3 using law of cos
                mainangle = (acos(((p1_p3*p1_p3)+(p2_p3*p2_p3)-(p1_p2*p1_p2))/(2.0*p1_p3*p2_p3))*180)/PI; 
                subangle = (acos(((p1_p3*p1_p3)+(p3_xy*p3_xy)-(p1_xy*p1_xy))/(2.0*p1_p3*p3_xy))*180)/PI;
                subangle += (acos(((p3_xy*p3_xy)+(p2_p3*p2_p3)-(p2_xy*p2_xy))/(2.0*p3_xy*p2_p3))*180)/PI;
                if(abs(mainangle - subangle) > EPS) in = false;

                if(abs((p2_xy+p1_xy) - p1_p2) <= EPS) in = false;
                if(abs((p2_xy+p3_xy) - p2_p3) <= EPS) in = false;
                if(abs((p3_xy+p1_xy) - p1_p3) <= EPS) in = false;

                if(in){
                    found = true;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
        }
        if(!found) cout << "Point " << j << " is not contained in any figure" << endl;
        j++;
    }
}

int main(){

    FastIO;
    // ll c_n = 0;
    // ll t; cin >> t;
    // while(t--){
    //     cout << "Case " << ++c_n << ": ";
        //cout << "Case " << ++c_n << ":" << endl;
        solve();
    //}
}