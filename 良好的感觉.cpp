//洛谷P2422
//思路分析：本题利用单调栈求出每个感受值为最小值的区间，利用前缀和求出区间和，最后区间最小值与区间和乘积取最大值
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll>num(n+1), l(n+1), r(n+1), pref(n+1);
    for(int i = 1; i <= n; i++) cin >> num[i];

    //求前缀和
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + num[i];

    //遍历区间最小值的左边界
    stack<int>st;
    for(int i = 1; i <= n; i++)
    {
        while(!st.empty() && num[i] <= num[st.top()]) st.pop();
        if(st.empty()) l[i] = 0;
        else l[i] = st.top(); //与前缀和下标对齐
        st.push(i);
    }

    //同理求边界最小值的右边界
    while(!st.empty()) st.pop();    //清空数据栈

    for(int i = n; i > 0; i--)
    {
        while(!st.empty() && num[i] <= num[st.top()]) st.pop();
        if(st.empty()) r[i] = n+1;
        else r[i] = st.top();
        st.push(i);
    }

    //求乘积并取最大值
    ll max_digit = 0;
    for(int i = 1; i <= n; i++)
    {
        ll sum = pref[r[i]-1] - pref[l[i]];
        max_digit = max(max_digit, sum*num[i]);
    }

    cout << max_digit;
    return 0;
}