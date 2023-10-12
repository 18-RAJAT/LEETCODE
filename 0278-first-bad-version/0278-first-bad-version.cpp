// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int left,int right)
    {
        if(left==right)
        {
            return left;
        }
        int mid=left+(right-left)/2;
        if(isBadVersion(mid))//if mid is bad then all the versions after mid are bad so we search in the left half of the array
        {
            return binarySearch(left,mid);
        }
        else
        {
            return binarySearch(mid+1,right);
        }
        return -1;
    }
    int firstBadVersion(int n) {
        return binarySearch(1,n);
    }
};