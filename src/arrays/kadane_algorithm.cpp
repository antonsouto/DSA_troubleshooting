#include <vector>
using namespace std;




class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxSum = arr[0];
        int actualSum = 0;
        //[-20, -5, 28, -28, 17, -12]
        for(int i = 0; i < arr.size(); ++i){
            actualSum += arr[i];
            if(actualSum > maxSum){
                maxSum = actualSum;
            }
            if(actualSum < 0){
                actualSum = 0;
                continue;
            }
        }
        return maxSum;
    }
};