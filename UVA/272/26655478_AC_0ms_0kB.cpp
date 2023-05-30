#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char text[100001];
    bool truef = true;
    while (cin.getline(text, 100001))
    {
        for (int i = 0; i < strlen(text) ; i++)
        {
            if (text[i] == '"')
            {
                if (truef)
                    printf("``");
                else
                    printf("''");
                truef = !truef;
            }
            else
                cout << text[i];
        }
        cout << endl;
    }
}