#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printResult(vector<int> &vecInt, int t[])
{
    for (int i = 0; i < vecInt.size(); ++i)
    {
        if (vecInt[i] == 1)
        {
            cout << t[i] << " ";
        }
    }
    cout << endl;
}

void combination(int c, int n,vector<int> & vecInt)//C(n c)
//get 0,1 combination
{
    //initial first combination like:1,1,0,0,0
    vecInt.insert(vecInt.begin(), n, 0);
    for (int i = 0; i < c; ++i)
    {
        vecInt[i] = 1;
    }
    
    for (int i = 0; i < n - 1; ++i)
    {
        if(vecInt[i] == 1 && vecInt[i + 1] == 1) ++i;
        else if (vecInt[i] == 1 && vecInt[i + 1] == 0)
        {
            //1. first exchange 1 and 0 to 0 1
            swap(vecInt[i], vecInt[i + 1]);
            int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (vecInt[j])
                {
                    vecInt[j] = 0;
                    vecInt[count++] = 1;
                }
            }
            //2.move all 1 before vecInt[i] to left
            //sort(vecInt.begin(), vecInt.begin() + i);//slow
            //try do step 1 and 2 from front
            i = -1;
        }
    }


}

int main()
{
    const int N = 5;
    int t[N] = {1, 2, 3, 4, 5};
    vector<int> zero_one_combination;
    combination(2, N,zero_one_combination);
    printResult(zero_one_combination,t);
    
    return 0;
}