#include <iostream>
#include <functional>

struct TreeNode {
    // TreeNode definition
};

class Defer {
public:
    Defer(std::function<void()> func) : func_(func) {}
    ~Defer() { func_(); }

private:
    std::function<void()> func_;
};

// ## 链接宏，链接x和y，不能写成xy。否则会寻找名为xy的变量。

#define CONCATENATE(x, y) x##y
#define DEFER(func) Defer CONCATENATE(defer_, __LINE__) ([&]() { func; })
// __LINE__行号

void deleteTreeNode(TreeNode* node) {
    // Implement the tree node deletion logic here
    delete node;
}

int main() {
    TreeNode* root = new TreeNode();
    // Do operations with root

    DEFER(deleteTreeNode(root));

    // The rest of your code
    // Root will be deleted when leaving the scope
    return 0;
}
