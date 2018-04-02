//
//  VectorTest.cpp
//  SWPractice
//
//  Created by Arup Sarker on 3/30/18.
//  Copyright © 2018 SRBD. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> intList;
    vector<int> :: iterator i;
    vector<int> :: reverse_iterator ir;
    
    for (int j = 0; j < 15; j++) {
        intList.push_back(j);
    }
    cout << "Vector in Forward order" << endl;
    
    for (i = intList.begin(); i != intList.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    
    cout << "Vector in Reverse Order" << endl;
    for (ir = intList.rbegin(); ir != intList.rend(); ir++) {
        cout << *ir << " ";
    }
    cout <<"\n Size: " << intList.size() << endl;
    cout << "\n MAX Size: " << intList.max_size() << endl;
    cout << "\n Capacity: " << intList.capacity() << endl;
    cout << "\n Reference Operator: intList[2] =  " << intList[2] << endl;
    cout << "\n Element at  Position 4: " << intList.at(4);
    cout << "\n Front element of the Vector: " << intList.front() << endl;
    cout << "\n Last Elements of the Vector: " << intList.back() << endl;
    return 0;
}

