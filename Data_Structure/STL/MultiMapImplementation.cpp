//
//  MultiMapImplementation.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/3/18.
//  Copyright © 2018 Arup Sarker. All rights reserved.
//

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void showMultiMap(multimap<int, int> mmt)
{
    cout << "Key\tVal\n";
    multimap<int, int> :: iterator it;
    for (it = mmt.begin(); it != mmt.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
}
int main()
{
    multimap<int, int> mmt;
    for (int i = 1; i < 10; i++) {
        mmt.insert(pair<int, int>(i, i*2));
        mmt.insert(pair<int, int>(i*2, i*3));
    }
    cout << "Show MultiMap:\n";
    showMultiMap(mmt);
    
    multimap<int, int> mmt1(mmt.begin(), mmt.end());
    cout<<"\nShow Second MultiMap:\n";
    showMultiMap(mmt1);
    mmt1.erase(4);
    cout<<"\nShow Second MultiMap after erasing specific elements:\n";
    showMultiMap(mmt1);
    mmt1.erase(mmt1.begin(), mmt1.find(10));
    cout<<"\nShow Second MultiMap after erasing group of elements:\n";
    showMultiMap(mmt1);
    cout <<"\nLower Bound of Multimap:\nKey\tVal\n"<<mmt.lower_bound(6)->first<<"\t" << mmt.lower_bound(6)->second<<endl;
    cout<<"\nUpper Bound of Multimap:\nKey\tVal\n"<<mmt.upper_bound(6)->first<<"\t" <<mmt.upper_bound(6)->second<<endl;
    return 0;
}
