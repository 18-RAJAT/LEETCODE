<h2><a href="https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/">1326. Minimum Number of Taps to Open to Water a Garden</a></h2><h3>Hard</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">There is a one-dimensional garden on the x-axis. The garden starts at the point <code speechify-initial-font-size="13px" style="font-size: 13px;">0</code> and ends at the point <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code>. (i.e The length of the garden is <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code>).</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">There are <code speechify-initial-font-size="13px" style="font-size: 13px;">n + 1</code> taps located at points <code speechify-initial-font-size="13px" style="font-size: 13px;">[0, 1, ..., n]</code> in the garden.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Given an integer <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code> and an integer array <code speechify-initial-font-size="13px" style="font-size: 13px;">ranges</code> of length <code speechify-initial-font-size="13px" style="font-size: 13px;">n + 1</code> where <code speechify-initial-font-size="13px" style="font-size: 13px;">ranges[i]</code> (0-indexed) means the <code speechify-initial-font-size="13px" style="font-size: 13px;">i-th</code> tap can water the area <code speechify-initial-font-size="13px" style="font-size: 13px;">[i - ranges[i], i + ranges[i]]</code> if it was open.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return <em speechify-initial-font-size="14px" style="font-size: 14px;">the minimum number of taps</em> that should be open to water the whole garden, If the garden cannot be watered return <strong speechify-initial-font-size="14px" style="font-size: 14px;">-1</strong>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/1685_example_1.png" style="width: 525px; height: 255px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> n = 5, ranges = [3,4,1,1,0,0]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> n = 3, ranges = [0,0,0,0]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> -1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> Even if you activate all the four taps you cannot water the whole garden.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= n &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">4</sup></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">ranges.length == n + 1</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= ranges[i] &lt;= 100</code></li>
</ul>
</div>