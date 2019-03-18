#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
ll FastPower(ll x, ll n)
{
    if (n == -1)
        return -1;
    else if (n == 0)
        return 1;
    else
    {
        ll weight = x;
        ll t = n;
        ll sum = 1;
        while (t>0)
        {
            if (t % 2) //不可以被2整除
            {
                sum *= weight;
            }
            t >>= 1;
            weight *= x * x;
        }
    }
    return sum;
}