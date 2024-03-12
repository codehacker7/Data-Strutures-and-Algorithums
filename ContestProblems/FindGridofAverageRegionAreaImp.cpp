#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<vector<int>>> resultSet(n, vector<vector<int>>(m));
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int sum = 0;
                bool isRegion = true;
                
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        sum += image[k][l];
                        if (k > i && abs(image[k][l] - image[k - 1][l]) > threshold) isRegion = false;
                        if (l > j && abs(image[k][l] - image[k][l - 1]) > threshold) isRegion = false;
                    }
                }
                
                if (isRegion) {
                    for (int k = i; k < i + 3; k++) {
                        for (int l = j; l < j + 3; l++) {
                            resultSet[k][l].push_back(sum / 9);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> result = image;
                
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!resultSet[i][j].empty()) {
                   result[i][j] = accumulate(begin(resultSet[i][j]), end(resultSet[i][j]), 0) / resultSet[i][j].size();

                }
            }
        }
        
        return result;
    }
};
