#define DEBUG
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

map<string,int> cnt;
vector<string> words;

string standlized(const string &x)
{
    string ans=x;
    for (int i = 0; i < ans.length();i++)
    {
        if (isalpha(ans[i]))
        {
            ans[i] =   tolower(ans[i]);
        }
        else
            ans[i] = ' ';
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
#ifdef DEBUG
    freopen("input54.txt", "r", stdin);
    freopen("output54.txt", "w", stdout);
#endif

    string x;
    vector<string> ans;
    while (cin >> x)
    {
        if(x[0] == '#')
            break;
        words.push_back(x);
        string r=standlized(x);
        if(cnt.count(r) != 1)
            cnt[r] = 0;
        cnt[r]++;
    }
    for (int i = 0; i < words.size();i++)
    {
        if(cnt[standlized(words[i])]==1)
        {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << endl;
    }
        return 0;
}