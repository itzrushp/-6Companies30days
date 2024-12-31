#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to smooth the image using a 3x3 filter
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Initialize the answer matrix with the same size as img, filled with 0
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));

        // Loop through each cell of the input image
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = 0;    // To store the sum of the cell values in the 3x3 grid
                int count = 0;  // To count the number of valid cells in the 3x3 grid

                // Loop through the 3x3 grid centered at (i, j)
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        // Check if the cell (r, c) is within the bounds of the image
                        if (r >= 0 && r < img.size() && c >= 0 && c < img[0].size()) {
                            count++;          // Increment the count of valid cells
                            sum += img[r][c]; // Add the value of the cell to the sum
                        }
                    }
                }

                // Calculate the smoothed value as the average of valid cells
                int val = sum / count;

                // Assign the smoothed value to the corresponding cell in the answer matrix
                ans[i][j] = val;
            }
        }

        return ans; // Return the smoothed image
    }
};

// Helper function to print a 2D vector (matrix)
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Main function to test the image smoother
int main() {
    // Example input image
    vector<vector<int>> img = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };

    cout << "Input Image:" << endl;
    printMatrix(img);

    // Create a Solution object and apply the image smoother
    Solution solution;
    vector<vector<int>> smoothedImg = solution.imageSmoother(img);

    // Print the resulting smoothed image
    cout << "Smoothed Image:" << endl;
    printMatrix(smoothedImg);

    return 0;
}
