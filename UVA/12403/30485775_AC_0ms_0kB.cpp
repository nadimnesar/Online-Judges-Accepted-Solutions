#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long sum = 0;
    int t;
    cin >> t;
    while(t--)
    {
        string str; cin >> str;
        if(str == "donate"){
        	int m;
        	cin >> m;
        	sum += m;
        }
        else{
        	cout << sum << endl;
        }
    }
}