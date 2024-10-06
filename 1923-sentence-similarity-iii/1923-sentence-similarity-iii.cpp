class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()==sentence2.size()) return sentence1==sentence2;
        if(sentence1.size()>sentence2.size())
        {
            swap(sentence1,sentence2);
        }
        istringstream ss1(sentence1),ss2(sentence2); string t;
        vector<string>s1,s2;

        while(ss1>>t)s1.push_back(t);
        while(ss2>>t)s2.push_back(t);
        
        int n1=s1.size(),n2=s2.size(),l=0,r=0;
        while(l<n1 && s1[l]==s2[l])l++;
        while(n1-r-1>=l && s1[n1-1-r]==s2[n2-1-r])r++;
        return n1-r-1<l;
    }
};