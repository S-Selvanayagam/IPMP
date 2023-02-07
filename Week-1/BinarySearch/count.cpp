// Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.

#include<iostream>
#include<vector>
using namespace std;

int firstoccurence(vector<int> nums, int key)
{
    int left =0; int right = nums.size(); int result = -1;
    while(left<=right)
    {
        int mid = left + (right -left)/2;
        if(nums[mid] < key) {left = mid+1;}
        else if(nums[mid] > key) {right = mid-1;}
        else{
            result = mid;
            right = mid-1;
        }
    }
    return result;
}

int lastoccurence(vector<int> nums, int key)
{
    int left =0; int right = nums.size(); int result = -1;
    while(left<=right)
    {
        int mid = left + (right -left)/2;
        if(nums[mid] < key) {left = mid+1;}
        else if(nums[mid] > key) {right = mid-1;}
        else{
            result = mid;
            left = mid+1;
        }
    }
    return result;
}

int noofoccurences(vector<int>nums, int key)
{
    int first = firstoccurence(nums,key);
    int last =  lastoccurence(nums,key);

    if(first==-1 || last ==-1)
    {
        return 0;
    }

    return last-first+1;
}

int main()
{
    int n,k;
    cin>>n;
    cout<<"elements of the array"<<endl;
    vector<int> arr;
    for(int i=0; i<n;i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }
    cout<<"search key: "<<endl;
    cin>>k;
    int ans = noofoccurences(arr,k);
    cout<<ans<<endl;
    return 0;
}