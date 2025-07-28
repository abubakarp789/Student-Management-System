#pragma once
#include "Student.h"

class TreeNode {
public:
    Student data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int rollNumber, const std::string& name);
};
