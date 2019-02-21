#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


bool CMP10905(string a,string b)
{
	return (a+b>b+a);
}

int main()
{
    int n;
    string strGame[101];
    freopen("10905.txt", "rt", stdin);
    while(scanf("%d",&n) == 1)
    {
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
        {
            cin >> strGame[i];
        }
        sort(strGame, strGame+n,CMP10905);
        for(int i = 0; i < n; i++)
        {
            cout << strGame[i];
        }
        printf("\n");
    }
    return 0;
}
