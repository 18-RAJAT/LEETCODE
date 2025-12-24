class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int sum=0,ans=0;
        for(auto& it:apple)sum+=it;
        for(int i=capacity.size()-1;~i;--i)
        {
            ans++;
            sum-=capacity[i];
            if(sum<=0)break;
        }
        return ans;
    }
};