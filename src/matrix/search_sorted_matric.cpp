#include <vector>
using namespace std;




class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> flatMatrix;
        
        for(auto i : mat){
            for(auto j : i){
                flatMatrix.push_back(j);
            }
        }
        
        int low = 0;
        int high = n*m - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(flatMatrix[mid] < x){
                low = mid + 1;
            }else if(flatMatrix[mid] > x){
                high = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};