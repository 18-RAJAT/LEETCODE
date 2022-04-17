# C++ Generic sort
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You need to sort elements of an array where the array can be of following data-types:</span></p>

<ul>
	<li><span style="font-size:18px">Integer</span></li>
	<li><span style="font-size:18px">String</span></li>
	<li><span style="font-size:18px">floating number</span></li>
</ul>

<p><span style="font-size:18px">Your task is to complete the given two functions</span><span style="font-size:18px">: <strong>sortArray()</strong> and </span><strong><span style="font-size:18px">printArray()</span></strong>.</p>

<p><br>
<span style="font-size:18px">The input line </span><span style="font-size:18px">contains 2 lines. The first line contains <strong>n</strong>(size of array) and <strong>q</strong>(type of array) separated by space. Below is the description about q.</span></p>

<ul>
	<li><span style="font-size:18px">q = 1, means elements of the array are of integer type</span></li>
	<li><span style="font-size:18px">q = 2, means elements of the array are of string type</span></li>
	<li><span style="font-size:18px">q = 3, means elements of array are of floating digit type &nbsp;</span></li>
</ul>

<p><span style="font-size:18px">The second line contains n elements of the array separated by space.</span></p>

<p><span style="font-size:18px">We have to&nbsp;print the elements in sorted form of given type of array separated by space.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong> <strong> </strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
3 3
34.23 -4.35 3.4
<strong>Output: 
</strong>-4.35 3.4 34.23&nbsp;
<strong>Explanation:</strong>
The array is of floating type. After
sorting the elements of array are as
such:&nbsp; -4.35 3.4 34.23
</span></pre>

<p><span style="font-size:18px"><strong>Example 2: </strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
4 1
123 -2311 837 0 
<strong>Output: </strong>
-2311 0 123 837&nbsp;</span></pre>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 50<br>
1 &lt;= n &lt;= 100<br>
1 &lt;= q &lt;= 3</span></p>
 <p></p>
            </div>