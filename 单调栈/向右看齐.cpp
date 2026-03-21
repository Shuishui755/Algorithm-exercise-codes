//思路分析：根据题意向右看齐，特别地你虚遍历身高数组，使用单调栈数据结构从矮到高存储遍历的奶牛身高，当现有奶牛身高低于栈顶时入栈，否则弹出栈顶直到栈顶奶牛身高高于当前奶牛
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //输入奶牛数目n以及身高信息height[]
    int n;
    cin >> n;

    int height[n], obj[n];
    for(int i = 1; i <= n; i++) cin >> height[i];

    stack<int>st;   //定义栈
    //逆序遍历数组
    for(int i = n; i > 0; i--)
    {
        //while循环判断是否入栈
        while(!st.empty() && height[i] >= height[st.top()]) st.pop();
        if(st.empty()) obj[i] = 0;
        else obj[i] = st.top();
        st.push(i);
    }

    //再反向输出仰望对象
    for(int i = 1; i <= n; i++) cout << obj[i] << '\n';

    return 0;
}