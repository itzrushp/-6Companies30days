## Josephus Problem: Brute-Force and Optimized Solution

### Brute-Force Solution

1. **Initialization of the Vector:**
   - The vector `a` is initialized with `n` elements, and it's filled with values from `1` to `n` using a loop.

2. **Elimination Process:**
   - We start with an index `j = 0` (0-indexed) and use the `erase()` function to remove every `k`-th person from the vector.
   - The value of `j` is incremented by `k - 1` each time, and we use the modulus operation (`j %= a.size()`) to ensure that `j` stays within bounds of the current vector size.

3. **Final Result:**
   - Once the loop finishes and only one element remains in the vector, that person is the winner.

### Time and Space Complexity:
- **Time Complexity:** O(n^2) because each time we remove an element using `erase()`, it takes O(n) time, and there are `n` eliminations.
- **Space Complexity:** O(n) because we store the list of `n` people in a vector.


```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a(n);
        for(int i = 0 ; i < n ; i ++){
            a[i]=i+1;
        }
        int j = 0 ;
        while(a.size()>1){
          j+=k-1;
          j%=a.size();

          a.erase(a.begin()+j);
        }

        return a[0];
    }
};
```

---

### Optimized Solution (Mathematical Approach)

1. **Base Case:**
   - The winner when there is only one person (`n = 1`) is at position `0` (0-indexed). This is the base case.

2. **Iterative Solution:**
   - For each `i` from `2` to `n`, we calculate the new position of the winner using the formula:
     ```
     winner = (winner + k) % i;
     ```
   - This formula accounts for the fact that the position of the winner shifts with each elimination. Essentially, it finds the safe position in a circular arrangement.

3. **Final Result:**
   - Once we finish the loop, the value of `winner` holds the 0-indexed position of the last remaining person.
   - To convert this to a 1-indexed position, we add `1` before returning the result.

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0 ; 

        for(int i=2 ; i <=n ; i++){
            winner = (winner+k)%i;
        }

        return winner+1;
    }
};

//Recursive : 
int josephus(int n, int k) {
    if (n == 1) return 0;  // Base case, one person remains
    return (josephus(n - 1, k) + k) % n;  // Recursive step
}
```

### Time and Space Complexity:
- **Time Complexity:** O(n) because we only iterate from `2` to `n` once, calculating the winner in each iteration.
- **Space Complexity:** O(1) because we only use a constant amount of extra space to store the `winner` and `i`.

---

### Summary of Differences:

| Approach             | Time Complexity | Space Complexity |
|----------------------|-----------------|------------------|
| **Brute-Force**       | O(n^2)          | O(n)             |
| **Optimized (Mathematical)** | O(n)           | O(1)             |

- The brute-force solution simulates the elimination process using a vector, which leads to O(n^2) time complexity due to the repeated use of `erase()`.
- The optimized solution uses an iterative approach based on the Josephus problem formula, achieving O(n) time complexity with constant space.
