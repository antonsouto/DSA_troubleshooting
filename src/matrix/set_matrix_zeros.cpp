#include <vector>
using namespace std;




class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        bool firstRowZero = false;
        bool firstColumnZero = false;
        
        for(int i = 0; i < mat[0].size(); ++i){
        
            if(mat[0][i] == 0){
                firstRowZero = true;
            }
        }
        for(int j = 0; j < mat.size(); ++j){
        
            if(mat[j][0] == 0){
                firstColumnZero = true;
            }
        }
        
        for(int i = 1; i < mat.size(); ++i){
            for(int j = 1; j < mat[0].size(); ++j){
                if(mat[i][j] == 0){
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                
                }
            }
        }
        
        for(int i = 1; i < mat.size(); ++i){
            for(int j = 1; j < mat[0].size(); ++j){
                if(mat[0][j] == 0 || mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < mat[0].size(); ++i){
            if(firstRowZero){
                    mat[0][i] = 0;
            }
        }
        
        for(int j = 0; j < mat.size(); ++j){
            if(firstColumnZero){
                    mat[j][0] = 0;
            }
        }
        
    }
};