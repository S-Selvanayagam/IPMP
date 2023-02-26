// Problem: Given an array A[] and a number x, check for pair in A[] with sum as x
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        int l,r;
        for(int i=0;i<n-2;i++)
        {
            l = i+1;
            r = n-1;
            while(l<r){
                if(A[i] + A[l]+ A[r] == X) return true;
                else if (A[i] + A[l] + A[r] > X) r --;
                else l++;
            }
        }
        return false;
    }

};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
