#include <vector>
#include <climits>
using namespace std;




class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int localAcum = 0;
        int circularAcum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int total = 0;

        
        
        for(int x : arr){
            total += x;
            
            // Bloque máximo
            localAcum = max(x, x + localAcum);
            maxSum = max(localAcum, maxSum);
            
            
            // Bloque mínimo
            circularAcum = min(x, x + circularAcum);
            minSum = min(circularAcum, minSum);
            

        }
            
        if(total == minSum){
            return maxSum;
        }else{
            return max(maxSum, total - minSum);
        }
    }
};