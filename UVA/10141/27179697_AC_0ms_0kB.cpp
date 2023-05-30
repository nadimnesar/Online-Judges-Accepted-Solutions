/**Bismillahir Rahmanir Rahim.**/

/**
 *    author:  nasimnoob
**/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<cstdio>

using namespace std;

//----------------------------------------------------------//

typedef long long int                        ll;
typedef unsigned long long int              ull;
typedef long double                          ld;

//-----------------------------------------------------------//
#define      test                       int t; cin>>t;  while(t--)

#define      cube(x)                    (x*x*x)
#define      sqr(x)                     (x*x)

#define      INPUT                      freopen("input.txt", "r", stdin)
#define      OUTPUT                     freopen("output.txt", "w", stdout)

#define      srev                       reverse(s.begin(),s.end())
#define      sortstr                    sort(s.begin(), s.end());
#define      gtl(x)                     getline(cin, (x))
#define      dot(x)                     fixed << setprecision(x)

#define      Case                       cout << "Case " << ++tt << ": " ;

#define      PI                         acos(-1) // 3.1415926535897932
#define      MIN                        9999999

#define      Faster                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);




//scanf("%[^\n]%*c", str);
//sort(s,s+n,greater<int>());
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);


//--------------------------------------Solution------------------------------//

int main()
{
    //Faster;


    int tt = 0 ;
    int space = 0 ;

    int num_of_req, proposal;

    while ( cin >> num_of_req >> proposal and num_of_req and proposal )
    {
        cin.ignore();
        if (space) cout << endl;
        space++;
        for (int i = 0 ; i < num_of_req ; i++)
        {
            string  s;
            getline(cin, s);
        }
        double check = 0;
        string best_proposal;
        double met = DBL_MAX;
        for (int i = 0 ; i < proposal ; i ++)
        {
            string str ;
            getline(cin, str);
            double price ;
            double n;
            cin >> price ;
            cin >> n;
            cin.ignore();
            for (int j = 0 ; j < n ; j ++)
            {
                string name;
                getline(cin, name);
            }
            double avg = (double)(n/num_of_req);
            if (check < avg)
            {
                best_proposal = str ;
                met = price ;
                check = avg;
            }
            else if (check == avg)
            {
                if (met > price)
                {
                    best_proposal = str ;
                    met = price ;
                    check = avg ;
                }
            }
        }

        cout << "RFP #" << ++tt << endl;;
        cout << best_proposal << endl;

    }

    return 0 ;
}





