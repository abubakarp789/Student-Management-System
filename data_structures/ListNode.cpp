#include "ListNode.h"

ListNode::ListNode(const Student& student) : data(student), next(nullptr) {}

ListNode::~ListNode() {
    delete next;
}
