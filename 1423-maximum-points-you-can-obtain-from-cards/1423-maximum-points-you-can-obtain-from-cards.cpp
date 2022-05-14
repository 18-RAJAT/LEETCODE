class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int answer=0;
            int n=cardPoints.size();
            for(int i=0;i<k;++i)
            {
                    answer+=cardPoints[i];
            }
            int answerMax=answer;
            n--;k--;
            
            while(k>=0)
            {
                    answer-=cardPoints[k];
                    answer+=cardPoints[n];
                    answerMax=max(answer,answerMax); 
                    n--;k--;
            }
            return answerMax;
    }
};


