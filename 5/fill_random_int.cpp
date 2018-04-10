#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iostream>
#include <ctime>
using namespace std;
void fill_random_int(vector<int> &v,int cnt)
{
    v.clear();
    for (int i=0; i < cnt;i++)
    {
        v.push_back(rand());
    }
}
void test_sort(vector<int>&v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1;i++)
    {
        // if(v[i] > v[i + 1]) throw "sort error";
        if(v[i] > v[i + 1])
            printf("%d>%d\n", v[i], v[i + 1]);
    }
/*  sort(v.begin(), v.end(),greater<int>());
    for (int i = 0; i < v.size()-1;i++)
    {
        if(v[i] > v[i + 1]) throw "sort error";
    }
 */
}
int main()
{
    srand(time(NULL));
    vector<int> v;
    fill_random_int(v, 1000000);
    try{
        test_sort(v);
    }
    catch(const char* msg)
    {
        cout << msg << endl;
    }
    return 0;
}