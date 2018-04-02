/*
 * File Name: DqueTest.cpp
 * Author Name: Arup Kumar Sarker
 * Description: STL: Deque Implementation
 * url: https://www.geeksforgeeks.org/deque-cpp-stl/ 
 */
#include<iostream>
#include<deque>

using namespace std;

void showDeque(deque<int> dq)
{
    deque<int>::iterator it;
    for(it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    deque<int> dq;
    for(int i = 1; i<10;i++)
    {
        dq.push_back(i*2);
    }
    cout << "Show Deque List : ";
    showDeque(dq);
    cout << "Front of the deque : " << dq.front() << endl;
    cout << "Back of the Deque : " << dq.back() << endl;
    
    for(int i = 1; i<5;i++)
        dq.push_front(i*3);
    
    cout << "Show Deque after add push front : ";
    showDeque(dq);
    return 0;
}
