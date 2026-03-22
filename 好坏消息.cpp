//洛谷P2629
//思路分析：利用前缀和算法，将和大于零的问题转换成pref[k+n-1]>=pref[k-1]的最小值问题,利用单调队列滑动窗口算法维护单调性。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>num(n);
    for(int i = 0; i < n; i++) cin >> num[i];   //输入具体消息的好坏都

    //利用双倍数字思想，构成循环数组
    vector<int> double_num(2*n+1);
    for(int i = 1; i <= 2*n; i++) double_num[i] = num[(i - 1) % n];

    //求前缀和
    vector<int>pref(2*n + 1);
    pref[0] = 0;
    for(int i = 1; i <= 2*n; i++) pref[i] = pref[i-1] + double_num[i];

    //遍历探寻k取值
    int cnt = 0;    //定义计数器
    deque<int>dq;
    for(int i = 1; i <= 2*n; i++)
    {
        //判断是否已经过时
        if(!dq.empty() && dq.front() < i-n+1) dq.pop_front();

        //滑动窗口算法维护单调性
        while(!dq.empty() && pref[i] < pref[dq.back()]) dq.pop_back();

        dq.push_back(i);
        //最小值判别得出k
        if(i > n) if(pref[dq.front()] >= pref[i-n]) cnt++;
    }

    cout << cnt;
    return 0;
}