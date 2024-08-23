class Solution:
    def fractionAddition(self, expression: str) -> str:
        import fractions
        ans=str(fractions.Fraction(eval(expression)).limit_denominator(20000))
        return ans if '/' in ans else ans+'/1'