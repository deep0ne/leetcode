/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int index = 0;
        std::deque<ListNode*> nodes;
        if(head->next == nullptr || head == nullptr) {
            return head;
        }

        while(head != nullptr) {
            if(head->next) {
                nodes.push_back(head->next);
            }
            head = head->next;
            ++index;
        }

        int mid = index / 2 - 1;
        return nodes[mid];
        
    }
};