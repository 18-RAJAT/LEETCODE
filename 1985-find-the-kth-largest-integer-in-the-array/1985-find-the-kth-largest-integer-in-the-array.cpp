class Solution {
public:
    //sort the number decresing order
      static bool cmp(const string& a, const string& b) {
        if(a.length()==b.length()) return a>b;
        else return a.length()>b.length();
    }
    string kthLargestNumber(vector<string>& nums,int k) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[k-1];
    }
};