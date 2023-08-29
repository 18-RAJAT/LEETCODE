<h2><a href="https://leetcode.com/problems/minimum-penalty-for-a-shop/">2483. Minimum Penalty for a Shop</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">You are given the customer visit log of a shop represented by a <strong speechify-initial-font-size="14px" style="font-size: 14px;">0-indexed</strong> string <code speechify-initial-font-size="13px" style="font-size: 13px;">customers</code> consisting only of characters <code speechify-initial-font-size="13px" style="font-size: 13px;">'N'</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">'Y'</code>:</p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">if the <code speechify-initial-font-size="13px" style="font-size: 13px;">i<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup></code> character is <code speechify-initial-font-size="13px" style="font-size: 13px;">'Y'</code>, it means that customers come at the <code speechify-initial-font-size="13px" style="font-size: 13px;">i<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup></code> hour</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">whereas <code speechify-initial-font-size="13px" style="font-size: 13px;">'N'</code> indicates that no customers come at the <code speechify-initial-font-size="13px" style="font-size: 13px;">i<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup></code> hour.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">If the shop closes at the <code speechify-initial-font-size="13px" style="font-size: 13px;">j<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup></code> hour (<code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= j &lt;= n</code>), the <strong speechify-initial-font-size="14px" style="font-size: 14px;">penalty</strong> is calculated as follows:</p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">For every hour when the shop is open and no customers come, the penalty increases by <code speechify-initial-font-size="13px" style="font-size: 13px;">1</code>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">For every hour when the shop is closed and customers come, the penalty increases by <code speechify-initial-font-size="13px" style="font-size: 13px;">1</code>.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return<em speechify-initial-font-size="14px" style="font-size: 14px;"> the <strong speechify-initial-font-size="14px" style="font-size: 14px;">earliest</strong> hour at which the shop must be closed to incur a <strong speechify-initial-font-size="14px" style="font-size: 14px;">minimum</strong> penalty.</em></p>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Note</strong> that if a shop closes at the <code speechify-initial-font-size="13px" style="font-size: 13px;">j<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup></code> hour, it means the shop is closed at the hour <code speechify-initial-font-size="13px" style="font-size: 13px;">j</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> customers = "YYNY"
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 2
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> 
- Closing the shop at the 0<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup> hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">st</sup> hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">nd</sup> hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">rd</sup> hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup> hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">nd</sup> or 4<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup> hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> customers = "NNNNN"
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 0
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> It is best to close the shop at the 0<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup> hour as no customers arrive.</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 3:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> customers = "YYYY"
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 4
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> It is best to close the shop at the 4<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">th</sup> hour as customers arrive at each hour.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= customers.length &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">customers</code> consists only of characters <code speechify-initial-font-size="13px" style="font-size: 13px;">'Y'</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">'N'</code>.</li>
</ul>
</div>