# Finding the Closest Point on the Rectangle to the Circle's Center

The problem at hand is to determine the closest point on a rectangle to the center of a circle. This is useful when checking if a circle and rectangle overlap. The rectangle is axis-aligned, and we are given the circle's center coordinates and radius. We need to compute the closest x and y coordinates on the rectangle to the circle's center.

### Problem Breakdown

Given:
- Circle's center: \((xc, yc)\)
- Circle's radius: \(r\)
- Rectangle corners: 
  - Bottom-left: \((x1, y1)\)
  - Top-right: \((x2, y2)\)

The goal is to find the closest point on the rectangle to the circle's center. This can be done by **clipping** the circle’s center to the boundaries of the rectangle.

### Intuition Behind Finding the Closest x-coordinate

1. **The x-coordinate of the circle’s center is `xc`**.
2. **The rectangle spans horizontally between `x1` and `x2`**.
3. We want the closest x-coordinate on the rectangle:
   - If `xc` is **inside** the rectangle (i.e., \(x1 \leq xc \leq x2\)), then the closest x is simply \(xc\).
   - If `xc` is **left of** the rectangle (i.e., \(xc < x1\)), then the closest x is \(x1\).
   - If `xc` is **right of** the rectangle (i.e., \(xc > x2\)), then the closest x is \(x2\).


# Example 1: Circle center inside rectangle
x1, x2 = 3, 7
y1, y2 = 3, 7
xc, yc = 5, 5
result1 = find_closest_point(x1, x2, y1, y2, xc, yc)
print(f"Example 1 - Circle center inside: {result1}")  # Expected: (5, 5)

# Example 2: Circle center left of rectangle
xc, yc = 2, 5
result2 = find_closest_point(x1, x2, y1, y2, xc, yc)
print(f"Example 2 - Circle center left: {result2}")   # Expected: (3, 5)

# Example 3: Circle center right of rectangle
xc, yc = 8, 5
result3 = find_closest_point(x1, x2, y1, y2, xc, yc)
print(f"Example 3 - Circle center right: {result3}")  # Expected: (7, 5)

# Additional test cases
# Circle center above rectangle
xc, yc = 5, 8
result4 = find_closest_point(x1, x2, y1, y2, xc, yc)
print(f"Example 4 - Circle center above: {result4}")  # Expected: (5, 7)

# Circle center below rectangle
xc, yc = 5, 2
result5 = find_closest_point(x1, x2, y1, y2, xc, yc)
print(f"Example 5 - Circle center below: {result5}")  # Expected: (5, 3)

"""
Explanation of the Formula:
- min(xc, x2): Ensures that if circle center is right of x2, closest point is x2
- max(x1, ...): Ensures that if circle center is left of x1, closest point is x1
- Same logic applies for y-coordinates

The formula efficiently handles all cases where the circle's center could be:
1. Inside the rectangle
2. Left/right of the rectangle
3. Above/below the rectangle
"""