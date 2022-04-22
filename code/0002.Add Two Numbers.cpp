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
