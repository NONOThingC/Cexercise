#include <iostream>
using namespace std;
extern int sum;
int sum;
int answer(int agr_1, int agr_2, int agr_3, int agr_4)
{
	sum = agr_4 + agr_3 + agr_2 - agr_1;
	return sum;
}
int main()
{
	int a = 1, b = 2, c = 3,d=4;
	answer(a, b, c,d);

}
