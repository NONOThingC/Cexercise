#define DEBUG
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;
set<string> dict;
int main()
{
#ifdef DEBUG
    freopen("input53.txt", "r", stdin);
    freopen("output53.txt", "w", stdout);
#endif

    string x, buf;
    while (cin >> x)
    {
        for (int i = 0; i < x.length(); i++)
        {
            if (isalpha(x[i]))
                x[i] = tolower(x[i]);
            else
            {
                x[i] = ' ';
            }
        }
        stringstream ss(x);
        while (ss >> buf)
        {
            dict.insert(buf);
        }    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        cout << *it << endl;
    }
        cout << endl;    
    }

    return 0;
}