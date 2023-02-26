// Problem: Minimum row with maximum number of 1s

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {
        int mincount = INT_MAX, minindex = -1;
        for(int i=0; i<N; i++)
        {
            int count =0;
            for(int j=0; j<M ; j++)
            {
                if( A[i][j] == 1) count ++;
            }
            if(count < mincount)
            {
                mincount = count;
                minindex = i+1;
            }
        }
        return minindex;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
