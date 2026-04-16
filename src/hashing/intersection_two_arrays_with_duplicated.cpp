#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> primero;
        vector<int> sol;
        for(auto elem: a){
            primero.insert(elem);
        }
        for(auto elem: b){
            auto it = primero.find(elem);
            if(it != primero.end()){
                sol.push_back(elem);
                primero.erase(elem);
            }
        }
        return sol;
    }
};