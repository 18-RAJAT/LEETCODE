#define f1(i,s,e) for(long long int i=0;i<k.length();i++)
#define fff(i,s,e) for(long long int i=0;i<m.length();i++)

class Solution {
public:
    string decodeMessage(string k, string m) {
        char tp ='a';
        unordered_map<char,char>ump;
            f1(i,s,e)
        {
            if(k[i]!=' ' and ump.find(k[i])==ump.end()) 
            {ump[k[i]]=tp;tp++;}  
        }
        string s="";
        fff(i,s,e)
        {
            if(m[i]!=' '){s=s+ump[m[i]];}
            else{s=s+" ";}}
        return s;
    }
};