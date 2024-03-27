class Solution {
public:
    bool xorGame(vector<int>& nums){
        int n=nums.size();
        int Xor=0;
        for(int i=0;i<n;++i)
        {
            Xor^=nums[i];
        }
        return (Xor==0 || n%2==0)?true:false;
    }
};