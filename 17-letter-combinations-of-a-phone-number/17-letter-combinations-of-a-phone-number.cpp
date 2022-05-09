class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        //No digits are avaliable then this case will be works on...!!
        if(digits == "")
        {
            return {};
        }
        
        string operation = "";
            
        vector<string>result;
        
        ans(digits,operation,result);
        
        return result;
        
    }
    
    void ans(string digits,string operation,vector<string>& result)
    {
        //Possible combinations...!!
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.size() == 0)
        {
            result.push_back(operation);
            return;
        }
        
        string s = v[digits[0] - '0'];
        
        digits.erase(digits.begin() + 0);
        
        for(int i=0;i<s.length();++i)
        {
            ans(digits,operation+s[i],result);
        }
    }
};