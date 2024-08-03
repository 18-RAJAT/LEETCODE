class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return is_permutation(arr.begin(),arr.end(),target.begin());
    }
};