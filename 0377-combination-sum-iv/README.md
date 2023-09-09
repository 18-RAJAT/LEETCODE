<h2><a href="https://leetcode.com/problems/combination-sum-iv/">377. Combination Sum IV</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given an array of <strong speechify-initial-font-size="14px" style="font-size: 14px;">distinct</strong> integers <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code> and a target integer <code speechify-initial-font-size="13px" style="font-size: 13px;">target</code>, return <em speechify-initial-font-size="14px" style="font-size: 14px;">the number of possible combinations that add up to</em>&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">target</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">The test cases are generated so that the answer can fit in a <strong speechify-initial-font-size="14px" style="font-size: 14px;">32-bit</strong> integer.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [1,2,3], target = 4
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 7
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong>
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [9], target = 3
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 0
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= nums.length &lt;= 200</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= nums[i] &lt;= 1000</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">All the elements of <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code> are <strong speechify-initial-font-size="14px" style="font-size: 14px;">unique</strong>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= target &lt;= 1000</code></li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</strong> What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?</p>
</div>