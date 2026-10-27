#include <iostream>
#include <vector>
using namespace std;

int N = 8;
int cx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int cy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
bool limits(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N);
}
bool isempty(vector<vector<int>>& a, int x, int y) {
    return (limits(x, y) && a[x][y] == -1);
}
int getDegree(vector<vector<int>>& a, int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (isempty(a, x + cx[i], y + cy[i])) {
            count++;
        }
    }
    return count;
}
bool nextMove(vector<vector<int>>& a, int& x, int& y) {
    int min_deg_idx = -1;
    int min_deg = 9; 
    for (int i = 0; i < 8; ++i) {
        int nx = x + cx[i];
        int ny = y + cy[i];
        
        if (isempty(a, nx, ny)) {
            int c = getDegree(a, nx, ny);
            if (c < min_deg) {
                min_deg_idx = i;
                min_deg = c;
            }
        }
    }
    if (min_deg_idx == -1) return false;

    x = x + cx[min_deg_idx];
    y = y + cy[min_deg_idx];
    return true;
}
void findTour() {
    vector<vector<int>> a(N, vector<int>(N, -1));
    int x = 0, y = 0;
    a[x][y] = 1;
    for (int i = 2; i <= N * N; ++i) {
        if (!nextMove(a, x, y)) {
            cout << "No complete tour found." << endl;
            return;
        }
        a[x][y] = i; 
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    findTour();
    return 0;
}