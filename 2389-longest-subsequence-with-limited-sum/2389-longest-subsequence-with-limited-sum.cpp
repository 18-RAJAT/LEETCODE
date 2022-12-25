class Solution {
public:
    vector<int> answerQueries(vector<int>& num, vector<int>& q) {
        vector<int>ans;
        sort(num.begin(),num.end());
        for(int i=1;i<num.size();i++)
        {
            num[i]+=num[i-1];
        }
        
        for(int i=0;i<q.size();i++)
        {
            int ind=upper_bound(num.begin(),num.end(),q[i])-num.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};