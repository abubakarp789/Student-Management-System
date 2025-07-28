#pragma once
#include <string>

class Student {
public:
    int rollNumber;
    std::string name;
    std::string courses;
    float grades;

    Student();
    Student(int roll, const std::string& n, const std::string& c, float g);
};
