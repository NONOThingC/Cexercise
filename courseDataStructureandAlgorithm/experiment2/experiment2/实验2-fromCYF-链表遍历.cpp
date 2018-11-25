#include<iostream>
using namespace std;

#define TOTAL_MAN 30
#define SPACE 9
#define REST_MAN 15

struct man
{
	int id;
	struct man * next;
};

class ship
{
	int people_num;
	int kick_list[REST_MAN];
	struct man * man;
public:
	ship();
	int kick_one();
	int * kick();
};
//class ship
ship::ship()
{
	man = new struct man;
	man->id = 1;
	struct man * temp = man;
	struct man * prior = man;
	for (int i = 0; i < TOTAL_MAN - 1; i++)
	{
		temp = new struct man;
		prior->next = temp;
		temp->id = (i + 2);
		prior = prior->next;
	}
	prior->next = man;
}
int ship::kick_one()
{
	int kick_id;
	struct man * temp;
	for (int i = 0; i < SPACE - 2; i++)
	{
		man = man->next;
	}
	temp = man;
	man = man->next->next;
	kick_id = temp->next->id;
	delete temp->next;
	temp->next = man;
	return kick_id;
}
int * ship::kick()
{
	int * all_kick_id = new int[TOTAL_MAN - REST_MAN];
	for (int i = 0; i < TOTAL_MAN - REST_MAN; i++)
	{
		all_kick_id[i] = kick_one();
	}
	return all_kick_id;
}

int main()
{
	int * ids = new int[TOTAL_MAN - REST_MAN];
	ship test_ship;
	ids = test_ship.kick();
	for (int i = 0; i < TOTAL_MAN - REST_MAN; i++)
	{
		cout << ids[i] << ' ';
	}
	system("pause");
	return 0;
}