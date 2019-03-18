#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void combination(vector<vector<int>>&results, int n, int c) //C(n c)
//get 0,1 combination
{
    //initial first combination like:1,1,0,0,0
    vector<int> vecInt(n,0);
    //vecInt.insert(vecInt.begin(), n, 0);
    for (int i = 0; i < c; ++i)
    {
        vecInt[i] = 1;
    }
    //include initial value
    results.push_back(vecInt);
    for (int i = 0; i < n - 1; ++i)
    {
        if(vecInt[i] == 0 && vecInt[i + 1] == 0)    i+=2;
         if (vecInt[i] == 1 && vecInt[i + 1] == 0)
        {
            //1. first exchange 1 and 0 to 0 1
            swap(vecInt[i], vecInt[i + 1]);
            int count = 0;
            //2.move all 1 before vecInt[i] to left
            //sort(vecInt.begin(), vecInt.begin() + i);//slow
            for (int j = 0; j < i; j++)
            {
                if (vecInt[j])
                {
                    vecInt[j] = 0;
                    vecInt[count++] = 1;
                }
            }
            //now it is new series
            results.push_back(vecInt);
            //try do step 1 and 2 from front
            i = -1;
        }
    }
}

int main()
{
    const int N = 5;
    int t[N] = {1, 2, 3, 4, 5};
    vector<vector<int>> results;
    combination(results, N, 2);
    int tt=results.size();

    return 0;
}
