// 题目: https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 循环遍历数组 nums,每一步的循环中，做两个事:
        // 1、判断 target - num[i] 的结果是否在 哈希表 中
        // 2、将 nums[i] 插入到 哈希表中
        vector<int> res;

        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];

            // count() 的结果，要么 1/0
            if(hash.count(another)) {
                // 映射类容器，都可以当作数组操作
                // 容器[key] = val
                res = vector<int>({hash[another], i});
                break;
            }

            // 每个元素进入 hash 表
            // key： nums[i]       val： i
            hash[nums[i]] = i;
        } 

        return res;
    }
};