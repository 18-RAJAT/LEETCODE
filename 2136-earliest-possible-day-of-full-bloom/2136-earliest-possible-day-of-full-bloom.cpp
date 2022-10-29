class Solution {
public:
    //pt=plantTime
    //gt=growTime
    int earliestFullBloom(vector<int>& pt,vector<int>& gt) {
        // sort(pt.begin(),pt.end());
        // sort(gt.begin(),gt.end());
        int n=pt.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;++i)

        v.push_back(make_pair(gt[i],pt[i]));
        sort(v.begin(),v.end());
            
        int answer=0;
        for(int i=0;i<n;++i)
        {
            answer=max(answer,v[i].first);
            answer+=v[i].second;
        }
        // cout<<answer<<"\n";
        return answer;
    }
};