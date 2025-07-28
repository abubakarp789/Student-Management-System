#pragma once
#include "Student.h"

class ListNode {
public:
    Student data;
    ListNode* next;

    ListNode(const Student& student);
    ~ListNode();
};
