#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class BigInteger
{
  public:
    friend ostream &operator<<(ostream &out,  BigInteger const &x);
    friend istream &operator>>(istream &in, BigInteger &x);

    BigInteger operator+(const BigInteger &b)
{
    BigInteger c;
    c.s.clear();
    for (int i = 0, g = 0;; i++)
    {
        if (g == 0 && i >= s.size() && i >= b.s.size())
            break;
        int x = g;
        if (i < s.size())
            x += s[i];
        if (i < b.s.size())
            x += b.s[i];
        c.s.push_back(x);
        g = x / BASE;
    }
    return c;
}
    BigInteger operator+=( const BigInteger &b)
{
    *this=*this+b;
    return *this;
}

    bool operator<(const BigInteger &b)const 
    {
        if(s.size()!=b.s.size())
            return s.size() < b.s.size();
        for (int i = s.size() - 1; i >= 0;i--)
        {
            if(s[i]!=b.s[i])
                return s[i] < b.s[i];
        }
        return false;
    }
        bool operator>(const BigInteger &b)const 
    {
        if(s.size()!=b.s.size())
            return s.size() > b.s.size();
        for (int i = s.size() - 1; i >= 0;i--)
        {
            if(s[i]!=b.s[i])
                return s[i] > b.s[i];
        }
        return true;
    }
    BigInteger(long long num = 0)
    {
        *this = num;
    }
    BigInteger operator=(long long num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger operator=(const string &str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - i * WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator+(const BigInteger &b) const;

  private:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
};


ostream &operator<<(ostream &out, BigInteger const &x)
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}
istream &operator>>(istream &in, BigInteger &x)
{
    string s;
    if (!(in >> s))
        return in;
    x = s;
    return in;
}
