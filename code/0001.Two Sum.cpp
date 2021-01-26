给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*效率 1 > 2 > 3*/
```
/*Solution1 暴力破解法*/
[C++]
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
[C]
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = NULL;
    for(int i = 0; i < numsSize - 1; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            if(nums[i] + nums[j] == target){
                result = (int*)malloc(sizeof(int)*2);
                result[0] = i;
                result[1] = j;
                *returnSize=2;
                return result;
            }
        }
    }
    return result;
}

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
```
