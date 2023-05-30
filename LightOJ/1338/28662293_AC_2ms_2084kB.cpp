#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int t, c=1;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        char s1[101], s2[101];
        cin.getline(s1, 101);
        cin.getline(s2, 101);
        for (int i=0; i<strlen(s1); i++)
            s1[i]=tolower(s1[i]);
        for (int i=0; i<strlen(s2); i++)
            s2[i]=tolower(s2[i]);
        int i=0, s1alpha[26]={0}, j;
        while (s1[i]!='\0')
        {
            if (s1[i]>='a' && s1[i]<='z')
            {
                j=s1[i]-'a';
                ++s1alpha[j];
            }
            ++i;
        }
        int k=0, s2alpha[26]={0}, l;
        while (s2[k]!='\0')
        {
            if (s2[k]>='a' && s2[k]<='z')
            {
                l=s2[k]-'a';
                ++s2alpha[l];
            }
            ++k;
        }
        int n=0, m;
        for (m=0; m<26; m++)
        {
            if(s1alpha[m]==s2alpha[m])
                n++;
        }
        if(n==26)
            cout << "Case " << c++ << ": Yes" << endl;
        else cout << "Case " << c++ << ": No" << endl;
    }
}