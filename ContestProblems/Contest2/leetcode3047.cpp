#define ll long long

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        ll area = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ll minX = max(bottomLeft[i][0], bottomLeft[j][0]);
                ll maxX = min(topRight[i][0], topRight[j][0]);  // Corrected this line

                ll minY = max(bottomLeft[i][1], bottomLeft[j][1]);  // Corrected this line
                ll maxY = min(topRight[i][1], topRight[j][1]);
                
                if(minX < maxX && minY < maxY){
                    ll side = min(maxX - minX, maxY - minY);
                    area = max(area, side * side);
                }
            }
        }
        
        return area;
    }
};
