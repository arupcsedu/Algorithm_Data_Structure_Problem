//
//  FWList.cpp
//  SWPractice
//
//  Created by Arup Sarker on 4/2/18.
//  Copyright © 2018 SRBD. All rights reserved.
//

#include <iostream>
#include <forward_list>

using namespace std;

void showFList(forward_list<int> fList)
{
    forward_list<int> :: iterator it;
    for(it = fList.begin(); it != fList.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    forward_list<int> fList;
    forward_list<int>:: iterator it;
    for(int i = 1; i<10;i++)
    {
        fList.push_front(i*2);
    }
    //Show Forward List
    cout << "Show Forward List: ";
    showFList(fList);
    fList.assign({1,2,3,4});
    cout<< "\nShow After Assign function: ";
    showFList(fList);
    fList.emplace_front(70);
    cout<< "\nShow After Emplace Front Function: ";
    showFList(fList);
    
    cout << "\nShow After insert After: ";
    it = fList.insert_after(fList.begin(), {2,4,6});
    for (int &c: fList) {
        cout << c << " ";
    }
    
    cout << "\nShow value of emplace After: ";
    it = fList.emplace_after(it, 15);
    for (int &c:  fList) {
        cout << c << " ";
    }
    
    cout << "\nShow value erase After: ";
    it = fList.erase_after(it);
    for (int &c:  fList) {
        cout << c << " ";
    }
    
    cout << "\nShow Value After Using Remove: ";
    fList.remove(4);
    for (int &c:  fList) {
        cout << c << " ";
    }
    
    cout << "\n Show Value After Using Remove If: ";
    fList.remove_if([](int x){return x == 2;});
    for(int &c : fList)
    {
        cout << c << " ";
    }
    forward_list<int> fList1;
    fList1.assign( {2,0,3});
    fList.splice_after(fList.begin(), fList1);
    cout<<"\nShow Value After Splice After";
    for(int &c: fList)
    {
        cout<< c << " ";
    }
    return 0;
}
