#include<cstudio>
#include <cstdlib>
#include <ctime>
template<typename T,typename BACK>
BACK randT(T Lower, T Upper)
{
    T temp;
    if (Lower > Upper)
    {
        temp = Upper;
        Upper = Lower;
        Lower = temp;
    }
    return rand() / (double)RAND_MAX *(Upper - Lower) + Lower;
}

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(0));

    return 0;
}
