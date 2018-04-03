//
//  QueueList.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/3/18.
//  Copyright © 2018 SRBD. All rights reserved.
//

#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

void showQueue(queue<int> qt)
{
    queue<int> qq = qt;
    while (!qq.empty()) {
        cout << qq.front() << " ";
        qq.pop();
    }
}
int main()
{
    queue<int> qt;
    for(int i = 1; i<5;i++)
    {
        qt.push(i*2);
    }
    cout << "Show Queue Elements: ";
    showQueue(qt);
    cout<<"\nSize of Queue: "<<qt.size();
    cout<<"\nFront of Queue: "<<qt.front();
    cout<<"\nBack of Queue: "<<qt.back() << endl;
    
    return 0;
}
