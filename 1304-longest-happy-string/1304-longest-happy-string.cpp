class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        while(!pq.empty())
        {
            auto[cnt1,c1]=pq.top();
            pq.pop();
            if(ans.size()>=2 && ans.back()==c1 && ans[ans.size()-2]==c1 && c1!=0)
            {
                if(pq.empty()) break;
                auto[cnt2,c2]=pq.top();
                pq.pop();
                ans+=c2;
                if(--cnt2>0)pq.push({cnt2,c2});
                pq.push({cnt1,c1});
            }
            else
            {
                ans+=c1;
                if(--cnt1>0)pq.push({cnt1,c1});
            }
        }
        return ans;
    }
};