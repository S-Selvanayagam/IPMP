// GFG - Search in a Rotated Array
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(A[mid]==key) {return mid;}
            if(A[mid]>=A[l]) 
            {
                if(A[l] <= key && key <= A[mid]) h = mid-1;
                else l = mid+1;
            }
            else{
                if(A[mid]<=key && key <= A[h]) l = mid+1;
                else h = mid -1;
            }
            
        }
        return -1;        
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
