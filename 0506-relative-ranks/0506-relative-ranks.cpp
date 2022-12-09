class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({score[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans[v[i].second]="Gold Medal";
            }
            else if(i==1)
            {
                ans[v[i].second]="Silver Medal";
            }
            else if(i==2)
            {
                ans[v[i].second]="Bronze Medal";
            }
            else
            {
                ans[v[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
};