class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>result;
            int numbers=1,sizeTarget=0;
            while(numbers<=n)
            {
                    if(sizeTarget==target.size())break;
                    if(numbers==target[sizeTarget])
                    {
                            result.push_back("Push");numbers++;sizeTarget++;
                    }
                    else
                    {
                            result.push_back("Push");
                            result.push_back("Pop");
                            numbers++;
                    }
            }
            return result;
    }
};
