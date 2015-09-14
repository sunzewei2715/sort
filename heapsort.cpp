//
//  main.cpp
//  heapsort
//
//  Created by sun zewei on 15-5-21.
//  Copyright (c) 2015年 sun zewei. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void shiftDown(int *a, int n, int i)//下滑
{
    int larger;
    if(2*i<=n && a[2*i]>a[i])
        larger=2*i;
    else larger=i;
    if(2*i+1<=n && a[2*i+1]>a[larger])
        larger=2*i+1;
    if(larger!=i)
    {
        swap(&a[i],&a[larger]);
        shiftDown(a,n,larger);
    }
}

void buildHeap(int *a, int n)//建堆
{
    for(int i=n/2;i>=1;i--)
        shiftDown(a,n,i);
}

void sort(int *a, int n)
{
    for(int i=n;i>1;i--)
    {
        swap(&a[1],&a[n]);
        n--;
        shiftDown(a,n,1);
    }
}

int main()
{
    int n;cin>>n;
    int *a=new int[n+3];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    buildHeap(a,n);
    sort(a,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}

