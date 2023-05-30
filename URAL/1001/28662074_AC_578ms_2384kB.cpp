#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <long long unsigned int> root;
    long long unsigned int r;
    while(scanf("%llu", &r)!=EOF)
    {
        root.push_back(r);
    }
    for (int i=root.size()-1; i>=0 ; i--)
	{
		cout << fixed << setprecision(4) << sqrt((root[i])) << endl;
	}
}