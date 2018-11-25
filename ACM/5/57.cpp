#define DEBUG
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int coeff[3] = {2, 3, 5};
const int targetnumber = 1500;
int main()
{
#ifdef DEBUG
    freopen("input57.txt", "r", stdin);
    freopen("output57.txt", "w", stdout);
#endif
    priority_queue<LL, vector<LL>, greater<LL>> geSet;
    set<LL> s;
    geSet.push(1);
    s.insert(1);
    int i = 1,x;
    while (i <= targetnumber)
    {
        LL temp;
        LL top = geSet.top();
        geSet.pop();
        for (int j = 0; j < 3; j++)
        {
            temp = top * coeff[j];
            if (!s.count(temp))
            {
                geSet.push(temp);
                s.insert(temp);
            }
        }
        if(i==targetnumber)
            x = top;

        i++;

    }
    cout << "The 1500'th ugly number is " << x << ".\n";

    return 0;
}