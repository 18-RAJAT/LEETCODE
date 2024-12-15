class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        if(!classes.size())return 0;
		priority_queue<pair<double,pair<int,int>>>pq;
		for(auto& c:classes)
        {
            double ele=((double)(c[0])+1)/((double)(c[1])+1);
            double pos=(double)(c[0])/(double)(c[1]);
            pq.push({ele-pos,{c[0],c[1]}});
        }
        double sza=pq.size();
        while(extraStudents>0)
        {
            auto T=pq.top();
            pq.pop();
            
            double ele=((double)(T.second.first)+2)/((double)(T.second.second)+2);
            double pos=(double)(T.second.first+1)/(double)(T.second.second+1);
            pq.push({ele-pos,{T.second.first+1,T.second.second+1}});

            extraStudents--;   
        }
        double avg=0.0;
        while(!pq.empty())
        {
            auto T=pq.top();
            pq.pop();
            avg+=(double)T.second.first/(double)T.second.second;
        }
        return avg/sza;
    }
};