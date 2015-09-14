//
//  main.cpp
//  mergesort
//
//  Created by sun zewei on 15-5-21.
//  Copyright (c) 2015年 sun zewei. All rights reserved.
//

#include <iostream>
using namespace std;

void fix(int min, int max, int mid, int *a, int *b)
{
    int i=min,j=mid+1,k=min;
    while(i<=mid && j<=max)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=max) b[k++]=a[j++];
    for(i=min;i<=max;i++)
        a[i]=b[i];
    return;

}

void merge(int min, int max, int *a, int *b)
{
    int t=(min+max)/2;
    if(min<t) merge(min,t,a,b);
    if(t+1<max) merge(t+1,max,a,b);
    if(min<max) fix(min,max,t,a,b);
    return;
}

int main()
{
    int i,n,*a,*b;
    cin>>n;
    a=new int[n+3];
    b=new int[n+3];
    for(i=1;i<=n;i++)
        cin>>a[i];
    merge(1,n,a,b);
    for(i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}

