class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size(),one=0,sum=0;
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            sum+=one;
            ans.push_back(sum);
            if(boxes[i]=='1')one++;
        }
        one=0,sum=0;
        for(int i=n-1;~i;--i)
        {
            sum+=one;
            ans[i]+=sum;
            if(boxes[i]=='1')one++;
        }
        return ans;
    }
};