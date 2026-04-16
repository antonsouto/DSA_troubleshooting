#include <vector>
#include <algorithm>
using namespace std;





bool canPlace(const vector<int> &stalls, const int dist, const int n);

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls.back() - stalls.front();
        
        int respuesta = 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(!canPlace(stalls, mid, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
                respuesta = mid;
            }
            
        }
        return respuesta;
    }
};


bool canPlace(const vector<int> &stalls, const int dist, const int n){
    
    int offset = 0;
    int placed = 1;
    int lastPos = stalls[0];
    
    
    for(int i = 1; i < n; ++i){

        auto iterBegin = stalls.begin() + offset + 1;
        
        if(iterBegin >= stalls.end()){
            return false;
        }
        auto it = find_if(iterBegin, stalls.end(), 
            [&dist, &lastPos](const int &x)->bool{
                return x - lastPos >= dist;
            });
        
        if(it == stalls.end()){
            return false;
        }
        
        // Colocamos la puta vaca
        lastPos = *it;
        offset = distance(stalls.begin(), it);
        placed++;
    }
    return placed == n;
}