/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
  
      let accu=init;
      for(let i=0;i<nums.length;++i) 
      {
        accu=fn(accu,nums[i]);
      }
      return accu;
};