//
//  ListTest.cpp
//  SWPractice
//
//  Created by Arup Sarker on 3/30/18.
//  Copyright © 2018 SRBD. All rights reserved.
//

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void showList(list<int> l1)
{
    list<int> :: iterator i;
    for (i = l1.begin(); i != l1.end(); i++) {
        cout << *i << " ";
    }
}

int main()
{
    list<int> intList1, intList2;
    for(int i = 1; i<10;i++)
    {
        intList1.push_back(i*2);
        intList2.push_front(i*3);
    }
    cout << "Show list one back push:\n";
    showList(intList1);
    cout << "\nShow list one front push:\n";
    showList(intList2);
    cout << endl;
    cout << "\n Size of List1 : " << intList1.size()<< endl;
    cout << "\n Max size of List2: " << intList2.max_size() << endl;
    cout << "\n Front Elements of List2: " << intList2.front() << endl;
    cout << "\n Back Elements of List1: " << intList1.back() << endl;
    intList1.reverse();
    cout << "\n Show List1 after reversing:\n";
    showList(intList1);
    cout << "\nShow List2 After sorting it:\n";
    intList2.sort();
    showList(intList2);
    cout << endl;
    return 0;
}
