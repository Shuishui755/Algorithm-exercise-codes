//思路分析：为了确保不超时的前提下，使用双端队列（每个数只需进出队一次，且排序一次）再分别“尾进首出取最小”、“首进尾出取最大”输出结果
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    //录入序列信息
    int num[n];
    for(int i = 0; i < n; i++) cin >> num[i];

    //“尾进首出取最小”
    deque<int>dq_min;   //定义求最小值双端队列
    for(int i = 0; i < n; i++)
    {
        while(!dq_min.empty() && num[i] < num[dq_min.back()]) dq_min.pop_back();
        dq_min.push_back(i);

        //k次开始输出
        if(i >= k-1) cout << num[dq_min.front()] << " ";
        
        if(i - dq_min.front() >= k-1) dq_min.pop_front();
    }

    cout << "\n";

    //“首进尾出取最大”
    deque<int>dq_max;   //定义求最大值双端队列
    for(int i = 0; i < n; i++)
    {
        while(!dq_max.empty() && num[i] > num[dq_max.front()]) dq_max.pop_front();
        dq_max.push_front(i);

        //k次开始输出
        if(i >= k-1) cout << num[dq_max.back()] << " ";
        
        if(i - dq_max.back() >= k-1) dq_max.pop_back();
    }

    return 0;
}