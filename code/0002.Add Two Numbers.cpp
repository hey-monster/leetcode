给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *lTmp = new ListNode(0);
        int sum = 0;
        ListNode *cur= lTmp;
        ListNode *p1 = l1, *p2 = l2;
        while((p1 != NULL)||(p2 != NULL)){
            if(p1 != NULL){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL){
                sum += p2->val;
                p2 = p2->next;                
            }
            cur->next = new ListNode(0);
            cur = cur->next;            
            cur->val = sum%10;
            sum = sum/10;
        }
        if(sum){
            cur->next = new ListNode(sum);
        }
        return lTmp->next;
    }
};


/*使用下面的写法耗时减少接近50%*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};
```
[C]
第二次做
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = -1;
    head->next = NULL;
    struct ListNode* ret = head;
    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    int out = 0;
    while(tmp1 != NULL || tmp2 != NULL){
        int sum = 0;
        if(tmp1 != NULL){
            sum += tmp1->val;
            tmp1 = tmp1->next;
        }
        if(tmp2 != NULL){
            sum += tmp2->val;
            tmp2 = tmp2->next;
        }
        sum += out;
        if(sum > 9){
            sum = sum % 10;
            out = 1;
        }else{
            out = 0;
        }
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = sum;
        cur->next = NULL;
        head->next = cur;
        head = head->next;
    }
    if(out != 0){
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next = NULL;
        cur->val = 1;
        head->next = cur;
        head = head->next;
    }
    return ret->next;
}
```
