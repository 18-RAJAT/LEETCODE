class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        
    Arrays.sort(arr);
	
        var commonDiff = arr[1] - arr[0];
	
	for (var i = 2; i < arr.length; i++)
		
        if (arr[i] - arr[i - 1] != commonDiff)
		
            return false;

        return true;
        
    }
};