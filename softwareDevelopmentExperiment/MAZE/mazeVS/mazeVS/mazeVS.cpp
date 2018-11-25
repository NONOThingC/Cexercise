// mazeVS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

// mazeVS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// mazeVS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
#include <Windows.h>
#include <queue>
#define MAZE_MAX 50
using namespace std;
const int DrawPicture = 0;
const int DrawSearch = 0;
const int HEIGHT = 31;
const int WIDTH = 31;
int mazemap[HEIGHT + 4][WIDTH + 4];
struct stackpoint
{
	int x;
	int y;
};
stack<stackpoint> pool;

void printMaze();

bool finishsearch()
{
	for (int i = 2; i < HEIGHT + 3; i++)
	{
		for (int j = 2; j < WIDTH + 3; j++)
			if (mazemap[i][j] == 0)
			{
				return false;
			}
	}
	return true;
}
bool search_neibor(stackpoint &currentpoint, stackpoint &nextpoint)
{
	int amount = 0;
	bool temp[4]; //最多4个方向,对应于下
	//左
	if (mazemap[currentpoint.x - 2][currentpoint.y] == 0)
	{
		amount++;
		temp[0] = true;
	}
	else
		temp[0] = false;
	//下
	if (mazemap[currentpoint.x][currentpoint.y + 2] == 0)
	{
		amount++;
		temp[1] = true;
	}
	else
		temp[1] = false;
	//右
	if (mazemap[currentpoint.x + 2][currentpoint.y] == 0)
	{
		amount++;
		temp[2] = true;
	}
	//上
	else
		temp[2] = false;
	if (mazemap[currentpoint.x][currentpoint.y - 2] == 0)
	{
		amount++;
		temp[3] = true;
	}
	else
		temp[3] = false;
	//查看有无邻居
	if (amount == 0)
	{
		return false;
	}
	else
	{
		//有邻居就生成随机数并选择

		int randnumber = rand() % amount;
		int kk = 0;

		randnumber += 1;
		while (randnumber != 0)
		{
			if (temp[kk])
				randnumber--;
			kk++;
		}
		kk--;
		switch (kk)
		{
		case 0:
			nextpoint.x = currentpoint.x - 2;
			nextpoint.y = currentpoint.y;
			break;
		case 1:
			nextpoint.x = currentpoint.x;
			nextpoint.y = currentpoint.y + 2;
			break;
		case 2:
			nextpoint.x = currentpoint.x + 2;
			nextpoint.y = currentpoint.y;
			break;
		default:
			nextpoint.x = currentpoint.x;
			nextpoint.y = currentpoint.y - 2;
		}
		return true;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i <= HEIGHT + 3; i++)
		for (int j = 0; j <= WIDTH + 3; j++)
			mazemap[i][j] = 0;
	//初始化边缘
	for (int i = 0; i <= HEIGHT + 3; ++i)
	{
		mazemap[i][0] = 3;
		mazemap[i][1] = 3;
		mazemap[i][HEIGHT + 2] = 3;
		mazemap[i][HEIGHT + 3] = 3;
	}

	for (int i = 0; i <= WIDTH + 3; ++i)
	{
		mazemap[0][i] = 3;
		mazemap[1][i] = 3;
		mazemap[WIDTH + 2][i] = 3;
		mazemap[WIDTH + 3][i] = 3;
	}
	const int start_x = 2;
	const int start_y = 2;
	mazemap[start_x][start_y] = 1;
	//mazemap[HEIGHT][WIDTH+1] = 1;
	//初始点分配与入栈
	stackpoint *point = new stackpoint;
	point->x = start_x;
	point->y = start_y;
	pool.push(*point);
	stackpoint currentpoint, nextpoint;
	currentpoint = pool.top();
	printMaze();
	system("pause");
	system("cls");


	while (!pool.empty())
	{

		bool search_result = search_neibor(currentpoint, nextpoint);
		//如果找到就返回true，如果没找到就返回false
		//找邻居节点，如果找到就打通墙，并以新点为当前点
		//0是未访问要画墙，2是访问过画墙，1是访问过不画墙
		if (!search_result && mazemap[currentpoint.x][currentpoint.y] == 0)
			mazemap[currentpoint.x][currentpoint.y] = 2;
		else if (!search_result)
		{
			currentpoint = pool.top();
			pool.pop();
		}
		else if (search_result)
		{
			mazemap[currentpoint.x][currentpoint.y] = 1;
			mazemap[nextpoint.x][nextpoint.y] = 1;
			mazemap[currentpoint.x + (nextpoint.x - currentpoint.x) / 2][currentpoint.y + (nextpoint.y - currentpoint.y) / 2] = 1;
			pool.push(currentpoint);
			currentpoint = nextpoint;
			if (DrawPicture)
			{
				system("cls");
				printMaze();
				Sleep(1000);
			}

		}


	}
	delete point;
	point = nullptr;
	printMaze();
	system("pause");
	//解法

	int targetx = HEIGHT + 1;
	int targety = WIDTH + 1;
	//起始点标记
	mazemap[start_x][start_y] = 4;
	queue<stackpoint> BFSque;
	stackpoint startpoint;
	startpoint.x = start_x;
	startpoint.y = start_y;
	BFSque.push(startpoint);
	//用于路径生成
	int record_last_path[HEIGHT + 4][WIDTH + 4][2];
	record_last_path[start_x][start_y][0] = start_x;
	record_last_path[start_x][start_y][1] = start_y;
	//用于各方向坐标，分别对应左下右上
	int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int if_solution = 1;
	while (mazemap[targetx][targety] == 1)
	{
		if (DrawSearch) {
			printMaze();
		}
		if (BFSque.empty())
		{
			if_solution = 0;
			printf("no solution");
			break;
		}
		else {
			stackpoint temp_que_point = BFSque.front();
			int temp_quene_x = temp_que_point.x;
			int temp_quene_y = temp_que_point.y;
			BFSque.pop();
			for (int i = 0; i < 4; i++)
			{
				int searchx = temp_quene_x + dir[i][0];
				int searchy = temp_quene_y + dir[i][1];
				if (mazemap[searchx][searchy] == 1)
				{
					mazemap[searchx][searchy] = 4;
					record_last_path[searchx][searchy][0] = temp_quene_x;
					record_last_path[searchx][searchy][1] = temp_quene_y;
					stackpoint temp_push_ele;
					temp_push_ele.x = searchx;
					temp_push_ele.y = searchy;
					BFSque.push(temp_push_ele);
				}
			}

		}

	}
	printMaze();
	if (if_solution)
	{
		int count_step = 0;
		int targeti = targetx;
		int targetj = targety;
		printf("The path is:\n");
		for (; targeti != start_x || targetj != start_y;)
		{
			printf("(%d,%d)->", targeti, targetj);
			int tempi = targeti,tempj=targetj;
			targeti = record_last_path[tempi][tempj][0];
			targetj = record_last_path[tempi][tempj][1];
			count_step++;
		}
		printf("(%d,%d)", targeti, targetj);
		printf("\n\nshortest path step is %d\n", count_step);
	}
	system("pause");
	return 0;
}

void printMaze()
{
	//0是未访问要画墙，2是访问过画墙，1是访问过不画墙,3是墙，4是搜索点
	for (int i = 0; i <= HEIGHT + 3; i++)
	{
		for (int j = 0; j <= WIDTH + 3; j++)
			(mazemap[i][j] == 1) ? printf("□") :
			((mazemap[i][j] == 0 || mazemap[i][j] == 2) ? printf("█") :
			((mazemap[i][j] == 3) ? printf("●") : printf("※")));
		printf("%c", 10);
	}
	cout << endl;
}



//////
