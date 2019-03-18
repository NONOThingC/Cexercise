#include <algorithm>
#include <vector>
#include <cstdio>
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
bool getSubSet(vector<vector<int>> & store_vector,int digit,int start_length,int end_length)
//start_length is minimum digit of subset,end_length is maximum digit of subset(not including end_length)
{
    if(digit<start_length) return false;
    if(end_length<start_length) return false;
    for(int i=start_length;i<end_length;i++)
    {  
        vector<int> vecInt;
        combination(store_vector, digit, i);
    }
}

int main()
{
    vector<vector<int>> results;
    if(getSubSet(results,5,0,6))
    printf("successful");

    return 0;
}