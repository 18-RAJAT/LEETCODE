class Solution {
public:
    void recur(vector<int>& result,int n,int nums)
    {
        if(n<nums)return;
        result.push_back(nums);
        recur(result,n,nums*10);
        if(nums%10!=9)recur(result,n,nums+1);
    }
    vector<int>lexicalOrder(int n)
    {
        vector<int> result;
        recur(result,n,1);
        return result;
    }
};