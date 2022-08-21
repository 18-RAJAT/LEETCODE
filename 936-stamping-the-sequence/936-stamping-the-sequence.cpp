class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int s=stamp.size(),t=target.size();
        int count=0;
        vector<int>ans;
        bool isSafe=true;
        while(isSafe){
            isSafe=false;
            for(int i=0;i<=t-s;i++){
                bool notMatch=true;
                int dot=0;
                for(int j=0;j<s;j++){
                    if(target[i+j]=='.'){
                        dot++;
                    }
                    if(target[i+j]!='.'&&target[i+j]!=stamp[j]){
                        notMatch=false;
                        break;
                    }
                }
                if(dot<s&&notMatch){
                    ans.push_back(i);
                    isSafe=true;
                    for(int j=0;j<s;j++){
                        target[i+j]='.';
                    }
                }
            }
        }
        for(int i=0;i<t;i++){
            if(target[i]!='.'){
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};