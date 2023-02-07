#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int n; cout<<"Enter size of the array"<<endl; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k; cout<<"Enter search key to find floor of"<<endl; cin>>k;
    if(arr.empty()) {
        cout<<"Array is empty"<<endl;
        return 0;
    }
    if(k < arr[0]) {
        cout<<"Floor not present"<<endl;
        return 0;
    }
    auto i = upper_bound(arr.begin(),arr.end(),k);
    int index = i - arr.begin() - 1;
    cout<<"Floor is present with value: "<<arr[index]<<endl;
    return 0;
}
