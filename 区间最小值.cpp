//思路分析：依旧利用双端队列思想，对序列每个值都创建一个队列，“尾进首出取最小”
#include <bits/stdc++.h>
using namespace std;

//定义“尾进首出取最小”函数
int findMin(int num[], int start, int end)
{
    //每个数都创建新的队列来存放数据
    deque<int>dq;


    //“尾进首出取最小”
    for(int i = start; i <= end; i++)
    {
        if(dq.empty()) dq.push_back(i);
        else
        {
            while(!dq.empty() && num[i] < num[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
    }

    return num[dq.front()];                                        
}

int main()
{
    int n, m;
    cin >> n >> m;

    int num[n];
    for(int i = 0; i < n; i++) cin >> num[i];

    cout << 0 << endl;

    for(int i = 1; i < n; i++)
    {
        if(i < m) cout << findMin(num, 0, i-1) << endl;
        else cout << findMin(num, i-m, i-1) << endl;
    }
}