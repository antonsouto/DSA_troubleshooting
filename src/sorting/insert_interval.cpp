#include <vector>
using namespace std;




class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<int> aux;
        vector<vector<int>> solucion;
        bool insertado = false;
        
        for(int i = 0; i < intervals.size(); ++i){
            // Intervalo antes de el nuevo completamente 
            if(intervals[i][1] < newInterval[0]){
                solucion.push_back(intervals[i]);
            }
            
            // Caso 2: Solape 
            else if(intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            
            else if(intervals[i][0] > newInterval[1]){
                solucion.push_back(newInterval);
                insertado = true;
                for(int j = i;j < intervals.size();++j){
                    solucion.push_back(intervals[j]);
                }
                break;
            }
            
        }
        
        if(!insertado){
            solucion.push_back(newInterval);
        }
        
        return solucion;
    }
};