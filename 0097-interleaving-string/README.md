<h2><a href="https://leetcode.com/problems/interleaving-string/">97. Interleaving String</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given strings <code speechify-initial-font-size="13px" style="font-size: 13px;">s1</code>, <code speechify-initial-font-size="13px" style="font-size: 13px;">s2</code>, and <code speechify-initial-font-size="13px" style="font-size: 13px;">s3</code>, find whether <code speechify-initial-font-size="13px" style="font-size: 13px;">s3</code> is formed by an <strong speechify-initial-font-size="14px" style="font-size: 14px;">interleaving</strong> of <code speechify-initial-font-size="13px" style="font-size: 13px;">s1</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">s2</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">An <strong speechify-initial-font-size="14px" style="font-size: 14px;">interleaving</strong> of two strings <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">t</code> is a configuration where <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">t</code> are divided into <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">m</code> <span data-keyword="substring-nonempty" speechify-initial-font-size="14px" style="font-size: 14px;">substrings</span> respectively, such that:</p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">s = s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + ... + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">n</sub></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">t = t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + ... + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">m</sub></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">|n - m| &lt;= 1</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">The <strong speechify-initial-font-size="14px" style="font-size: 14px;">interleaving</strong> is <code speechify-initial-font-size="13px" style="font-size: 13px;">s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">3</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">3</sub> + ...</code> or <code speechify-initial-font-size="13px" style="font-size: 13px;">t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">1</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">2</sub> + t<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">3</sub> + s<sub speechify-initial-font-size="9.75px" style="font-size: 9.75px;">3</sub> + ...</code></li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Note:</strong> <code speechify-initial-font-size="13px" style="font-size: 13px;">a + b</code> is the concatenation of strings <code speechify-initial-font-size="13px" style="font-size: 13px;">a</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">b</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg" style="width: 561px; height: 203px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> true
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> false
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> Notice how it is impossible to interleave s2 with any other string to obtain s3.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 3:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> s1 = "", s2 = "", s3 = ""
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> true
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= s3.length &lt;= 200</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">s1</code>, <code speechify-initial-font-size="13px" style="font-size: 13px;">s2</code>, and <code speechify-initial-font-size="13px" style="font-size: 13px;">s3</code> consist of lowercase English letters.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</strong> Could you solve it using only <code speechify-initial-font-size="13px" style="font-size: 13px;">O(s2.length)</code> additional memory space?</p>
</div>