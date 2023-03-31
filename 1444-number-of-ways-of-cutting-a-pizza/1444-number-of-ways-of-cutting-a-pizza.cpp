class Solution {
public:
    map<string,int>mp;
    bool isvalid(vector<string>&pizza,int rs,int r,int cs,int cp)
    {
    for(int p=rs;p<=r;p++){
      for(int i=cs;i<=cp;i++){
          if(pizza[p][i]=='A')
          return true;
     }
    }
    return false;
    }
    int dfs(vector<string>& pizza,int k,int rs,int r,int cs,int s){
    string i="";
    i=i+to_string(k)+" "+to_string(rs)+" "+to_string(r)+" "+to_string(cs)+" "+to_string(s);  
    if(mp.count(i)>0)
         return mp[i];
    if(k==0)
         return mp[i]=1;
    if(rs>r||cs>s||k<0)
         return mp[i]=0;
    int sols=0;
    for(int p=rs;p+1<=r;p++){
     if(isvalid(pizza,rs,p,cs,s)&&isvalid(pizza,p+1,r,cs,s)){
         sols=(sols+dfs(pizza,k-1,p+1,r,cs,s))%1000000007;
    }
    }
    for(int i=cs;i+1<=s;i++){
     if(isvalid(pizza,rs,r,cs,i)&&isvalid(pizza,rs,r,i+1,s)){
        sols=(sols+dfs(pizza,k-1,rs,r,i+1,s))%1000000007;  
    }
    }
    return mp[i]=sols;
    }
    int ways(vector<string>& pizza, int k) {
        int sols=0;
        string i="";
        i=i+to_string(k)+" ";
        
        i+=to_string(0)+" "+to_string(pizza.size())+" "+to_string(0)+" "+to_string(pizza[0].size()); 
        if(k==1)
        {
            return mp[i]=1;
        }
        k--;
        return mp[i]=dfs(pizza,k,0,pizza.size()-1,0,pizza[0].size()-1);
    }
};