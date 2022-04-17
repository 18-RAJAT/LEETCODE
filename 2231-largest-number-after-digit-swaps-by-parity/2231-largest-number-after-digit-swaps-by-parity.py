class Solution:
    def largestInteger(self, num: int) -> int:
        digits = list(map(int, str(num)))
        evens = sorted(x for x in digits if x % 2 == 0)
        
        odds = sorted(x for x in digits if x % 2 == 1)
        
        return ''.join(str(odds.pop() if x&1 else evens.pop()) for x in digits)