class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        
        for(int i=1; i<n; i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }
        
        vector<int> ans;
        
        for(auto q : queries) {
            int L = q[0];
            int R = q[1];
            
            int sum;
            
            if(L>0) {
                sum = prefix[R] - prefix[L-1];
            } else {
                sum = prefix[R];
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};