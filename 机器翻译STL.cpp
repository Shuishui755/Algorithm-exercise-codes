//思路分析：利用STL改写代码
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    queue<int> wordsQueue;

    //输入单词
    int word[n];
    for(int i =0; i < n; i++) cin >> word[i];

    //遍历单词进行翻译判断
    int cnt = 0;
    bool isFind[1001] = {0};

    for(int i = 0; i < n; i++)
    {
        if(!isFind[word[i]])
        {
            cnt++;
            wordsQueue.push(word[i]);
            isFind[word[i]] = 1;

            if(wordsQueue.size() > m)
            {
                isFind[wordsQueue.front()] = 0;
                wordsQueue.pop();
            }
        }
    }
    cout << cnt;
    return 0;
}