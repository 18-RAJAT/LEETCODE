class Solution {
public:
    double average(vector<int>& salary) {
        auto result = minmax_element(salary.begin(),salary.end());
            
            return(accumulate(salary.begin(),salary.end(),0.) - *result.first-*result.second)/(salary.size()-2);
    }
};