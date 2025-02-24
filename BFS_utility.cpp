//
// Created by bolt on 25-2-24.
//
/*
 * ˼·�Ƕ���Ԫ�����У�����չԪ�����У�Ȼ�����Ԫ�س���
 * ��ȱ���ֱ���յ�
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

queue<point> q;//�洢���е㼰����չ

int main()
{
    //��¼������Ϣ
    int board[100][100];//Ϊ��ͼ
    int memory[100][100];//��¼�Ƿ��߹���BFS���ظ�����
    int startx, starty, endx, endy, barrierx, barriery;
    cout << "�밴˳���������λ�ã��յ�λ�����ϰ���λ��" << endl;
    cin >> startx >> starty >> endx >> endy >> barrierx >> barriery;
    board[barrierx][barriery] = 1;
    int move_x[4]={-1,1,0,0}; //��¼x�����ϵ��ƶ���˳��Ϊ��������
    int move_y[4]={0,0,-1,1}; //��¼y

    //BFS
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;

    memory[startx][starty] = 1;
    q.push(start); //��ʼλ�����
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, step=q.front().step; //ȡ������Ԫ��
        if (x == endx && y == endy)
            cout<<"��ϲ�����յ㣡������"<<step<<"��"<<endl;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x+move_x[i];
                int ny = y+move_y[i]; //������չ
                if (0<=nx && nx<100 && 0<=ny && ny<100 && board[nx][ny]!=1 && memory[nx][ny]!=0)
                {
                    point temp;
                    temp.x = nx, temp.y = ny;
                    temp.step = q.front().step+1;
                    q.push(temp); //��չԪ������
                    memory[nx][ny] = 1; //��¼
                }
            }
        }
        q.pop(); //��չ��ϣ�����Ԫ�س���
    }
}

