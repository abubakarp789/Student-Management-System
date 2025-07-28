#include "Student.h"

Student::Student() : rollNumber(0), name(""), courses(""), grades(0.0) {}

Student::Student(int roll, const std::string& n, const std::string& c, float g) 
    : rollNumber(roll), name(n), courses(c), grades(g) {}
