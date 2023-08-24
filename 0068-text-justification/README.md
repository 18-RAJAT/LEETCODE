<h2><a href="https://leetcode.com/problems/text-justification/">68. Text Justification</a></h2><h3>Hard</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given an array of strings <code speechify-initial-font-size="13px" style="font-size: 13px;">words</code> and a width <code speechify-initial-font-size="13px" style="font-size: 13px;">maxWidth</code>, format the text such that each line has exactly <code speechify-initial-font-size="13px" style="font-size: 13px;">maxWidth</code> characters and is fully (left and right) justified.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces <code speechify-initial-font-size="13px" style="font-size: 13px;">' '</code> when necessary so that each line has exactly <code speechify-initial-font-size="13px" style="font-size: 13px;">maxWidth</code> characters.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">For the last line of text, it should be left-justified, and no extra space is inserted between words.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Note:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">A word is defined as a character sequence consisting of non-space characters only.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">Each word's length is guaranteed to be greater than <code speechify-initial-font-size="13px" style="font-size: 13px;">0</code> and not exceed <code speechify-initial-font-size="13px" style="font-size: 13px;">maxWidth</code>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;">The input array <code speechify-initial-font-size="13px" style="font-size: 13px;">words</code> contains at least one word.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong>
[
&nbsp; &nbsp;"This &nbsp; &nbsp;is &nbsp; &nbsp;an",
&nbsp; &nbsp;"example &nbsp;of text",
&nbsp; &nbsp;"justification. &nbsp;"
]</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong>
[
&nbsp; "What &nbsp; must &nbsp; be",
&nbsp; "acknowledgment &nbsp;",
&nbsp; "shall be &nbsp; &nbsp; &nbsp; &nbsp;"
]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 3:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong>
[
&nbsp; "Science &nbsp;is &nbsp;what we",
  "understand &nbsp; &nbsp; &nbsp;well",
&nbsp; "enough to explain to",
&nbsp; "a &nbsp;computer. &nbsp;Art is",
&nbsp; "everything &nbsp;else &nbsp;we",
&nbsp; "do &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;"
]</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= words.length &lt;= 300</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= words[i].length &lt;= 20</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">words[i]</code> consists of only English letters and symbols.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= maxWidth &lt;= 100</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">words[i].length &lt;= maxWidth</code></li>
</ul>
</div>