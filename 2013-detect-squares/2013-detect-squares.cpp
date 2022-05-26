class DetectSquares {
public:
        map<pair<int,int>,int>mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
            int answer=0;
            for(auto it:mp)
            {
                    pair<int,int>p=it.first;
                    if(p.first!=point[0] and p.second!=point[1] and (abs(point[0]-p.first)==abs(point[1]-p.second)))
                    {
                            int f=mp[{p.first,p.second}];
                            int s=mp[{p.first,point[1]}];
                            int t=mp[{point[0],p.second}];
                            
                            int current=f*s*t;
                            answer=answer+current;
                    }
            }
        return answer;
    }
};