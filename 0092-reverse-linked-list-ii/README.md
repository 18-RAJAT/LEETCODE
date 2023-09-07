<h2><a href="https://leetcode.com/problems/reverse-linked-list-ii/">92. Reverse Linked List II</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given the <code speechify-initial-font-size="13px" style="font-size: 13px;">head</code> of a singly linked list and two integers <code speechify-initial-font-size="13px" style="font-size: 13px;">left</code> and <code speechify-initial-font-size="13px" style="font-size: 13px;">right</code> where <code speechify-initial-font-size="13px" style="font-size: 13px;">left &lt;= right</code>, reverse the nodes of the list from position <code speechify-initial-font-size="13px" style="font-size: 13px;">left</code> to position <code speechify-initial-font-size="13px" style="font-size: 13px;">right</code>, and return <em speechify-initial-font-size="14px" style="font-size: 14px;">the reversed list</em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg" style="width: 542px; height: 222px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [1,2,3,4,5], left = 2, right = 4
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [1,4,3,2,5]
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>

<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [5], left = 1, right = 1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [5]
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">The number of nodes in the list is <code speechify-initial-font-size="13px" style="font-size: 13px;">n</code>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= n &lt;= 500</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">-500 &lt;= Node.val &lt;= 500</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= left &lt;= right &lt;= n</code></li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<strong speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</strong> Could you do it in one pass?</div>