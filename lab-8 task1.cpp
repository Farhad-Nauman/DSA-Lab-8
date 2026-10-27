#include <iostream>
#include <vector>
using namespace std;

int findMaxInColumn(const vector<vector<int>>& mat, int rows, int mid, int& maxRow) {
    int maxVal = mat[0][mid];
    maxRow = 0;
    for (int i = 1; i < rows; i++) {
        if (mat[i][mid] > maxVal) {
            maxVal = mat[i][mid];
            maxRow = i;
        }
    }
    return maxVal;
}
vector<int> findPeak(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int left = 0, right = cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int maxRow = 0;
        findMaxInColumn(mat, rows, mid, maxRow);

        bool isLeftGreater = (mid - 1 >= left && mat[maxRow][mid - 1] > mat[maxRow][mid]);
        bool isRightGreater = (mid + 1 <= right && mat[maxRow][mid + 1] > mat[maxRow][mid]);

        if (!isLeftGreater && !isRightGreater) {
            return {maxRow, mid, mat[maxRow][mid]};
        } else if (isLeftGreater) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return {-1, -1, -1};
}
int main() {
    vector<vector<int>> mat = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };
    vector<int> result = findPeak(mat);
    cout << "Peak element is " << result[2] << " at (" << result[0] << ", " << result[1] << ")" << endl;
    return 0;
}