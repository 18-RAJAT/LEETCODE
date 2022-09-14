class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int temp=0;
        for(auto &it:operations)
        {
            if(it=="++X" or it=="X++")temp++;
            else temp--;
        }
        return temp;
    }
};