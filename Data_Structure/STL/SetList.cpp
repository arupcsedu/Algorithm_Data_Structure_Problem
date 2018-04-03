//
//  SetList.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/3/18.
//  Copyright © 2018 Arup Sarker. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;
void showSet(set<int, greater<int>> st)
{
    set<int,greater<int>> :: iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
}

void showSet1(set<int, less<int>> st)
{
    set<int,greater<int>> :: iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
}

int main()
{
    set<int, greater<int>> st1;
    for (int i = 1; i<10; i++) {
        st1.insert(i*2);
        st1.insert(i*3);
    }
    cout<<"Show the value of Sets 1: ";
    showSet(st1);
    
    //Assign set1 to set2
    
    set<int,less<int>> st2(st1.begin(),st1.end());
    cout << "\nThe Value of Set 2: ";
    showSet1(st2);
    
    st1.erase(st1.begin(), st1.find(16));
    
    cout<<"\nShow the value of Sets 1 After Erasing: ";
    showSet(st1);
    
    st1.erase(2);
    cout<<"\nShow the value of Sets 1 After Erasing specific value: ";
    showSet(st1);
    
    cout <<"\nLower Bound of 21: " << *st2.lower_bound(21);
    
    cout <<"\nUpper Bound of 21: " << *st2.upper_bound(21);
    
    return 0;
}
