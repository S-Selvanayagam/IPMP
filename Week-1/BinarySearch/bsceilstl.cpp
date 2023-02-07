#include<iostream>
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
    int k; cout<<"Enter search key to find ceil of"<<endl; cin>>k;
    auto i = lower_bound(arr.begin(),arr.end(),k);             // we want first occurence of values not less than k
    int index = i - arr.begin();
    if(arr.empty()) {
        cout<<"Array is empty"<<endl;
        return 0;
    }
    if(index == n) {cout<<"no ceil is present"<<endl;}
    else{
        cout<<"Ceil is present in index"<<index<<endl;
    }
    return 0;
}