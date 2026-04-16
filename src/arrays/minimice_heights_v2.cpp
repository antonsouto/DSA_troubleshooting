#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        if(arr.empty()){
            return 0;
        }
        if(arr.size() == 1){
            return 0;
        }
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int average = arr.back() - arr.front();
        int maximum = arr.back() - k;
        int minimum = arr.front() - k;
        int localHeight = average;
        
        for(int i = 1; i < arr.size(); ++i){
            if((arr[i] - k) < 0){continue;} 
            int minH = min(arr[0] + k, arr[i] - k);
            int maxH = max(arr[n-1] - k, arr[i-1] + k);
            localHeight = min(localHeight, maxH - minH);
        }
        

        return localHeight;
    }
};