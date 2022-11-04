class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        if(n==0 or n==1) return s;
        if(s==" ")
        {
            return s;
        }
        while(i<=j and i!=n and j!=-1)
        {
            while(i!=n and j!=-1 and i<=j and !isVowel(s[i])) i++;
            while(i!=n and j!=-1 and i<=j and !isVowel(s[j])) j--;
            if(i<=j and i!=n and j!=-1)
            {
                swap(s[i],s[j]);
            }
            i++;
            j--;
        }
        return s;
    }
};