//洛谷P1714
//思路分析：本题利用前缀和算法，将和最值问题转换为值最值问题，并利用单调队列来维护有序性，对每个单元求最大和，通过比较得出最终结果
#include <bits/stdc++.h>
using namespace std;

int  main()
{
    int n, m;
    int max_num = -1e18;
    cin >> n >> m;

    int num[n], pref[n+1];
    pref[0] = 0;    //初始化，为了从1开始方便计数

    for(int i = 0; i < n; i++) cin >> num[i];   //输入幸运值数据
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + num[i-1]; //求前缀和

    deque<int>dq;   //定义单调队列
    dq.push_back(0);
    //遍历前缀和
    for(int i = 1; i <= n; i++)
    {
        while(!dq.empty() && i - m > dq.front()) dq.pop_front();    //弹出超时前缀和
        if(!dq.empty()) max_num = max(max_num, pref[i] - pref[dq.front()]);
        while(!dq.empty() && pref[dq.back()] > pref[i]) dq.pop_back();  //维护队列单调性
        dq.push_back(i);
    }

    cout << max_num;
    return 0;
}