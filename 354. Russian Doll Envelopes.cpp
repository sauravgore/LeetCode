/*

354. Russian Doll Envelopes
Hard

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 
Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 10^5
envelopes[i].length == 2
1 <= wi, hi <= 10^5

*/

// Time Complexity -> O(nlogn), Space Complexity -> O(n)

bool comp(const pair<int, int> &x, const pair<int, int> &y) {
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}

class Solution {
public:
     void solveLOGN(vector<int> &A, vector<int> &dp, int i, map<int,int> &m) {
        map<int,int>::iterator itr = m.upper_bound(A[i]);
        if(itr != m.end())
            dp[i] = itr->second + 1;
        else 
            dp[i] = 1;
        m[A[i]] = dp[i];
        map<int,int>::iterator it = m.lower_bound(A[i]);
        if(it != m.begin() && it->second >= prev(it)->second)
            m.erase(prev(it));
    }

    int findLIS(vector<int> &A) {
        int last = 10000;
        vector<int> dp(A.size()+1,0);
        map<int,int> m;
        int res = 1;
        for(int i = A.size()-1; i >= 0; i--) {
            solveLOGN(A, dp, i, m);
            res = max(res, dp[i]);
        }
        return res;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int> > pr;
        for (int i = 0; i < n; i++)
            pr.push_back({envelopes[i][0], envelopes[i][1]});
        sort(pr.begin(), pr.end(), comp);
        vector<int> A;
        for (int i = 0; i < pr.size(); i++)
            A.push_back(pr[i].second);
        return findLIS(A);
    }
};
