#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t, c=1;
    cin >> t;
    while(t--)
    {
        long long int w;
        cin >> w;
        if(w%2!=0)
        {
            cout << "Case " << c++ << ": Impossible" << endl;
        }
        else
        {
            long long int limit=w/2, odd=0;
            for(int even=2; even<=limit; even=even+2)
            {
                if((w%even)==0)
                {
                    odd=w/even;
                }
                if(odd%2==1)
                {
                    cout << "Case " << c++ << ": " << odd << ' ' << even << endl;
                    break;
                }
            }
        }
    }
}
