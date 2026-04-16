#include <vector>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        int r = 0, c = cols - 1;
        
        while(r < rows && c >= 0){
            if(mat[r][c]==x){
                return true;
            }else if(mat[r][c] > x){
                c--;
                if(c < 0){
                   r++;
                   c = cols - 1;
                }
            }else{
                r++;
                c = cols - 1;
            }
        }
        return false;
    }
};