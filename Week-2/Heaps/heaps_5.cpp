// GFG - Rearrange characters in a string such that no two adjacent are same
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string rearrangeString(string str)
    {
        int n = str.size();
        vector<int> freq(26, 0);
        for(char ch : str){
            freq[ch - 'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                pq.push({freq[i],i+'a'});
            }
        }
        if(pq.size() ==1) return "0";
        string res = "";
        pair<int,char> prev = {-1,'*'};
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            res+= curr.second;
            if(prev.first>0)
            {
                pq.push(prev);
            }
            curr.first--;
            prev = curr;
        }
        if(n!= res.size())
        {
            return "0";
        }
        return res;
    }
};

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}