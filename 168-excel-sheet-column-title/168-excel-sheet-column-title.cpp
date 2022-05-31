class Solution {
public:
    string convertToTitle(int n) {
 
   string result;
    char temp;

    while(n)
    {
        n -= 1;
        temp = 'A' + n % 26;
        result = temp + result;
        n /= 26;

    }
    return result;
    }
};
