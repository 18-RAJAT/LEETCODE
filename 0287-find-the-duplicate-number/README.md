<h2><a href="https://leetcode.com/problems/find-the-duplicate-number/">287. Find the Duplicate Number</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given an array of integers <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code> containing&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">n + 1</code> integers where each integer is in the range <code speechify-initial-font-size="13px" style="font-size: 13px;">[1, n]</code> inclusive.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">There is only <strong speechify-initial-font-size="14px" style="font-size: 14px;">one repeated number</strong> in <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code>, return <em speechify-initial-font-size="14px" style="font-size: 14px;">this&nbsp;repeated&nbsp;number</em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">You must solve the problem <strong speechify-initial-font-size="14px" style="font-size: 14px;">without</strong> modifying the array <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code>&nbsp;and uses only constant extra space.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [1,3,4,2,2]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 2
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> nums = [3,1,3,4,2]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 3
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= n &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">nums.length == n + 1</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= nums[i] &lt;= n</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">All the integers in <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code> appear only <strong speechify-initial-font-size="14px" style="font-size: 14px;">once</strong> except for <strong speechify-initial-font-size="14px" style="font-size: 14px;">precisely one integer</strong> which appears <strong speechify-initial-font-size="14px" style="font-size: 14px;">two or more</strong> times.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><b speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</b></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">How can we prove that at least one duplicate number must exist in <code speechify-initial-font-size="13px" style="font-size: 13px;">nums</code>?</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">Can you solve the problem in linear runtime complexity?</li>
</ul>
</div>