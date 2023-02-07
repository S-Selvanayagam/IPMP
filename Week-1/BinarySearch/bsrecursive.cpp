#include<iostream>
using namespace std;


int binarysearch(int arr[], int l, int r, int k)
{
    int mid = l + (r-l)/2;
    if (r >= l) {
        if (arr[mid] == k) {
            cout<<"element is found at index"<<mid<<endl;
            return mid;
        }
        if (arr[mid] > k) {
            return binarysearch(arr, l, mid-1, k);
        }
        else {
            return binarysearch(arr, mid+1, r, k);
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter element to be searched"<<endl;
    cin>>k;
    int flag = binarysearch(arr,0,n-1,k);
    if (flag == -1) cout<<"element not found"<<endl;
    return 0;
}

//time complexity - O(log n)
//space complexity - O(log n)
