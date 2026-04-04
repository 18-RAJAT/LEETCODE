class Solution{
public:
    string decodeCiphertext(string encodedText,int rows){
        if(rows==1)return encodedText;
        int cols=encodedText.size()/rows;
        string ans="";
        for(int j=0;j<cols;++j)
        {
            int i=0,col=j;
            while(i<rows && col<cols)
            {
                ans+=encodedText[i*cols+col];
                i++,col++;
            }
        }
        while(!ans.empty()&&ans.back()==' ')ans.pop_back();
        return ans;
    }
};