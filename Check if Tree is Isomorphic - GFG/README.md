# Check if Tree is Isomorphic
## Easy
<div class="problems_problem_content__Xm_eO" speechify-initial-font-family="Roboto, sans-serif" speechify-initial-font-size="16px"><p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;"><span style="font-size: 15px; font-family: urw-din;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Given two&nbsp;Binary Trees. Check whether they are&nbsp;Isomorphic or not.</span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;"><span style="font-size: 15px; font-family: urw-din;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;">Note:&nbsp;</strong><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;">Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.&nbsp;Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;">For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;"><a href="https://media.geeksforgeeks.org/wp-content/cdn-uploads/ISomorphicTrees-e1368593305854.png" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;"><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/ISomorphicTrees-e1368593305854.png" alt="ISomorphicTrees" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px" style="font-family: urw-din; font-size: 15px;"></a></span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Example 1:</strong></span></p>
<pre speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Input:
 T1    </strong>1     <strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">T2:</strong>   1
&nbsp;    /   \        /  \
&nbsp;   2     3      3    2
&nbsp;  /            /
&nbsp; 4<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">&nbsp;           </strong>4<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">
Output: </strong>No
</span>
</pre>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Example 2:</strong></span></p>
<pre speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Input:
T1    </strong>1     <strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">T2:</strong>    1
&nbsp;   /  \         /   \
&nbsp;  2    3       3     2
&nbsp; /                    \
&nbsp; 4<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">&nbsp;                    </strong>4<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">
Output: </strong>Yes
</span></pre>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Your Task:</strong><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">You don't need to read input or print anything. Your task is to complete the function<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"> isomorphic() </strong>that takes<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">&nbsp;</strong>the root&nbsp;nodes of both the Binary Trees as its input&nbsp;and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, otherwise false.)</span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Expected Time Complexity:&nbsp;</strong>O(min(M, N)) where M and N are the sizes of the two trees.<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Expected Auxiliary Space:&nbsp;</strong>O(min(H1, H2)) where H1 and H2 are the heights of the two trees.</span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 18px;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Constraints:</strong><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">1&lt;=Number of nodes&lt;=10<sup speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">5</sup></span></p></div>