class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(50, vector<bool>(50, false));
        vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> new_image = image;
        queue<pair<int, int>> unvisited_pixels;
        unvisited_pixels.push(pair<int, int>(sr, sc));
        while(!unvisited_pixels.empty()) {
            pair<int, int> pixel = unvisited_pixels.front();
            unvisited_pixels.pop();
            int row = pixel.first, col = pixel.second;
            new_image[row][col] = newColor;
            for(auto& neighbor : neighbors) {
                int child_row = row + neighbor.first, child_col = col + neighbor.second;
                if (child_row >= 0 && child_row < image.size() &&
                   child_col >= 0 && child_col < image[0].size() && 
                    !visited[child_row][child_col] && new_image[child_row][child_col] == image[sr][sc]) {
                    visited[child_row][child_col] = true;
                    unvisited_pixels.push(pair<int, int>(child_row, child_col));
                }
            }
        }
        return new_image;
    }
};