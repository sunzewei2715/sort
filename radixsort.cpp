//
//  main.cpp
//  radixsort
//
//  Created by sun zewei on 15-5-22.
//  Copyright (c) 2015年 sun zewei. All rights reserved.
//

#include <iostream>
using namespace std;

int getMaxDigit(int *a, int n, int d)//返回数字位数，如27返回2，4869返回4
{
    int maxDigit=0;
    long dd=1;
    for(int i=1;i<=n;i++)
        while(a[i]>=dd)
        {
            maxDigit++;
            dd*=d;
        }
    return maxDigit;
}

void countingsort(int *a, int n, int d, int pow)
{
    int *c=new int[d+3];
    int *b=new int[n+3];
    int i,t;
    for(i=0;i<d;i++)//c清零
        c[i]=0;
    long radix=1;
    for(i=1;i<pow;i++)
        radix*=d;
    for(i=1;i<=n;i++)
    {
        t=(a[i]/radix)%d;//取第pow位上的数
        c[t]++;//计数
    }
    for(i=1;i<d;i++)
        c[i]+=c[i-1];
    for(i=n;i>=1;i--)
    {
        t=(a[i]/radix)%d;//取第pow位上的数
        b[c[t]]=a[i];
        c[t]--;
    }
    for(i=1;i<=n;i++)
        a[i]=b[i];
    delete []b;
    delete []c;
}


void radixsort(int *a, int n, int d)
{
    int dmax=getMaxDigit(a,n,d);
    for(int i=1;i<=dmax;i++)
        countingsort(a,n,d,i);
}

int main()
{
    int n,d=10;cin>>n;
    int *a=new int[n+3];
    for(int i=1;i<=n;i++)
        a[i]=rand();
    radixsort(a,n,d);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
    return 0;
}