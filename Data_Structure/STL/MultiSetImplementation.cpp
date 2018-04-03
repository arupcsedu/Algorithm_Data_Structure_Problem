//
//  MultiSetImplementation.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/3/18.
//  Copyright © 2018 Arup Sarker. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

void showMultiSet(multiset<int, greater<int>> st)
{
    multiset<int, greater<int>>:: iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
}
void showMultiSet2(multiset<int, less<int>> st)
{
    multiset<int, greater<int>>:: iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
}
int main()
{
    multiset<int, greater<int>> st1;
    for(int i = 1; i<10;i++)
    {
        st1.insert(i*2);
        st1.insert(i*3);
    }
    cout << "Show MultiSet: ";
    showMultiSet(st1);
    
    multiset<int, less<int>> st2(st1.begin(), st1.end());
    cout << "\nShow Multiset2: ";
    showMultiSet2(st2);
    st1.erase(st1.begin(),st1.find(15));
    cout << "\nShow after erasing multiset1: ";
    showMultiSet(st1);
    st1.erase(6);
    cout << "\nShow after erasing specific elements: ";
    showMultiSet(st1);
    
    cout << "\nLower bound of 6: " <<*st2.lower_bound(6);
    cout<< "\nUpper Boumd of 6: " << *st2.upper_bound(6);
    return 0;
}
