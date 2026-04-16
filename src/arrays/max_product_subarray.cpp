#include <vector>
#include <climits>
using namespace std;


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int localProduct = 1;
        int localMaxIzq = INT_MIN;
        int localMaxDrch = INT_MIN;
        
        for(int i = 0; i < arr.size(); ++i){
            localProduct *= arr[i];
            if(localProduct == 0){
                if(localMaxIzq < 0){
                    localMaxIzq = 0;
                }
                localProduct = 1;
                continue;
            }
            if(localProduct > localMaxIzq){
                localMaxIzq = localProduct;
            }
        }
        
        localProduct = 1;
        
        for(int i = arr.size() - 1; i >= 0; --i){
            localProduct *= arr[i];
            if(localProduct == 0){
                if(localMaxDrch < 0){
                    localMaxDrch = 0;
                }
                localProduct = 1;
                continue;
            }
            if(localProduct > localMaxDrch){
                localMaxDrch = localProduct;
            }
        }
        
        return localMaxIzq > localMaxDrch ? localMaxIzq : localMaxDrch;
    }
};