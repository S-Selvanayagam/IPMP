// the best way in O(n) time and constant space is to do xor operation - x^x =0 hence we get only the odd element left -> x^0 = x hence best way.
//GFG - Find Single
#include<bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
    int findSingle(int N, int arr[]){
        int res=0;
        for(int i=0;i<N;i++)
        {
            res = res ^ arr[i];
        }
        return res;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
