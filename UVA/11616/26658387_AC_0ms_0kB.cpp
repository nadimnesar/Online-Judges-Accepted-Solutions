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

    string str;
    while(cin >> str){
        if(1 <= (str[0]-48) and (str[0]-48) <= 9){
            int num;
            stringstream ss(str);
            ss >> num;
again:
            if(num >= 1000){
                cout << 'M';
                num -= 1000;
                goto again;
            }
            else if(num >= 900){
                cout << "CM";
                num -= 900;
                goto again;
            }
            else if(num >= 500){
                cout << 'D';
                num -= 500;
                goto again;
            }
            else if(num >= 400){
                cout << "CD";
                num -= 400;
                goto again;
            }
            else if(num >= 100){
                cout << 'C';
                num -= 100;
                goto again;
            }
            else if(num >= 90){
                cout << "XC";
                num -= 90;
                goto again;
            }
            else if(num >= 50){
                cout << 'L';
                num -= 50;
                goto again;
            }
            else if(num >= 40){
                cout << "XL";
                num -= 40;
                goto again;
            }
            else if(num >= 10){
                cout << 'X';
                num -= 10;
                goto again;
            }
            else if(num >= 9){
                cout << "IX";
                num -= 9;
                goto again;
            }
            else if(num >= 5){
                cout << 'V';
                num -= 5;
                goto again;
            }
            else if(num >= 4){
                cout << "IV";
                num -= 4;
                goto again;
            }
            else if(num >= 1){
                cout << 'I';
                num -= 1;
                goto again;
            }
            cout << endl;
        }
        else{
            int num = 0;
            int len = str.size();

            if(str[0] == 'I') num += 1;
            else if(str[0] == 'V') num += 5;
            else if(str[0] == 'X') num += 10;
            else if(str[0] == 'L') num += 50;
            else if(str[0] == 'C') num += 100;
            else if(str[0] == 'D') num += 500;
            else if(str[0] == 'M') num += 1000;

            for(int i = 1; i < len; i++){
                if(str[i] == 'I') num += 1;
                else if(str[i] == 'V'){
                    if(str[i-1] == 'I'){
                        num += 3;
                    }
                    else num += 5;
                }
                else if(str[i] == 'X'){
                    if(str[i-1] == 'I'){
                        num += 8;
                    }
                    else num += 10;
                }
                else if(str[i] == 'L'){
                    if(str[i-1] == 'X'){
                        num += 30;
                    }
                    else num += 50;
                }
                else if(str[i] == 'C'){
                    if(str[i-1] == 'X'){
                        num += 80;
                    }
                    else num += 100;
                }
                else if(str[i] == 'D'){
                    if(str[i-1] == 'C'){
                        num += 300;
                    }
                    else num += 500;
                }
                else if(str[i] == 'M'){
                    if(str[i-1] == 'C'){
                        num += 800;
                    }
                    else num += 1000;
                }
            }
            cout << num << endl;
        }
    }
    

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}