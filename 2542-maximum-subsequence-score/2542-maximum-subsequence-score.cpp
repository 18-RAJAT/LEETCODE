class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vp;
        for(int i=0;i<nums1.size();++i)
        {
            vp.push_back(make_pair(nums2[i],nums1[i]));
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        priority_queue<int>pq;
        long long int ans=0;
        long long int sum=0;
        for(int i=0;i<k-1;++i)
        {
            sum+=vp[i].second;
            pq.push(-vp[i].second);
        }
        for(int i=k-1;i<nums1.size();++i)
        {
            sum+=vp[i].second;
            pq.push(-vp[i].second);
            ans=max<long long int>(ans,sum*vp[i].first);
            sum+=pq.top();
            pq.pop();
        }
        return ans;
    }
};