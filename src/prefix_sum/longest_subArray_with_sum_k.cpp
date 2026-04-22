#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;



class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here

        unordered_map<int,int> acumulatedIndex;
        int neededSum;
        int solution = 0;
        int acumulated = 0;
        for(auto i = 0; i < arr.size(); i++){
            acumulated += arr[i];
            if(acumulated == k && solution < (i + 1)){
                solution = (i + 1);
            }
            neededSum = acumulated - k;
            
            if(acumulatedIndex.find(neededSum) != acumulatedIndex.end()){
                int l = acumulatedIndex[neededSum];
                if(solution < (i - l)){
                    solution = (i - l);
                }
            }else{
                if(acumulatedIndex.find(acumulated) == acumulatedIndex.end()){
                    acumulatedIndex[acumulated] = i;
                }
            }
        }
        return solution;
    }
};