#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

class Solution {
public:
    string toHex(int num) {
    //     string res;
    //     for(int i=0;num and i<9;++i)
    // {
    //     int bit=num&0xF;
    //     if(bit<10){res=char('0'+bit)+res;}
    //     else{res=char('a'+bit-10)+res;}
    //     num>>=4;
    // }
    // return res.empty()?"0":res;
        
        char a[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res="";
        u_int n=num;        
        if(num==0){res="0";} 
        while(n!=0) 
        {
          res=a[n%16]+res;
           n=n/16;
        }
         return res;
    }
};