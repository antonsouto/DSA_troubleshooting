#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int>complementos;
        int newComplemento;
        // bool respuesta = false;

        for(auto elem: arr){
            newComplemento = target - elem;
            if(complementos.find(elem) != complementos.end()){
                return true;
            }else{
                complementos.insert(newComplemento);
            }
        }
        return false;
    }
};