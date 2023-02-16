// gfg union
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {

        unordered_map<int,bool> mp;
        int count =0;
        for(int i=0; i<n; i++)
        {
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = true;
                count++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (mp.find(b[i]) == mp.end()) {
                mp[b[i]] = true;
                count++;
            }
        }
    return count;
        
    }
};


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
