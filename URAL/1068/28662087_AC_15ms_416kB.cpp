#include <iostream>
using namespace std;
int main()
{
    long long int i, N, sum=0;
    cin >> N;
    if(N<0)
    {
        for(i=1; i>=N; i--)
        {
            sum+=i;
        }
        cout << sum << endl;
    }
    else if(N>0)
    {
        for(i=1; i<=N; i++)
        {
            sum+=i;
        }
        cout << sum << endl;
    }
    else if(N==0)
    {
        cout << "1" << endl;
    }
}
