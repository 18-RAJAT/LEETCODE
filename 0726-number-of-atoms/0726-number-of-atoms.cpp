class Solution {
public:
    string getname(stack<char> &s){
        string h="";
        while(!(s.top()>=65 && s.top()<=90))
        {
            string u="";
            u+=s.top();
            h=u+h;
            s.pop(); 
        }
        string u="";
        u+=s.top();
        h=u+h;
        s.pop();
        return h;
    }
    string getnum(stack<char> &s)
    {
        string m="";
        while(s.top()!='(' && s.top()>=48 && s.top()<=57)
        {
            string y="";
            y+=s.top();
            m=y+m;
            s.pop();
         }
        return m;
    }
    string countOfAtoms(string formula)
    {
        stack<char> s;
        for(int i=0;i<formula.length();)
        {
            if(formula[i]==')')
            {
                int j=i+1;
                while(j<formula.length() && formula[j]>=48 && formula[j]<=57)
                {
                    j++;
                }
                int k;
                if(j>i+1)
                k=stoi(formula.substr(i+1,j-i-1));
                else k=1;
                string z="";
                while(s.top()!='(')
                {
                    string m=getnum(s);
                    string h=getname(s);
                    int r=k;
                    if(m!="")
                    {
                        r*=stoi(m);
                    }
                    z=h+to_string(r)+z;
                }
                s.pop();
                for(int l=0;l<z.length();++l)
                s.push(z[l]);
                i=j;
            }
            else
            { 
                s.push(formula[i]);
                i++;
            }
        }
        map<string,int>ma;
        while(!s.empty())
        {
            string m=getnum(s);
            string h=getname(s);
            auto it=ma.find(h);
            int z;
            (m=="")?z=1:z=stoi(m);
            if(it==ma.end())
            {
                ma.insert(pair<string,int>(h,z));
            }
            else it->second+=z; 
        }
        string x="";
        for(auto it=ma.begin();it!=ma.end();++it)
        {
            if(it->second!=1)
            x+=it->first+to_string(it->second);
            else x+=it->first;
        }
        return x;
    }
};