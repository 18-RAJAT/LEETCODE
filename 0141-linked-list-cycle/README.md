<h2><a href="https://leetcode.com/problems/linked-list-cycle/">141. Linked List Cycle</a></h2><h3>Easy</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given <code speechify-initial-font-size="13px" style="font-size: 13px;">head</code>, the head of a linked list, determine if the linked list has a cycle in it.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">next</code>&nbsp;pointer. Internally, <code speechify-initial-font-size="13px" style="font-size: 13px;">pos</code>&nbsp;is used to denote the index of the node that&nbsp;tail's&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">next</code>&nbsp;pointer is connected to.&nbsp;<strong speechify-initial-font-size="14px" style="font-size: 14px;">Note that&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">pos</code>&nbsp;is not passed as a parameter</strong>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return&nbsp;<code speechify-initial-font-size="13px" style="font-size: 13px;">true</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> if there is a cycle in the linked list</em>. Otherwise, return <code speechify-initial-font-size="13px" style="font-size: 13px;">false</code>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="width: 300px; height: 97px; margin-top: 8px; margin-bottom: 8px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [3,2,0,-4], pos = 1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> true
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="width: 141px; height: 74px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [1,2], pos = 0
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> true
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 0th node.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="width: 45px; height: 45px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [1], pos = -1
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> false
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong> There is no cycle in the linked list.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">The number of the nodes in the list is in the range <code speechify-initial-font-size="13px" style="font-size: 13px;">[0, 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">4</sup>]</code>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">-10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup> &lt;= Node.val &lt;= 10<sup speechify-initial-font-size="9.75px" style="font-size: 9.75px;">5</sup></code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">pos</code> is <code speechify-initial-font-size="13px" style="font-size: 13px;">-1</code> or a <strong speechify-initial-font-size="14px" style="font-size: 14px;">valid index</strong> in the linked-list.</li>
</ul>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Follow up:</strong> Can you solve it using <code speechify-initial-font-size="13px" style="font-size: 13px;">O(1)</code> (i.e. constant) memory?</p>
</div>