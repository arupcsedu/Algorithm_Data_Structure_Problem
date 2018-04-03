//
//  MapImplementation.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/3/18.
//  Copyright © 2018 Arup Sarker. All rights reserved.
//

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void showMap(map<int, int> mt)
{
    map<int, int> :: iterator it;
    cout <<"Key\tVal\n";
    for (it = mt.begin(); it != mt.end(); it++) {
        cout <<it->first << "\t" <<it->second << endl;
    }
}
int main()
{
    map<int, int> mt;
    for (int i = 1; i < 10; i++) {
        mt.insert(pair<int, int>(i, i*2));
    }
    cout << "Show Map Table:\n";
    showMap(mt);
    map<int, int> mt1(mt.begin(), mt.end());
    
    cout << "Show Second Map Table:\n";
    showMap(mt1);
    mt1.erase(mt1.begin(), mt1.find(4));
    
    cout << "Show Second Map Table After Erasing:\n";
    showMap(mt1);
    
    mt1.erase(4);
    cout<<"Show Map Table after erasing specific key:\n";
    showMap(mt1);
    
    cout<<"Lower bound of Map1: \nKey\tVal\n";
    cout<< mt.lower_bound(4)->first <<"\t"<<mt.lower_bound(4)->second;
    cout <<"\nUpper Bound of Map1: \nKey\tVal\n";
    cout<<mt.upper_bound(4)->first <<"\t"<<mt.upper_bound(4)->second<<endl;
    
    return 0;
}
