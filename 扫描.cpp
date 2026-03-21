//洛谷P2032
//思路分析：这是一道经典的滑动窗口优化算法，使用单调队列“首进尾出取最大”每次（第K个数开始）从队尾取出元素，即为所求的最大值，每个元素仅进出队一次，复杂度为O（n）
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int num[n]; //定义存储数据数组
    for(int i = 0; i < n; i++) cin >> num[i];

    deque<int>dq;   //定义单调队列

    //遍历数组开始取值
    for(int i = 0; i < n; i++)
    {
        while(!dq.empty() && num[i] > num[dq.front()]) dq.pop_front();  //“首进尾出取最大”
        dq.push_front(i);

        if(i >= k-1)  //开始输出
        {
            cout << num[dq.back()] << '\n';
            if(i -dq.back() >= k-1) dq.pop_back();    //清除“过期的元素”
        }
    }

    return 0;
}