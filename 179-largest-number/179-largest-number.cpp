bool compare(string a,string b)
{
        return a+b>b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
         vector<string>answer;
            for(int i=0;i<nums.size();++i){answer.push_back(to_string(nums[i]));}
         sort(answer.begin(),answer.end(),compare);
          
           string result;
        for(auto i:answer){
            result=result+i;
        }
        if(result[0]=='0'){
            return "0";
        }
            return result;
    }
};
