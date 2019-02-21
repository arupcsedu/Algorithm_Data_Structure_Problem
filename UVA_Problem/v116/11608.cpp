#include<bits/stdc++.h>

int main_11608()
{
    int n,arrTP[13],arrAP[13];
    int testCase = 1;
    freopen("11608.txt","rt",stdin);
    while(scanf("%d",&arrTP[0])==1)
    {
        if(arrTP[0]< 0)
            break;

        for(int i = 1;i<=12;i++)
        {
            scanf("%d",&arrTP[i]);
         //   arrTP[i] += bin;
          //  bin = arrTP[i];
        }

        for(int i = 0;i<12;i++)
        {
            scanf("%d",&arrAP[i]);
        }

        printf("Case %d:\n",testCase);
        for(int i = 0;i<12;i++)
        {
            if(arrAP[i] > arrTP[i])
            {
                printf("No problem. :(\n");
                arrTP[i+1] += arrTP[i];
            }
            else
            {
                arrTP[i+1] += (arrTP[i] - arrAP[i]);
                printf("No problem! :D\n");
            }
        }
        testCase++;

    }
    return 0;
}
