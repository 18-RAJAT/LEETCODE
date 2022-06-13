class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
            vector<int>answer;
            map<int,int>m1;
            map<int,int>m2;
            int temp=0;
            
            for(auto x : nums1){m1[x]++;}
            for(auto x : nums2){m2[x]++;}
            for(auto x : m1)
            {
                    temp=min(x.second,m2[x.first]);
                    if(temp>0){answer.push_back(x.first);}
            }
            return answer;
    }
};