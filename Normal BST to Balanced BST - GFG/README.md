# Normal BST to Balanced BST
## Easy
<div class="problems_problem_content__Xm_eO" speechify-initial-font-family="Roboto, sans-serif" speechify-initial-font-size="16px"><p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.</span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Example1:</strong></span></p>
<pre speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Input:</strong>
       30
      /
     20
    /
   10<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"></span><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Output:</strong>
     20
   /   \
 10     30
</span></pre>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Example2:</strong></span></p>
<pre speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Input:</strong>
         4
        /
       3
      /
     2
    /
   1
<strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Output:</strong>
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ <br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">     2        1                    4</span></pre>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Your Task:</strong><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">The task is to complete the function <strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">buildBalancedTree()</strong> which takes root as the input argument and returns the root of tree after converting the given BST&nbsp;into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself. </span><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">&nbsp;</span><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Expected Time Complexity:&nbsp;</strong>O(N)<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Expected Auxiliary Space: </strong>O(N)<br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Here N denotes total number of nodes in given BST.</span></p>
<p speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><span style="font-size: 14pt;" speechify-initial-font-family="urw-din" speechify-initial-font-size="15px"><strong speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">Constraints:</strong><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">1 &lt;= N &lt;= 10<sup speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">5</sup><br speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">1 &lt;= Node data &lt;= 10<sup speechify-initial-font-family="urw-din" speechify-initial-font-size="15px">9</sup></span></p></div>