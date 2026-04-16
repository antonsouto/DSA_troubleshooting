#include <vector>
using namespace std;




class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            int top = 0; 
            int bottom = n - 1;
            while(top < bottom){
                swap(mat[top][i], mat[bottom][i]);
                top++;
                bottom--;
            }
        }
    }
};