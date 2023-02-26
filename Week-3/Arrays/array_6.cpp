// gfg https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n) { 
    int freq[n+1] = {0};
    for(int i=0;i<n;i++)
        if(arr[i]>0 && arr[i]<=n)
            freq[arr[i]]++;
    for(int i=1;i<=n;i++)
        if(freq[i] == 0)
            return i;
    return n+1;
}

int main(){
    int arr[] = {0,10,2, -10, -20};
    cout<<missingNumber(arr,5);
    return 0;

}