#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool{
            return a[1] < b[1];
        });
        int maxLocal = intervals[0][1];
        int count = 0;
        
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < maxLocal){
                count++;
            }else{
                maxLocal = intervals[i][1];
            }
        }
        return count;
    }
};