class Solution {
public:
vector<int>ans;
    void help(int ind, int n ,int k, string& s){
        
        if(n==0) {
            ans.push_back(stoi(s));
            return;
        }
        
        if(ind+k<=9) {
             s+= to_string(ind+k);
             help(ind+k,n-1,k,s);
             s.pop_back();
        }
        //k=0 means add subtract will be same so neglect that
        if(ind-k>=0 && k!=0){
            s+= to_string(ind-k);
            help(ind-k,n-1,k,s);
            s.pop_back();
        }
        
          return;
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++){
            string s= to_string(i);
            help(i,n-1,k,s);
          
        }
          return ans;
        
    }
};