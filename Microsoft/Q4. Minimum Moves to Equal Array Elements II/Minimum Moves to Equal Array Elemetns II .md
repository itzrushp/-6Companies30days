## Problem Explanation: Minimum Moves to Equal Array Elements

Given an integer array `nums` of size `n`, we are tasked with returning the minimum number of moves required to make all elements of the array equal. In one move, you can either increment or decrement an element of the array by 1. 

### Approach and Intuition:

The goal is to make all elements equal with the minimum number of moves. The key observation here is that we want to minimize the sum of the absolute differences between all array elements.

1. **Sorting the Array:**
   - First, we sort the array in non-decreasing order. This helps because the problem essentially asks us to find a target value where all elements should converge, and the median value of the array minimizes the sum of absolute differences to other elements. The median is a point of central tendency that reduces the total number of moves required.

2. **Why Median?**
   - The median minimizes the sum of absolute differences. If we choose any number smaller or larger than the median, the total number of moves increases because:
     - If we choose a number smaller than the median, elements to the right of this number will require more moves to reach that number.
     - If we choose a number larger than the median, elements to the left of this number will require more moves to reach that number.
   - In mathematical terms, the median is the optimal value that minimizes the function:
     ```
     f(x) = Σ |nums[i] - x| for all i
     ```
     where `x` is a potential target value. The median of the sorted array minimizes this function.

3. **The Steps:**
   - Sort the array to arrange the elements in non-decreasing order.
   - The median is the element at the middle of the sorted array (for an odd number of elements) or any element in the middle range (for an even number of elements). For simplicity, we pick the middle element of the sorted array when the number of elements is odd.
   - Calculate the number of moves required to change each element in the array to the median value.

4. **Optimality of the Approach:**
   - Once we have the median, we calculate the total number of moves needed to convert all elements to this value. This is done by summing the absolute differences between each element and the median.
   - We don't need to check all possible target values, as the median gives the minimum possible result.

### Explanation of the Code:

1. **Sorting the Array:**
   - The array `nums` is sorted so that we can easily find the median.
   
2. **Finding the Number of Moves:**
   - After sorting, we iterate through the array and calculate the total number of moves needed to convert each element to the median. The median is the element in the middle of the sorted array.

```cpp 
   class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans =0;
        int i =0 ;
        int j = nums.size()-1;

        while( i < j ){
           ans+= abs(nums[i]-nums[j]) ;
           i++;j--;
        }

        return ans;
    }
};
```

### Time Complexity:
- **Sorting the array:** O(n log n), where `n` is the size of the array.
- **Summing the absolute differences:** O(n), where `n` is the size of the array.
- Overall, the time complexity of the solution is O(n log n).

### Space Complexity:
- **Space Complexity:** O(1) for the extra space used, except for the input array.

### Example:

For the array `nums = [1, 2, 3]`, after sorting, the array is `[1, 2, 3]`. The median is `2`. To make all elements equal to `2`:
- Element `1` needs `1` move to become `2`.
- Element `2` is already `2`, so no moves are required.
- Element `3` needs `1` move to become `2`.
Thus, the total number of moves is `1 + 1 = 2`.

### Summary:
- The key insight is that the median minimizes the total number of moves required to make all elements equal. By sorting the array and calculating the total number of moves to the median, we can solve the problem efficiently.


