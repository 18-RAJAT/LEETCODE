<h2><a href="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/">2366. Minimum Replacements to Sort the Array</a></h2><h3>Hard</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">You are given a <strong speechify-initial-font-size="14px" style="font-size: 14px;">0-indexed</strong> integer array <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code>. In one operation you can replace any element of the array with <strong speechify-initial-font-size="14px" style="font-size: 14px;">any two</strong> elements that <strong speechify-initial-font-size="14px" style="font-size: 14px;">sum</strong> to it.</p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">For example, consider <code speechify-initial-font-size="13px" style="font-size: 13px;">nums = [5,6,7]</code>. In one operation, we can replace <code speechify-initial-font-size="13px" style="font-size: 13px;">nums[1]</code> with <code speechify-initial-font-size="13px" style="font-size: 13px;">2</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">4</code> and convert <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code> to <code speechify-initial-font-size="13px" style="font-size: 13px;">[5,2,4,7]</code>.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return <em speechify-initial-font-size="14px" style="font-size: 14px;">the minimum number of operations to make an array that is sorted in <strong speechify-initial-font-size="14px" style="font-size: 14px;">non-decreasing</strong> order</em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [3,9,3]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 2
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.

</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [1,2,3,4,5]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 0
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> The array is already in non-decreasing order. Therefore, we return 0. 
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= nums.length &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= nums[i] &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">9</sup></code></li>
</ul>
</div>