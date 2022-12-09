/*
Given the head of a singly linked list, return true if it is a
palindrome
or false otherwise.
*/

#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> elements;
        while(head) {
            elements.push_back(head->val);
            head = head->next;
        }

        int i = 0, j = elements.size() - 1;
        while(i < j) {
            if(elements[i] != elements[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};