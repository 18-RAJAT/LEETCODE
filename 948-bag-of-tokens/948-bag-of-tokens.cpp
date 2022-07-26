class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int current=0;
        int i=0,j=tokens.size()-1;
        while(i<=j)
      {
            if(power>=tokens[i])
         {
            power=power-tokens[i];i++;current++;
         }
            else if(current>=1 and i!=j)
         {
            power=power+tokens[j];j--;current--;
         }
            else{break;}
       }
        int result=max(0,current);
        return result;
    }
};