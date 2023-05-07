/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        var ans=n++;
        return ans;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */