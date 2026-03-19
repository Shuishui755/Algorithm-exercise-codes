//思路分析：后缀表达式从前向后遍历，数字入栈，加减乘除符号则从栈中弹出两个数字进行运算，结果继续入栈，直至遍历完字符‘@’符号
#include<bits/stdc++.h>
using namespace std;

//定义计算方法根据符号进行计算
int calculate(int front, int rear, char character)
{
    switch (character)
    {
        case '+': return front + rear; 
        case '-': return front - rear; 
        case '*': return front * rear; 
        case '/': return front / rear; 
        default: return 0;
    }
}

int main()
{
    string s;
    cin >> s;

    int i = 0;
    stack<int>st_num;  //定义数字栈

    //从头开始遍历字符串
    int temp = 0;   //存储遍历的数字
    while(i < s.length() && s[i] != '@')
    {
        while(isdigit(s[i]))
        {
            temp += s[i] - '0';
            if(!isdigit(s[i+1]))    
            {
                st_num.push(temp);
                temp = 0;
            }
            else temp *= 10;    //处理多位数情况
            i++;
        }

        //判断计算符号并调用相应方法计算
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int rear = st_num.top();
            st_num.pop();
            int front = st_num.top();
            st_num.pop();
            st_num.push(calculate(front, rear, s[i]));
        }
        i++;
    }
    cout << st_num.top();
    return 0;
}