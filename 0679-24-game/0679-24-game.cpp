class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>arr(4);
        for(int i=0;i<4;++i)arr[i]=cards[i];
        stack<vector<double>>st;
        st.push(arr);
        while(!st.empty())
        {
            auto cards=st.top();
            st.pop();
            if(cards.size()==1)
            {
                if(fabs(cards[0]-24)<1e-3)return true;
                continue;
            }
            int n=cards.size();
            for(int i=0;i<n;++i)
            {
                for(int j=i+1;j<n;++j)
                {
                    vector<double>ret;
                    for(int k=0;k<n;++k)
                    {
                        if(i!=j && k!=i && k!=j)ret.push_back(cards[k]);
                    }
                    double a=cards[i],b=cards[j];
                    vector<double>check={a+b,a-b,b-a,a*b};
                    if(fabs(b)>1e-6)check.push_back(a/b);
                    if(fabs(a)>1e-6)check.push_back(b/a);
                    for(auto& it:check)
                    {
                        ret.push_back(it);
                        st.push(ret);
                        ret.pop_back();
                    }
                }
            }
        }
        return false;
    }
};