//本体使用滑动窗口算法来优化整体代码，主要是降低时间复杂度
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int num[n];
    for(int i = 0; i < n; i++) cin >> num[i];

    //创建双端队列，并开始遍历
    deque<int>dq;
    cout << 0 << '\n';  //切忌使用endl，频繁刷新缓冲区容易超时

    for(int i = 0; i < n-1; i++)
    {
        while(!dq.empty() && num[i] < num[dq.back()]) dq.pop_back();
        dq.push_back(i);
        
        cout << num[dq.front()] << '\n';

        if(i - dq.front() >= m-1) dq.pop_front();
    }
    return 0;
}