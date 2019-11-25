/*效率 1 > 2 > 3*/
/*Solution1 暴力破解法*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size();++j){
                if(nums[i]+nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

/*Solution2 二次哈希*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tmpMap;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            tmpMap[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); ++i){
            int a;
            a = target - nums[i];
            if(tmpMap.count(a) && tmpMap[a] != i){
                res.push_back(i);
                res.push_back(tmpMap[a]);
                break;
            }
        }
        return res;
    }
};

/*Solution3 一次哈希*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tmpMap;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            if(tmpMap.count(nums[i]) != 0){
                res.push_back(tmpMap[nums[i]]);
                res.push_back(i);                
                break;
            }
            tmpMap[target - nums[i]] = i;
        }
        return res;
    }
};
