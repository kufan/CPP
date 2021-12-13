// 题目链接 https://leetcode-cn.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
struct ListNode {
    int val;  // 数据域
    ListNode* next;  // 指针域

    // 构造函数
    ListNode() {
        val  = 0;
        next = nullptr;   // NULL
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* ne) {
        val = x;
        next = ne; 
    }
};
*/

// 1、从低位开始，往高位的方向做加法，如果需进位: 低位保留个位，高位+1
// 2、最高位也需要进位: 在跟高位补充一个节点即可
// 技巧: 方便处理边界  添加一个虚拟节点
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);  // 添加虚拟节点，作为头节点
        ListNode* cur = res;  // cur 指针用来指向当前节点
        int carry = 0;   // 表示进位

        // nullptr   NULL  --> 都可以表示假
        while(l1 || l2) {  // 两条链表，但凡有一条不为空，那么加法继续
            // l1 是否为 null, 如果到了链表的末尾，则用 0 表示
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int sum = n1 + n2 + carry;
            carry = sum / 10;

            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }        

        // 最高的两个数相加之后，是否还需要进位
        if(carry) {
            cur->next = new ListNode(1);
        }

        return res->next;  // 返回头节点即可
    }
};