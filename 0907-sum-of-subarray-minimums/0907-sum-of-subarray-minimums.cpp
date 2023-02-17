class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>ele;
        int res=0;
        for(int i=0;i<arr.size()+1;++i)
        {
            while(ele.size() and ((i==arr.size()) or (arr[ele.back()]>=arr[i])))
            {
                int mid=ele.back();
                ele.pop_back();
                int lft=ele.size()?ele.back():-1;
                int ryt=i;
                long cnt=(mid-lft)*(ryt-mid)%1000000007;
                res+=(arr[mid]*cnt)%1000000007;
                res%=1000000007;
            }
            ele.push_back(i);
        }
        return res%1000000007;
    }
};