#include <vector>

using namespace std;




class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here

        int leftSum = 0, rightSum = 0;
        int totalSum = 0;

        for(auto elem : arr)totalSum+=elem;

        for(auto i = 0; i < arr.size(); i++){
            // totalSum = leftSum + arr[i] + rightSum;
            // rightSum = totalsum - arr[i] - leftSum;
            rightSum = totalSum - arr[i] - leftSum;
            if(rightSum == leftSum){
                return i;
            }
            leftSum += arr[i];
        }
        return -1;
    }
};