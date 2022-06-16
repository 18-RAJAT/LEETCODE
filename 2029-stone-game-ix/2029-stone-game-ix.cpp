class Solution {
public:
    bool stoneGameIX(vector<int>& s) {
          vector<int>a(3,0);
          for(auto v:s)
          ++a[v%3];
          if(a[0]%2){return abs(a[1]-a[2])>2;}
          
            return a[1]!=0 and a[2]!=0;
    }
};

