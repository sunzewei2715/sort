//
//  main.cpp
//  countingsort
//
//  Created by sun zewei on 15-5-22.
//  Copyright (c) 2015年 sun zewei. All rights reserved.
//

#include <iostream>
using namespace std;

void countingsort(int *a, int n, int k)
{
    int *c=new int[k+3];
    int *b=new int[n+3];
    int i;
    for(i=0;i<k;i++)
        c[i]=0;
    for(i=1;i<=n;i++)
        c[a[i]]++;//计数
    for(i=1;i<k;i++)
        c[i]+=c[i-1];//c[i]表示不大于i的个数
    for(i=n;i>=1;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    for(i=1;i<=n;i++)
        a[i]=b[i];
}

int main()
{
    int n,k;cin>>n>>k;
    int *a=new int[n+3];
    for(int i=1;i<=n;i++)
        a[i]=rand()%k;
    countingsort(a,n,k);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
    return 0;
}

