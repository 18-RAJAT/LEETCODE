class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(auto& it:text)
        {
            if(it=='b')b++;
            else if(it=='a')a++;
            else if(it=='l')l++;
            else if(it=='o')o++;
            else if(it=='n')n++;
        }
        return min({b,a,n,l/2,o/2});
    }
};