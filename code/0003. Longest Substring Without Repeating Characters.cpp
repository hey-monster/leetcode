### 解题思路
此处撰写解题思路
思路1：
求一字符串，最大的无重复字符的子字符串长度，首先想到的是先从start开始，end往后走，找到重复字符记录下长度，start往后移动一下，再重复过程
思路2：
思路1计算量可能有点大，类似两数相加，可以像一个滑窗一样将整个字符串遍历一遍，记录滑窗的最大长度。
构建一张hash表，每个字符的最后一次出现位置对应一个位置。定义start/end，对应滑窗的前后边界，如果在滑窗右边界的一个字符是在hash中找到对应的值则将其更新为新值，左边界start指向旧值右边的字符，并计算end-start的值更新到result里面。
### 代码


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        int start = -1;
        unordered_map<int, int> m;
        for(int end=0; end<n; ++end){
            if(m.count(s[end])&& m[s[end]]> start){
                start = m[s[end]];
            }
            m[s[end]] = end;
            res = max(res, end-start);
        }
        return res;
    }
};
