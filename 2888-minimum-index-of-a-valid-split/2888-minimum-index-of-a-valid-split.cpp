class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size(),mx=0,cnt=0,ele=0;
        for(int i=0;i<n;++i)
        {
            mp[nums[i]]++;
            if(mx<mp[nums[i]])mx=mp[nums[i]],ele=nums[i],cnt=mx;
        }
        if(2*cnt<=n)
        {
            return -1;
        }
        int window1=0,window2=0;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]==ele)window1++;
            window2=abs<int>(cnt-window1);
            int l=2*window1,r=2*window2;
            if(i+1<l && n-i-1<r)return i;
        }
        return -1;
    }
};