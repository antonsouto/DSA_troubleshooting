#include <vector>
using namespace std;



class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            for(int j = 1; j < prices.size(); j++){
                if(prices[i] < prices[j]){
                    maxProfit += (prices[j] - prices[i]);
                }
                i = j;
            }
        }
        
        return maxProfit;
    }
};