<h2><a href="https://leetcode.com/problems/extra-characters-in-a-string/">2707. Extra Characters in a String</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">You are given a <strong speechify-initial-font-size="14px" style="font-size: 14px;">0-indexed</strong> string <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> and a dictionary of words <code speechify-initial-font-size="13px" style="font-size: 13px;">dictionary</code>. You have to break <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> into one or more <strong speechify-initial-font-size="14px" style="font-size: 14px;">non-overlapping</strong> substrings such that each substring is present in <code speechify-initial-font-size="13px" style="font-size: 13px;">dictionary</code>. There may be some <strong speechify-initial-font-size="14px" style="font-size: 14px;">extra characters</strong> in <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> which are not present in any of the substrings.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return <em speechify-initial-font-size="14px" style="font-size: 14px;">the <strong speechify-initial-font-size="14px" style="font-size: 14px;">minimum</strong> number of extra characters left over if you break up </em><code speechify-initial-font-size="13px" style="font-size: 13px;">s</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> optimally.</em></p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> s = "leetscode", dictionary = ["leet","code","leetcode"]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> s = "sayhelloworld", dictionary = ["hello","world"]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> 3
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= s.length &lt;= 50</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= dictionary.length &lt;= 50</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= dictionary[i].length &lt;= 50</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">dictionary[i]</code>&nbsp;and <code speechify-initial-font-size="13px" style="font-size: 13px;">s</code> consists of only lowercase English letters</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">dictionary</code> contains distinct words</li>
</ul>
</div>