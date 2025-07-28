#include "TreeNode.h"

TreeNode::TreeNode(int rollNumber, const std::string& name) 
    : data({rollNumber, name, "", 0.0}), left(nullptr), right(nullptr) {}
