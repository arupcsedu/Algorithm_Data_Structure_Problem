#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main()
{
    int n;
    freopen("11995.txt", "rt",stdin);
    while(scanf("%d",&n) != EOF)
    {
        int a,b;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        bool isStack = true;
        bool isQueue = true;
        bool isPriorityQueue = true;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&a, &b);
            if(a == 1)
            {
                if(isStack){
                    s.push(b);
                }
                if(isQueue){
                    q.push(b);
                }
                 if(isPriorityQueue){
                    pq.push(b);
                }
            }
            else
            {

                if(isQueue)
                {
                    int x = q.front();
                    if(q.empty() || x != b)
                        isQueue = false;
                    else
                        q.pop();
                }

                if(isStack)
                {
                    int x = s.top();
                    if(s.empty() || x != b)
                        isStack = false;
                    else
                        s.pop();
                }

                if(isPriorityQueue)
                {
                    int x = pq.top();
                    if(pq.empty() || x != b)
                        isPriorityQueue = false;
                    else
                        pq.pop();
                }

            }
        }
        if(isQueue == true && isStack == false && isPriorityQueue == false)
            printf("queue\n");
        else if(isQueue == false && isStack == true && isPriorityQueue == false)
            printf("stack\n");
        else if(isQueue == false && isStack == false && isPriorityQueue == true)
            printf("priority queue\n");
        else if(isQueue == false && isStack == false && isPriorityQueue == false)
            printf("impossible\n");
        else
            printf("not sure\n");
    }
    return 0;
}
