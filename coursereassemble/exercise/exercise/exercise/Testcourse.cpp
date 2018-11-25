// mazeVS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
#define MAZE_MAX 50
using namespace std;

enum DIRECTION
{
    N = 1,
    E = 4,
    S = 2,
    W = 8
};
DIRECTION direction;
const int HEIGHT = 30;
const int WIDTH = 30;
int mazemap[HEIGHT + 4][WIDTH + 4];
struct stackpoint
{
    int x;
    int y;
};
stack<stackpoint> pool;

void printMaze();

bool finishsearch(stackpoint *point, const int &getpoint_flag)
{
    for (int i = 2; i < HEIGHT + 3; i++)
    {
        for (int j = 2; j < WIDTH + 3; j++)
            if (mazemap[i][j] == 0)
            {
                if (getpoint_flag == 1)
                {
                    point->x = i;
                    point->y = j;
                }
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
    //上
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
    //下
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
        srand((unsigned)time(NULL));
        int randnumber = rand() % amount;
        int i;
        for (i = 0; randnumber; i++)
        {
            if (temp[randnumber])
                randnumber--;
        }
        switch (i)
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
    for (int i = 0; i <= HEIGHT + 3; i++)
        for (int j = 0; j <= WIDTH + 3; j++)
            mazemap[i][j] = 0;
    //初始化边缘
    for (int i = 0; i <= HEIGHT + 3; ++i)
    {
        mazemap[i][0] = 1;
        mazemap[i][1] = 1;
        mazemap[i][HEIGHT + 2] = 1;
        mazemap[i][HEIGHT + 3] = 1;
    }

    for (int i = 0; i <= WIDTH + 3; ++i)
    {
        mazemap[0][i] = 1;
        mazemap[1][i] = 1;
        mazemap[WIDTH + 2][i] = 1;
        mazemap[WIDTH + 3][i] = 1;
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

    int pool_push_flag = 0;
    while (!finishsearch(point, pool_push_flag))
    {
        if (pool_push_flag)
            pool.push(*point);
        while (!pool.empty())
        {

            bool search_result = search_neibor(currentpoint, nextpoint);
            //如果找到就返回true，如果没找到就返回false
            //找邻居节点，如果找到就打通墙，并以新点为当前点
            //0是未访问要画墙，2是访问过画墙，1是访问过不画墙
            if (!search_result && mazemap[currentpoint.x][currentpoint.y] == 0)
                mazemap[currentpoint.x][currentpoint.y] == 2;
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
                currentpoint = nextpoint;
            }
        }
        pool_push_flag = 1;
    }
    delete point;
    point = nullptr;
    return 0;
}

void printMaze()
{
    //0是未访问要画墙，2是访问过画墙，1是访问过不画墙
    for (int i = 0; i <= HEIGHT + 3; i++)
    {
        for (int j = 0; j <= WIDTH + 3; j++)
            (mazemap[i][j] == 1) ? printf("　") : printf("█");
        printf("%c", 10);
    }
    cout << endl;
}
