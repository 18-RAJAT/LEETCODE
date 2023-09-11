<h2><a href="https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/">1282. Group the People Given the Group Size They Belong To</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">There are <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code> people&nbsp;that are split into some unknown number of groups. Each person is labeled with a&nbsp;<strong speechify-initial-font-size="14px" style="font-size: 14px;">unique ID</strong>&nbsp;from&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">0</code>&nbsp;to&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">n - 1</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">You are given an integer array&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">groupSizes</code>, where <code speechify-initial-font-size="13px" style="font-size: 13px;">groupSizes[i]</code>&nbsp;is the size of the group that person&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">i</code>&nbsp;is in. For example, if&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">groupSizes[1] = 3</code>, then&nbsp;person&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">1</code>&nbsp;must be in a&nbsp;group of size&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">3</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return&nbsp;<em speechify-initial-font-size="14px" style="font-size: 14px;">a list of groups&nbsp;such that&nbsp;each person&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">i</code>&nbsp;is in a group of size&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">groupSizes[i]</code></em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Each person should&nbsp;appear in&nbsp;<strong speechify-initial-font-size="14px" style="font-size: 14px;">exactly one group</strong>,&nbsp;and every person must be in a group. If there are&nbsp;multiple answers, <strong speechify-initial-font-size="14px" style="font-size: 14px;">return any of them</strong>. It is <strong speechify-initial-font-size="14px" style="font-size: 14px;">guaranteed</strong> that there will be <strong speechify-initial-font-size="14px" style="font-size: 14px;">at least one</strong> valid solution for the given input.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> groupSizes = [3,3,3,3,3,1,3]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [[5],[0,1,2],[3,4,6]]
<b speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</b> 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> groupSizes = [2,1,3,3,3,2]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [[1],[0,5],[2,3,4]]
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">groupSizes.length == n</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= n&nbsp;&lt;= 500</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;=&nbsp;groupSizes[i] &lt;= n</code></li>
</ul>
</div>