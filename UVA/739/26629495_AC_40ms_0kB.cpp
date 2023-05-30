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

    cout << "         NAME                     SOUNDEX CODE" << endl;
    string str;
    while(cin >> str){
        cout << "         ";
        cout << str;
        int len = str.size();
        for(int i = 1; i < 26-len; i++){
            cout << ' ';
        }
        string encoded; encoded.clear();
        encoded += str[0];
        for(int i = 1; i < len; i++){
            if(str[i] == 'A' or str[i] == 'E' or str[i] == 'I' or str[i] == 'O' or str[i] == 'U' or str[i] == 'Y' or str[i] == 'W' or str[i] == 'H'){
                continue;
            }
            else if(str[i] == 'B' or str[i] == 'P' or str[i] == 'F' or str[i] == 'V'){
                if(str[i-1] != 'B' and str[i-1] != 'P' and str[i-1] != 'F' and str[i-1] != 'V'){
                    encoded += '1';
                }
                else continue;
            }
            else if(str[i] == 'C' or str[i] == 'S' or str[i] == 'K' or str[i] == 'G' or str[i] == 'J' or str[i] == 'Q' or str[i] == 'X' or str[i] == 'Z'){
                if(str[i-1] != 'C' and str[i-1] != 'S' and str[i-1] != 'K' and str[i-1] != 'G' and str[i-1] != 'J' and str[i-1] != 'Q' and str[i-1] != 'X' and str[i-1] != 'Z'){
                    encoded += '2';
                }
                else continue;
            }
            else if(str[i] == 'D' or str[i] == 'T'){
                if(str[i-1] != 'D' and str[i-1] != 'T'){
                    encoded += '3';
                }
                else continue;
            }
            else if(str[i] == 'L'){
                if(str[i-1] != 'L'){
                    encoded += '4';
                }
                else continue;
            }
            else if(str[i] == 'M' or str[i] == 'N'){
                if(str[i-1] != 'M' and str[i-1] != 'N'){
                    encoded += '5';
                }
                else continue;
            }
            else{
                if(str[i-1] != 'R'){
                    encoded += '6';
                }
                else continue;
            }
        }
        encoded += '0';
        encoded += '0';
        encoded += '0';

        for(int i = 0; i < 4; i++){
            cout << encoded[i];
        }
        cout << endl;
    }
    cout << "                   END OF OUTPUT" << endl;
    /*cout << "         |         |              |" << endl;
    cout << "         |         |              |__ Column 35" << endl;
    cout << "         |         |__ Column 20" << endl;
    cout << "         |__ Column 10" << endl;*/


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}