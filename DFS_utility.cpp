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
    int path[100][100]={4}; //��¼�����ڽӱ���

    //��¼������Ϣ
    int board[100][100];//Ϊ��ͼ
    int memory[100][100];//��¼�Ƿ��߹���DFS���ظ�����
    int startx, starty, endx, endy, barrierx, barriery;
    cout << "�밴˳���������λ�ã��յ�λ��" << endl;
    cin >> startx >> starty >> endx >> endy;
    cout << "�������ϰ���λ�ã������ж����ע�����" << endl;
    while (cin >> barrierx >> barriery)
        board[barrierx][barriery] = 1;
    int move_x[4]={-1,1,0,0}; //��¼x�����ϵ��ƶ���˳��Ϊ��������
    int move_y[4]={0,0,-1,1}; //��¼y

    //DFS
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;

    point parent = start; //��¼���ڵ�

    memory[startx][starty] = 1;
    s.push(start);

    while (!s.empty())
    {
        int x = s.top().x, y = s.top().y, step = s.top().step;
        point parent = s.top();
        if (x == endx && y == endy)
        {
            cout << "��ϲ�����յ㣡һ������" << step << "��" << endl;
        }
        else
        {
            for (int i=0; i<4; i++)
            {
                int nx = x+move_x[i];
                int ny = y+move_y[i]; //������չ
                if (0<=nx && nx<100 && 0<=ny && ny<100 && board[nx][ny]!=1 && memory[nx][ny]!=1)
                {
                    point temp;
                    temp.x = nx, temp.y = ny;
                    temp.step = s.top().step+1;
                    s.push(temp); //��չԪ������
                    memory[nx][ny] = 1; //��¼
                }
            }
            s.pop(); //��ջ
        }
    }
}