struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;
  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;


int Solution(const Node* root) {
    if(!root) {
        return 0;
    }
    int max_value = root->value;
    if(root->left) {
        int left_num = Solution(root->left);
        max_value = std::max(max_value, left_num);
    }
    if(root->right) {
        int right_num = Solution(root->right);
        max_value = std::max(max_value, right_num);
    }
    return max_value;
}

void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, &node3, nullptr});
    assert(Solution(&node4) == 3);
}

int main() {
  test();
}
