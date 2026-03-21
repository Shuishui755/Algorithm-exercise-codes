//洛谷P3378
//思路分析：题目不是太复杂并且为了方便管理内存，使用数组构建一个静态堆，根据输入的op判断入堆出堆
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int heap[N], len=0;

//定义入堆（上浮）方法
void push(int num)
{
    heap[++len] = num; //入堆底
    int i = len;
    while(i > 1)
    {
        if(heap[i/2] > heap[i]) swap(heap[i/2], heap[i]);   //根节点更大，则上浮
        i /= 2;
    }
}

//定义出堆（下沉）方法
void pop()
{
    heap[1] = heap[len--];  //堆底元素上提至根节点
    int i = 1;
    while(2 * i <= len)
    {
        int child = 2 * i;    //定义左孩子节点
        if(child < len && heap[child+1] < heap[child]) child++;    //如果有右孩子，需要比较

        if(heap[i] > heap[child])
        {
            swap(heap[i], heap[child]);
            i = child;
        }
        else break; //已经是最小，不需要下沉
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int num;
            cin >> num;
            push(num);
        }
        else if(op == 2) cout << heap[1] << '\n';
        else pop();
    }
}

