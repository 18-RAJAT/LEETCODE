/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int get(int index,MountainArray& mountainArr)
    {
        return mountainArr.get(index);//get(index);
    }
    int increasingBinarySearch(int target,MountainArray& mountainArr,int start,int end)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int midVal=get(mid,mountainArr);
            if(midVal==target)
            {
                return mid;
            }
            else if(midVal<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
    int decreasingBinarySearch(int target,MountainArray& mountainArr,int start,int end)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int midVal=get(mid,mountainArr);
            if(midVal==target)
            {
                return mid;
            }
            else if(midVal<target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
    int findPeak(MountainArray& mountainArr,int start,int end)
    {
        while(start<end)
        {
            int mid=start+(end-start)/2;
            int midVal=get(mid,mountainArr);
            int midVal1=get(mid+1,mountainArr);
            if(midVal<midVal1)
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return start;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=findPeak(mountainArr,0,mountainArr.length()-1);
        int ans=increasingBinarySearch(target,mountainArr,0,peak);
        if(~ans)
        {
            return ans;
        }
        return decreasingBinarySearch(target,mountainArr,peak+1,mountainArr.length()-1);
    }
};