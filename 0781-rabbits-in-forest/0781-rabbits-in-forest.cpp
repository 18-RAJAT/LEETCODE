class Solution {
public:
    int numRabbits(vector<int>& answers) {
        array<float,1005>mp;
        int n=answers.size();
        for(int i=0;i<n;++i)
        {
            mp[answers[i]]++;
        }
        int ans=0;
        for(int i=0;i<1005;++i)
        {
            ans+=(ceil(mp[i]/(i+1))*(i+1));
        }
        return ans;
    }
};