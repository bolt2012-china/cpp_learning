//
// Created by bolt on 25-1-20.
//
#include<iostream>
#include"Sales_item.h"
using namespace std;
int main()
{
    Sales_item total;   //保存和的变量，确保一直有数据可读
    if (cin >> total)
    {
        Sales_item trans;
        //读取剩余的交易记录
        while (cin >> trans)
        {
            if (total.isbn == trans.isbn) //如果仍在处理同一本书，销售额增加
                total += trans;
            else
            {
                cout << total << endl;  //打印前一本书的结果
                total = trans;  //total现在表示下一本书的销售额
            }
        }
        cout << total << endl;
    }
    else //没有输入就警告读者
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
