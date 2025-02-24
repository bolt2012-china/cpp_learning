//
// Created by bolt on 25-2-24.
//
#include <iostream>
#include <stack>
using namespace std;

struct point
{
    int x;
    int y;
    int step;
};

stack<point> s;

int main()
{
    //记录基本信息
    int board[100][100]; //为地图
    int memory[100][100]; //记录是否走过，DFS不重复遍历
    int startx, starty, endx, endy, barrierx, barriery;
    cout << "请按顺序输入起点位置，终点位置" << endl;
    cin >> startx >> starty >> endx >> endy;
    cout << "请输入障碍点位置，可以有多个，注意合理" << endl;
    while (cin >> barrierx >> barriery)
        board[barrierx][barriery] = 1;
    int move_x[4]={-1,1,0,0}; //记录x方向上的移动，顺序为上下左右
    int move_y[4]={0,0,-1,1}; //记录y

    point start,end;
    start.x = startx, start.y = starty, start.step = 0;
    end.x = endx, end.y = endy;
    memory[startx][starty] = 1;

    stack<point> s;
    s.push(start);
    while (!s.empty())
    {
        point p = s.top();
        if (p.x == end.x && p.y == end.y)
            cout<<"恭喜到达终点！共走了"<<p.step<<"步"<<endl;
        bool flag = false;
        int x=p.x, y=p.y, step=p.step;
        for (int i = 0; i < 4; i++)
        {
            int nx = x+move_x[i];
            int ny = y+move_y[i]; //进行扩展
            if (0<=nx && nx<100 && 0<=ny && ny<100 && board[nx][ny]!=1 && memory[nx][ny]!=1)
            {
                point temp;
                temp.x = nx, temp.y = ny;
                temp.step = s.top().step+1;
                s.push(temp); //扩展元素入列
                memory[nx][ny] = 1; //记录
                flag = true;
            }
        }
        if (!flag) //这一步是必要的，flag记录是否还有未被访问过的节点
            // 若直接pop，永远不会到达终点，因为会反复添加同一个，最后栈会全部清空
            s.pop();
    }
}
