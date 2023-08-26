<h2><a href="https://leetcode.com/problems/maximum-length-of-pair-chain/">646. Maximum Length of Pair Chain</a></h2><h3>Medium</h3><hr><div><p speechify-initial-font-size="14px" style="font-size: 14px;">You are given an array of <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code> pairs <code speechify-initial-font-size="13px" style="font-size: 13px;">pairs</code> where <code speechify-initial-font-size="13px" style="font-size: 13px;">pairs[i] = [left<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">i</sub>, right<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">i</sub>]</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">left<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">i</sub> &lt; right<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">i</sub></code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">A pair <code speechify-initial-font-size="13px" style="font-size: 13px;">p2 = [c, d]</code> <strong speechify-initial-font-size="14px" style="font-size: 14px;">follows</strong> a pair <code speechify-initial-font-size="13px" style="font-size: 13px;">p1 = [a, b]</code> if <code speechify-initial-font-size="13px" style="font-size: 13px;">b &lt; c</code>. A <strong speechify-initial-font-size="14px" style="font-size: 14px;">chain</strong> of pairs can be formed in this fashion.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return <em speechify-initial-font-size="14px" style="font-size: 14px;">the length longest chain which can be formed</em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">You do not need to use up all the given intervals. You can select pairs in any order.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> pairs = [[1,2],[2,3],[3,4]]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 2
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> The longest chain is [1,2] -&gt; [3,4].
</pre>

<p><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre><strong>Input:</strong> pairs = [[1,2],[7,8],[4,5]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest chain is [1,2] -&gt; [4,5] -&gt; [7,8].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == pairs.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-1000 &lt;= left<sub>i</sub> &lt; right<sub>i</sub> &lt;= 1000</code></li>
</ul>
</div>