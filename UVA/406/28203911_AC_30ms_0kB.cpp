//notmycodefortesting

#include<bits/stdc++.h>
using namespace std;

bool isprime(int num)   //prime checker function
{

    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}


int main()
{

	#ifndef ONLINE_JUDGE
    	clock_t tStart = clock();
    	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif

    vector<int>prime;

    for(int i=1; i<=1000; i++)
    {
        if(isprime(i))
            prime.push_back(i);
    }

    bool line = false;

    int n,prnt;
    while(cin>>n>>prnt)
    {

        cout<<n<<' '<<prnt<<':';
        int cnt = 0;
        for(int i=0; i<(int)prime.size(); i++)
        {
            if(prime[i]<=n)
            {
             cnt++;
            }else
            break;


        }
        int num=cnt;
        if(num%2==0)
        {
            if(2*prnt>num)
            {
                for(int i=0; i<cnt; i++)
                    cout<<" "<<prime[i];
                cout<<endl;
            }
            else
            {
                int ans = (num-(2*prnt))/2;

                for(int i = ans;i<num-ans;i++)
                    cout<<" "<<prime[i];
                cout<<endl;
            }
        }
        else{
            if((2*prnt)-1>num)
            {
                for(int i=0; i<cnt; i++)
                    cout<<" "<<prime[i];
                cout<<endl;
            }
            else
            {
                int ans = (num-((2*prnt)-1))/2;

                for(int i = ans;i<num-ans;i++)
                    cout<<" "<<prime[i];
                cout<<endl;
            }
        }
        cout<<endl;
    }
    #ifndef ONLINE_JUDGE
    	fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
	#endif
}