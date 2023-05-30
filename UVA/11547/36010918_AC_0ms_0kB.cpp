#include <bits/stdc++.h>
using namespace std;
int dpoint(long long int n)
{
    n/=10;
    return abs(n%10);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        n=((((((n*567)/9)+7492)*235)/47)-498);
        cout << dpoint(n) << endl;
    }
}