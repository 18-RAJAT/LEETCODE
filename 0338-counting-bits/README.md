<h2><a href="https://leetcode.com/problems/counting-bits/">338. Counting Bits</a></h2><h3>Easy</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given an integer <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code>, return <em speechify-initial-font-size="14px" style="font-size: 14px;">an array </em><code speechify-initial-font-size="13px" style="font-size: 13px;">ans</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> of length </em><code speechify-initial-font-size="13px" style="font-size: 13px;">n + 1</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> such that for each </em><code speechify-initial-font-size="13px" style="font-size: 13px;">i</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> </em>(<code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= i &lt;= n</code>)<em speechify-initial-font-size="14px" style="font-size: 14px;">, </em><code speechify-initial-font-size="13px" style="font-size: 13px;">ans[i]</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> is the <strong speechify-initial-font-size="14px" style="font-size: 14px;">number of </strong></em><code speechify-initial-font-size="13px" style="font-size: 13px;">1</code><em speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">'s</strong> in the binary representation of </em><code speechify-initial-font-size="13px" style="font-size: 13px;">i</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> n = 2
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [0,1,1]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> n = 5
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [0,1,1,2,1,2]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= n &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup></code></li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">It is very easy to come up with a solution with a runtime of <code speechify-initial-font-size="13px" style="font-size: 13px;">O(n log n)</code>. Can you do it in linear time <code speechify-initial-font-size="13px" style="font-size: 13px;">O(n)</code> and possibly in a single pass?</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">Can you do it without using any built-in function (i.e., like <code speechify-initial-font-size="13px" style="font-size: 13px;">__builtin_popcount</code> in C++)?</li>
</ul>
</div>