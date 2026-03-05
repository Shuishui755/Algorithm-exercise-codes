//思路分析：对内存和翻译软件的外存分别用链队列和数组表示，再对翻译软件外存数组遍历进行翻译判断
#include <bits/stdc++.h>
using namespace std;

//定义节点类型
typedef struct node{
    int data;
    struct node *next;
}Qnode, *Queue;

int main()
{
    //确定内存和翻译软件外存容量
    int M, N;
    cin >> M >> N;

    //构建内存链队列
    Queue head, p;
    p = new Qnode;
    p->data = -1;
    p->next = NULL;
    head = p;

    for(int i = 1; i < M; i++)
    {
        Queue current = new Qnode;
        current->data = -1;
        p->next = current;
        p = current;
    }

    p->next = head;

    //构建外存数组
    int word[N];
    for(int i = 0; i < N; i++)
    {
        cin >> word[i];
    }

    //遍历数组进行判断翻译
    Queue front = head;
    Queue rear = head;  //将链表转成队列
    int size = 0;   //内存实际大小
    int count = 0;

    //开始遍历
    for(int i = 0; i < N; i++)
    {
        Queue now = front;
        bool isFind = false;

        for(int j = 0; j < size; j++)
        {
            if(now->data == word[i])
            {
                isFind = true;
                break;
            }
            now = now->next;
        }

        if(!isFind)
        {
            count++;
            
            if(size == M)
            {
                front = front->next;
                size--;
            }
            if(size == 0)
            {
                rear->data = word[i];
                size = 1;
            }
            else
            {
                rear = rear->next;
                rear->data = word[i];
                size++;
            }
        }
    }

    cout << count << endl;
    return 0;
}