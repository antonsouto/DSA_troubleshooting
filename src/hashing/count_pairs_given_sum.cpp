#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int> frequency;
        int complement;
        int count = 0;
        // (1,1,1,1)
        for(auto elem : arr){
            complement = target - elem;
            if(frequency.find(complement) != frequency.end()){
                count += frequency[complement];
            }
            if(frequency.find(elem) != frequency.end()){
                frequency[elem]++;
            }else{
                frequency[elem] = 1;
            }
        }
        return count;
    }
};