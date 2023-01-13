/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = l1;
        while(l1 && l2) {
            if(l1->val + l2->val >= 10) {
                if(l1->next) {
                    l1->next->val += (l1->val + l2->val) / 10;
                    l1->val = (l1->val + l2->val) % 10;
                } else {
                    ListNode* next_node = new ListNode();
                    next_node->val = (l1->val + l2->val) / 10;
                    l1->val = (l1->val + l2->val) % 10;
                    l1->next = next_node;
                }
            } else {
                l1->val = l1->val + l2->val;
            }
            if(l1->next == nullptr && l2->next != nullptr) {
                while(l2) {
                    l2 = l2->next;
                    l1->next = l2;
                    l1 = l1->next;
                }
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1) {
            while (l1->next) {
                if(l1->val >= 10) {
                    l1->next->val += l1->val / 10;
                    l1->val = l1->val % 10;
                }
                l1 = l1->next;
            }
            if(l1->val >= 10) {
                ListNode* next_node = new ListNode();
                next_node->val = l1->val / 10;
                l1->val %= 10;
                l1->next = next_node;
            }
        }

        return curr;
    }
};