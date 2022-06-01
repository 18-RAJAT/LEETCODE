class Solution {
public:
    int balancedStringSplit(string s) {
        // map<char,char>balanced;
        //     int counter=0;
        //     for(char find : s)
        //     {
        //             balanced[find]++;
        //             if(balanced['R']==balanced['L']){counter++;}
        //     }
        //     return counter;
            
            int result=0;int counter=0;
            for(int i=0;i<s.size();++i)
            {
                    if(s[i]=='R'){counter++;}
                    else{counter--;}
                    
                    if(counter==0){result++;}
            }
            return result;
    }
};