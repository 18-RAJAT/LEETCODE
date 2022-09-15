class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n=changed.size();
        vector<int>result;
        
        for(int i=0;i<n;++i)
        {
            int value=changed[i];
            if(value<0)continue;
            
            auto idx=lower_bound(changed.begin()+i+1,changed.end(),2*value);
            if(idx!=changed.end() and *idx==2*value)
            {
                *idx=-1;//mark
                result.push_back(value);
            }
            else
            {
                return {};
            }
        }
        return result;
    }
};