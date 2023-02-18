// gfg - huffman encoding
#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class cmp{
    public:
        bool operator()(Node *a,Node *b) {
            return a->data > b->data;
        }
};

class Solution
{
	public:
		void traverse(Node *root,string temp,vector<string> &ans) {
	        if(root->left == NULL && root->right == NULL) {
	            ans.push_back(temp);
	            return;
	        }
	        traverse(root->left,temp+"0",ans);
	        traverse(root->right,temp+"1",ans);
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,cmp> pq;
		    for(int i=0;i<N;i++)
		        pq.push(new Node(f[i]));
		        
		    while(pq.size() > 1) {
		        Node *left = pq.top(); pq.pop();
		        Node *right = pq.top(); pq.pop();
		        Node *temp = new Node(left->data + right->data);
		        temp->left = left;
		        temp->right = right;
		        pq.push(temp);
		    }
		    
		    Node *root = pq.top();
		    vector<string> ans;
		    string temp = "";
		    traverse(root,temp,ans);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends