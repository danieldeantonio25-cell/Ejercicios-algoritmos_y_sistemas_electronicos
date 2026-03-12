#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> mapa_indices;
        
        for (int i = 0; i < nums.size(); i++) {
            int complemento = target - nums[i];
            
            
            if (mapa_indices.find(complemento) != mapa_indices.end()) {
                return {mapa_indices[complemento], i};
            }
            
            
            mapa_indices[nums[i]] = i;
        }
        
        return {};
    }
};
