// gfg - next prime palindrome
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		
		bool ispalindrome(int n)
	    {
	        int num = n;
	        int ans=0;
	        
	        while(num>0)
	        {
	            ans = ans*10+num%10;
	            num = num/10;
	        }
	        return n==ans;
	    }
	    
	    bool isprime(int n)
	    {
	        if(n<2) return false;
	        
	        for(int i=2;i<=sqrt(n);i++)
	        {
	            if(n%i==0) return false;
	        }
	        return true;
	    }
	
		int PrimePalindrome(int N)
		{
		    int c = N;
		    while(c>=N)
		    {
		        if(ispalindrome(c) && isprime(c)) return c;
		        c++;
		    }	    
		}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.PrimePalindrome(N);
		cout << ans << "\n";
	}
	return 0;
}