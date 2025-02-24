//
// Created by bolt on 25-2-24.
//
/*
 * 思路是对手元素入列，其扩展元素入列，然后队首元素出列
 * 广度遍历直到终点
 */
#include <queue>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;
    int step;
};

queue<point> q;//存储队列点及其扩展

int main()
{
    //记录基本信息
    int board[100][100];//为地图
    int memory[100][100];//记录是否走过，BFS不重复遍历
    int startx, starty, endx, endy, barrierx, barriery;
    cout << "请按顺序输入起点位置，终点位置" << endl;
    cin >> startx >> starty >> endx >> endy;
    cout << "请输入障碍点位置，可以有多个，注意合理" << endl;
    while (cin >> barrierx >> barriery)
        board[barrierx][barriery] = 1;
    int move_x[4]={-1,1,0,0}; //记录x方向上的移动，顺序为上下左右
    int move_y[4]={0,0,-1,1}; //记录y

    //BFS
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;

    memory[startx][starty] = 1;
    q.push(start); //起始位置入队
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, step=q.front().step; //取出队首元素
        if (x == endx && y == endy)
            cout<<"恭喜到达终点！共走了"<<step<<"步"<<endl;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x+move_x[i];
                int ny = y+move_y[i]; //进行扩展
                if (0<=nx && nx<100 && 0<=ny && ny<100 && board[nx][ny]!=1 && memory[nx][ny]!=1)
                {
                    point temp;
                    temp.x = nx, temp.y = ny;
                    temp.step = q.front().step+1;
                    q.push(temp); //扩展元素入列
                    memory[nx][ny] = 1; //记录
                }
            }
        }
        q.pop(); //拓展完毕，队首元素出队
    }
}
