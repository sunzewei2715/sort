//
//  main.cpp
//  quicksort
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

void quicksort(int *a, int min, int max)
{
    int j=min;
    for(int i=min;i<max;i++)
        if(a[i]<a[max])
        {
            swap(&a[i],&a[j]);
            j++;
        }
    swap(&a[max],&a[j]);
    if(min<j-1) quicksort(a,min,j-1);
    if(j+1<max) quicksort(a,j+1,max);
}

int main()
{
    int n;cin>>n;
    int *a=new int[n+3];
    for(int i=1;i<=n;i++)
        a[i]=rand()%1000;
    quicksort(a,1,n);
    for(int i=1;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}

