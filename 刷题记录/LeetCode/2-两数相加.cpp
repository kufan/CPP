// ��Ŀ���� https://leetcode-cn.com/problems/add-two-numbers/
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
    int val;  // ������
    ListNode* next;  // ָ����

    // ���캯��
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

// 1���ӵ�λ��ʼ������λ�ķ������ӷ���������λ: ��λ������λ����λ+1
// 2�����λҲ��Ҫ��λ: �ڸ���λ����һ���ڵ㼴��
// ����: ���㴦��߽�  ���һ������ڵ�
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);  // �������ڵ㣬��Ϊͷ�ڵ�
        ListNode* cur = res;  // cur ָ������ָ��ǰ�ڵ�
        int carry = 0;   // ��ʾ��λ

        // nullptr   NULL  --> �����Ա�ʾ��
        while(l1 || l2) {  // ��������������һ����Ϊ�գ���ô�ӷ�����
            // l1 �Ƿ�Ϊ null, ������������ĩβ������ 0 ��ʾ
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

        // ��ߵ����������֮���Ƿ���Ҫ��λ
        if(carry) {
            cur->next = new ListNode(1);
        }

        return res->next;  // ����ͷ�ڵ㼴��
    }
};