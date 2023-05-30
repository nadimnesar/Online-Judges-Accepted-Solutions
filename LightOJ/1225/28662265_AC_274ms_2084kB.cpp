#include <bits/stdc++.h>
using namespace std;
int palindromic(int a)
{
    int sum=0;
    while(a!=0)
    {
        int r;
        r=a%10;
        sum=sum*10+r;
        a=a/10;
    }
    return sum;
}
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        int n, p;
        cin >> n;
 
        p=palindromic(n);
        if(n==p)
        {
            cout << "Case " << j++ << ": Yes" << endl;
        }
        else
            cout << "Case " << j++ << ": No" << endl;
 
    }
}
