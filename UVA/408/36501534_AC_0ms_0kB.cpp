#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    long long n;
    long long s;
bool flag = false;
    while(cin>>n>>s){
      string str_n = to_string(n);
      string str_s = to_string(s);
      int space = 10-str_n.size();
      while(space--){
        cout << ' ';
      }
      cout << str_n;
      space = 10 + str_s.size();
      space = 20 - space;
      while(space--){
        cout << ' ';
      }
      cout << str_s;
      space = 4;
      while(space--){
        cout << ' ';
      }
      if(__gcd(n, s) == 1) cout << "Good Choice" << endl;
      else cout << "Bad Choice"<<endl;
      cout << endl;
    }
}