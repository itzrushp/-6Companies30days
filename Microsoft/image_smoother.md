# In-Place Image Smoothing with Encoding and Decoding

## Overview
To perform image smoothing **in-place**, we need to modify the matrix directly without using extra space. This is achieved by encoding both the **original value** and the **smoothed value** in the same cell using bitwise operations.

---

## Steps

### 1. **Encoding the New Value**
We store the **new smoothed value** in the higher bits of the integer while retaining the **original value** in the lower bits.  

### 2. **Decoding the New Value**
After all calculations, we extract the smoothed value from the higher bits by discarding the lower bits.

---

## Process Example

### Input Matrix:
```
img = [
    [100, 200],
    [150, 250]
]
```

---

### Step 1: Encoding

Let’s calculate the smoothed value for each cell and encode it.

1. **For Cell (0, 0):**
   - **Neighbors:** `[100, 200, 150]`
   - **Sum:** \(100 + 200 + 150 = 450\)
   - **Count:** \(3\)
   - **New Value:** \(450 / 3 = 150\)
   - **Encoding:**
     - Original value = \(100\)
     - New value = \(150\)
     - Binary representation:
       ```
       Original value (lower 8 bits):  01100100 (100 in binary)
       New value (higher 8 bits):     10010110 (150 in binary)
       Combined:                      10010110 01100100
       ```
     - Decimal encoding: \(38404\)
     - Update matrix: Replace \(img[0][0]\) with \(38404\).

2. **For Cell (0, 1):**
   - **Neighbors:** `[100, 200, 150, 250]`
   - **Sum:** \(100 + 200 + 150 + 250 = 700\)
   - **Count:** \(4\)
   - **New Value:** \(700 / 4 = 175\)
   - **Encoding:**
     ```
     Original value (200):  11001000 (200 in binary)
     New value (175):      10101111 (175 in binary)
     Combined:             10101111 11001000
     ```
     - Decimal encoding: \(44936\)
     - Update matrix: Replace \(img[0][1]\) with \(44936\).

3. Repeat the process for all cells.

---

### Step 2: Decoding

To extract the **new value**, shift each encoded value 8 bits to the right:

1. **For Cell (0, 0):**
   - Encoded value: \(38404\)
   - Binary: \(10010110 01100100\)
   - Shift right 8 bits: \(10010110\) (new value = \(150\))
   - Update matrix: Replace \(img[0][0]\) with \(150\).

2. Repeat for all cells.

---

### Final Matrix After Decoding:
```
img = [
    [150, 175],
    [170, 200]
]
```

---

## Key Operations

1. **Encoding:**
   - Use `img[i][j] |= (newVal << 8);`  
     - This shifts the new value `newVal` left by 8 bits and combines it with the original value using a bitwise OR (`|`).

2. **Decoding:**
   - Use `img[i][j] = (img[i][j] >> 8);`  
     - This shifts the value 8 bits to the right, discarding the original value and leaving only the new value.

---

## Why This Works
- **Bitwise Shifting:** Shifting left creates space in the higher bits for the new value. Shifting right moves the higher bits back to the lower position, effectively extracting the new value.
- **No Overflow:** Since we're working with integers, this method works as long as both the original and new values fit within 16 bits (values up to \(255\)).

---

## Example

### Input:
```
img = [
    [100, 200],
    [150, 250]
]
```

### After Encoding:
```
img = [
    [38404, 44936],
    [42600, 48750]
]
```

### After Decoding:
```
img = [
    [150, 175],
    [170, 200]
]
