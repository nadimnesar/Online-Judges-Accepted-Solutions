#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector< int >
#define vll             vector< ll >
#define vc              vector< char >
#define vs              vector< string >
#define pb              push_back
#define all(v)          v.begin(), v.end()
#define PI              acos(-1.0)  // 3.1415926535897932
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl

vector <string> Fn;

class Integer{
	private:
		string c;
	public:
		// Method to check within Two Integer number which is Big or same
		string BigIntFind(string a,string b){
			if(a.length() < b.length()) swap(a,b);
			string d = b;
			reverse(b.begin(),b.end());
			while(b.length() < a.length()) b.push_back('0');
			reverse(b.begin(),b.end());
			int i = 0;
			while(a[i]){
				if(a[i] > b[i]) return a;
				else if(a[i] < b[i]) return d;
				i++;
			}
			return "same";
		}

		// Method to Findout Digits of a number
		long int Digit(long int n){
			long int i = 0;
			for(;n > 0; i++) n /= 10;
			return i;
		}

		// Method to Convert string to number
		long int s2li(string a){
			long int n = 0;
			reverse(a.begin(),a.end());
			for(int i=0; a[i]; i++) n = ( n*10 ) + (a[i]-48);
			return n;
		}

		// Method to Convert number to string
		string li2s(long int a){
			c.clear();
			while(a > 0){
				c.push_back((a%10)+48);
				a /= 10;
			}
			reverse(c.begin(),c.end());
			return c;
		}

		// Method to Add two Integer number
		string Add(string a,string b){
			c.clear();
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			if(a.length() < b.length())
				swap(a,b);
			while(int(b.length()) < int(a.length()))
				b.push_back('0');

			int i = 0,carry = 0;
			while(a[i]){
				carry = carry + a[i]-48 + b[i]-48;
				c.push_back((carry %10) + 48);
				carry = carry / 10;
				i++;
			}
			while(carry > 9){
				c.push_back((carry % 10) + 48);
				carry = carry / 10;
			}
			if(carry != 0) c.push_back(carry + 48);
			reverse(c.begin(),c.end());
			return c;
		}

		// Method to Substruct within two Integer number
		string Minus(string a,string b){
			c.clear();
			bool flag = true;
			if(BigIntFind(a,b)==b){
				swap(a,b);
				flag = false;
			}
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			while(b.length() < a.length()) b.push_back('0');
			int i = 0,carry = 0,x = 0;
			while(a[i]){
				if(b[i] > a[i]) x = (a[i]-48) + 10;
				else x = a[i]-48;
				carry = x-(carry + (b[i]-48));
				c.push_back(carry+48);
				carry = x / 10;
				i++;
			}
			while(c[c.length()-1]=='0' && c.length() > 1) c.erase(c.length()-1,1);
			if(!flag) c.push_back('-');
			reverse(c.begin(),c.end());
			return c;
		}

		// Method for multiplication
		string M(string a,long int b){
			c.clear();
			long int m = 0,i;
			reverse(a.begin(),a.end());
			for(i = 0; a[i] ; i++){
				m = m + b * (a[i]-'0');
				c.push_back((m%10) + 48);
				m /= 10;
			}
			while(m > 0){
				c.push_back((m%10) + 48);
				m /= 10;
			}
			reverse(c.begin(),c.end());
			return c;
		}

		// Method for division
		string D(char ch,string a,long int b){
			c.clear();
			long int Len = a.length(),mod = 0,d = Digit(b),V = 0,i;
			i = 0;
			while(i < d || V < b){ V = (V * 10) + (a[i]-48); i++; }
			while(i < Len +1){

				c.push_back((V/b)+48);
				mod = V % b;
				V = (mod*10) + (a[i]-48);
				if(b > V) { i++; V = (V*10) + (a[i]-48); if(i!=Len+1) c.push_back('0'); }
				i++;
			}
			if(c.empty()) c = "0";
			if(ch=='m') c = li2s(mod);
			return c;
		}

		// Method to Generate Fibonacci numbers
		void F(string a,string b,long unsigned int n){
	    	if(n){
				Fn.push_back(a);
				c = Add(a,b);
				F(b,c,--n);
			}
		}
};

int main(){
	Integer Int;
	long int n;
	Int.F("1","1",10000);
	while(scanf("%ld",&n)==1){
		cout << Fn[n-1] << endl;
	}
	return 0;
}