#include <vector>
#include <algorithm>
using namespace std;




class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int> solution;
        // Control tamaños pequeños
        if(arr.size()<2){
            return solution;
        }

        sort(arr.begin(), arr.end());
        int left = 0;
        int right = arr.size() - 1;
        int absoluteDistance = __INT_MAX__;
        int auxDistance = __INT_MAX__;  
        while(left < right){

            if(arr[left] + arr[right] == target){
                if(solution.size()){
                        solution.clear();
                    }
                solution.push_back(arr[left]);
                solution.push_back(arr[right]);
                return solution;
            }

            if(arr[left] + arr[right] < target){
                auxDistance = abs(target - (arr[left] + arr[right]));
                if(auxDistance < absoluteDistance){
                    // Tengo que vaciar el vector
                    absoluteDistance = auxDistance;
                    if(solution.size()){
                        solution.clear();
                    }
                    solution.push_back(arr[left]);
                    solution.push_back(arr[right]);
                }
                left++;
            }else if(arr[left] + arr[right] > target){
                auxDistance = abs(target - (arr[left] + arr[right]));
                if(auxDistance < absoluteDistance){
                    // Tengo que vaciar el vector
                    absoluteDistance = auxDistance;
                    if(solution.size()){
                        solution.clear();
                    }
                    solution.push_back(arr[left]);
                    solution.push_back(arr[right]);
                }
                right--;
            }

        }
        return solution;
    }
};