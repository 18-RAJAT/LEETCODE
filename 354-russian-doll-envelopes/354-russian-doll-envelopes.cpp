class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
           int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int>&b)
             {
                 if (a[0] < b[0])return true;
                 if (a[0] == b[0])return a[1] > b[1];return false;
             });
            
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++)
        {
            int indx = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if (indx == lis.size())
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                lis[indx] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};