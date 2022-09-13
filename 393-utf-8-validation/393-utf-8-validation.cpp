class Solution {
public:
     bool validUtf8(vector<int>& data) {
        int byte=0;
        
        for(auto it:data)
        {
            if(byte == 0)
            {
                if((it>>7)==0b0){byte=0;}
                else if((it>>5)==0b110){byte=1;}
                else if((it>>4)==0b1110){byte=2;}
                else if((it>>3)==0b11110){byte=3;}
                else{return false;}
            }
             else
            {
                if((it>>6)==0b10)
                {
                    byte--;
                }
                else{return false;}
            }
        }
        if(byte==0)return true;
        return false;
    }
};