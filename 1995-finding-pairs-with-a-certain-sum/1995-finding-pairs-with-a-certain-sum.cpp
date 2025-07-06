class FindSumPairs {
    unordered_map<int,int>mp;
    vector<int>nums1,nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto& it:nums2)mp[it]++;
        this->nums1=nums1;
        this->nums2=nums2;
    }
    
    void add(int index, int val)
    {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int x)
    {
        int count=0;
        for(auto& it:nums1)count+=mp[x-it];
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */