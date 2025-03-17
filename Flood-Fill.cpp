#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

void dfs(vector<vector<int>> &image, int r, int c, int originalColor, int newColor) {
    if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != originalColor)
        return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, originalColor, newColor);
    dfs(image, r - 1, c, originalColor, newColor);
    dfs(image, r, c + 1, originalColor, newColor);
    dfs(image, r, c - 1, originalColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor)
        return image;

    dfs(image, sr, sc, originalColor, newColor);
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    for (const auto &row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

};