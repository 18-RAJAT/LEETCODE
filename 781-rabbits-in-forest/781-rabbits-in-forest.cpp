class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int answer=0;
            vector<int>count(1000);
            for(auto it:answers)
            {
                    if(count[it]%(it+1)==0)
                            answer=answer+it+1;
                    ++count[it];
            }
            return answer;
    }
};