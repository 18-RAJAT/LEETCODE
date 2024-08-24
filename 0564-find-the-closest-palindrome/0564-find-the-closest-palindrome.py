class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length=len(n)
        if length==1:return str(int(n)-1)
        
        prefix=int(n[:(length+1)//2])
        candidates={str(10**(length -1)-1),str(10**length+1)}
        
        for i in [-1,0,1]:
            new_prefix=str(prefix + i)
            candidates.add(new_prefix+new_prefix[-(length%2+1)::-1])
        
        candidates.discard(n)
        return min(candidates,key=lambda x:(abs(int(x)-int(n)),int(x)))
