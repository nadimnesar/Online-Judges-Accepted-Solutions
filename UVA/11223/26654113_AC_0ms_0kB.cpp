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

void traslation(string temp){
    if(temp == " ") cout << ' ';
    else if(temp == ".-") cout << 'A';
    else if(temp == "-...") cout << 'B';
    else if(temp == "-.-.") cout << 'C';
    else if(temp == "-..") cout << 'D';
    else if(temp == ".") cout << 'E';
    else if(temp == "..-.") cout << 'F';
    else if(temp == "--.") cout << 'G';
    else if(temp == "....") cout << 'H';
    else if(temp == "..") cout << 'I';
    else if(temp == ".---") cout << 'J';
    else if(temp == "-.-") cout << 'K';
    else if(temp == ".-..") cout << 'L';
    else if(temp == "--") cout << 'M';
    else if(temp == "-.") cout << 'N';
    else if(temp == "---") cout << 'O';
    else if(temp == ".--.") cout << 'P';
    else if(temp == "--.-") cout << 'Q';
    else if(temp == ".-.") cout << 'R';
    else if(temp == "...") cout << 'S';
    else if(temp == "-") cout << 'T';
    else if(temp == "..-") cout << 'U';
    else if(temp == "...-") cout << 'V';
    else if(temp == ".--") cout << 'W';
    else if(temp == "-..-") cout << 'X';
    else if(temp == "-.--") cout << 'Y';
    else if(temp == "--..") cout << 'Z';
    else if(temp == "-----") cout << '0';
    else if(temp == ".----") cout << '1';
    else if(temp == "..---") cout << '2';
    else if(temp == "...--") cout << '3';
    else if(temp == "....-") cout << '4';
    else if(temp == ".....") cout << '5';
    else if(temp == "-....") cout << '6';
    else if(temp == "--...") cout << '7';
    else if(temp == "---..") cout << '8';
    else if(temp == "----.") cout << '9';
    else if(temp == ".-.-.-") cout << '.';
    else if(temp == "--..--") cout << ',';
    else if(temp == "..--..") cout << '?';
    else if(temp == ".----.") cout << "'";
    else if(temp == "-.-.--") cout << '!';
    else if(temp == "-..-.") cout << '/';
    else if(temp == "-.--.") cout << '(';
    else if(temp == "-.--.-") cout << ')';
    else if(temp == ".-...") cout << '&';
    else if(temp == "---...") cout << ':';
    else if(temp == "-.-.-.") cout << ';';
    else if(temp == "-...-") cout << '=';
    else if(temp == ".-.-.") cout << '+';
    else if(temp == "-....-") cout << '-';
    else if(temp == "..--.-") cout << '_';
    else if(temp == ".-..-.") cout << '"';
    else if(temp == ".--.-.") cout << '@';
    return;
}


int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    bool br = false;
    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        if(br) cout << endl;
        br = true;
        cout << "Message #" << ++cn << endl;
        string str;
        str.clear();
        getline(cin, str);
        int len = str.size();
        string temp;
        for(int i = 0; i < len; i++){
            if(str[i] == ' '){
                if(str[i+1] == ' '){
                    traslation(temp);
                    temp.clear();
                    temp += ' ';
                }
                else{
                    traslation(temp);
                    temp.clear();
                }
            }
            else temp += str[i];
        }
        traslation(temp);
        cout << endl;
        temp.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}