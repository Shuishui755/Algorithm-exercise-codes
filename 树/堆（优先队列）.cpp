//洛谷P3378
//思路分析：用STL库中的优先队列（本质上就是堆）来简化刚刚刚代码
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>>pq;   //创建优先队列，从小到大排序

    for(int i = 0; i < n; i++)
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int number;
            cin >> number;
            pq.push(number);
        }
        else if(op == 2) cout << pq.top() << '\n';
        else pq.pop();
    }
}