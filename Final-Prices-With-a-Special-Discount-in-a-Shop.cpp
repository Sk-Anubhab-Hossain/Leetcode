class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> res;
        stack<int> st;
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            int val= prices[i];
            if(!st.empty()){
                val= prices[i]-st.top();
            }
            res.push_back(val);
            st.push(prices[i]);
        }
        reverse(res.begin(), res.end());
        return res;
            
    }
};