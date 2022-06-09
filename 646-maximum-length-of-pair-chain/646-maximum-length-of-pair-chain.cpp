bool compare(vector<int>& a ,vector<int>& b)
{
        return a[1]<b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
            int answer=0;
            int prev=INT_MIN;
            sort(pairs.begin(),pairs.end(),compare);
            for(auto & pair : pairs)
            {
                  if(pair[0]>prev)
                  {
                    answer++;prev++;
                    prev=pair[1];
                  }
            }
            return answer;
    }
};