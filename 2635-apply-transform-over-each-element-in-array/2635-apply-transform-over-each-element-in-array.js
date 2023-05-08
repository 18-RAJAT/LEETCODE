/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map=(arr,fn)=>arr.flatMap((el,i)=>fn(el,i))