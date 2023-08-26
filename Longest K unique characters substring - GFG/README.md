# Longest K unique characters substring
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string you need to print the size of the longest possible substring that has exactly <strong>K&nbsp;unique</strong> characters. If there is no possible substring then print -1.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
S = "aabacbebebe</span><span style="font-size: 18px;">", K = 3
<strong>Output:</strong> <br>7
<strong>Explanation</strong>: <br>"cbebebe" is the longest substring with 3 distinct characters.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
S = "aaaa", K = 2
<strong speechify-initial-font-size="15px" style="font-size: 15px;">Output:</strong> -1
<strong speechify-initial-font-size="15px" style="font-size: 15px;">Explanation</strong>: <br speechify-initial-font-size="15px" style="font-size: 15px;">There's no substring with 2 distinct characters.
</span></pre>
<p speechify-initial-font-size="15px" style="font-size: 15px;"><span style="font-size: 15px;" speechify-initial-font-size="15px"><strong speechify-initial-font-size="15px" style="font-size: 15px;">Your Task:</strong><br speechify-initial-font-size="15px" style="font-size: 15px;">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong speechify-initial-font-size="15px" style="font-size: 15px;">longestKSubstr()&nbsp;</strong>which takes the string S and an integer K as input and returns the length of the longest substring with exactly K&nbsp;distinct characters. If there is no substring with exactly K distinct characters then return -1.</span></p>
<p speechify-initial-font-size="15px" style="font-size: 15px;"><span style="font-size: 15px;" speechify-initial-font-size="15px"><strong speechify-initial-font-size="15px" style="font-size: 15px;">Expected Time Complexity: </strong>O(|S|).<br speechify-initial-font-size="15px" style="font-size: 15px;"><strong speechify-initial-font-size="15px" style="font-size: 15px;">Expected Auxiliary Space:&nbsp;</strong>O(|S|).</span></p>
<p speechify-initial-font-size="15px" style="font-size: 15px;"><span style="font-size: 15px;" speechify-initial-font-size="15px"><strong speechify-initial-font-size="15px" style="font-size: 15px;">Constraints:</strong><br speechify-initial-font-size="15px" style="font-size: 15px;">1 ≤ |S| ≤ 10<sup speechify-initial-font-size="15px" style="font-size: 15px;">5</sup><br speechify-initial-font-size="15px" style="font-size: 15px;">1 ≤ K ≤ 26<br speechify-initial-font-size="15px" style="font-size: 15px;">All characters are lowercase latin characters.</span></p></div>