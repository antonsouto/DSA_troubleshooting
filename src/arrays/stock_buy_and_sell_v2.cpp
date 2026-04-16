#include <vector>
using namespace std;



class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0;
        int minPrice = prices[0];
        
        
        if(prices.size() < 2){
            return 0;
        }
        
        for(int i = 1; i < prices.size(); ++i){
            int profit = prices[i] - minPrice;
            
            maxProfit = max(maxProfit, profit);
            
            minPrice = min(minPrice, prices[i]);
        }

      return maxProfit;
    }
};