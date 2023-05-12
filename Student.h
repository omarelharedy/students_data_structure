#ifndef INC_3_STUDENT_H
#define INC_3_STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    string id;
    double gpa;
    string department;
public:
    Student() = default;

    Student(string name, string id, double gpa, string department) {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
        this->department = department;
    }

    Student(nullptr_t pVoid) {}

    bool operator<(const Student &other) const {
        return this->gpa < other.gpa;
    }

    bool operator>(const Student &other) const {
        return this->gpa > other.gpa;
    }

    Student &operator=(const Student &other) {
        this->name = other.name;
        this->id = other.id;
        this->gpa = other.gpa;
        this->department = other.department;
        return *this;
    }

    const string &getId() const {
        return id;
    }

    friend ostream &operator<<(ostream &out, const Student &stdu) {
        out << stdu.name << endl;
        out << stdu.id << endl;
        out << stdu.gpa << endl;
        out << stdu.department << endl;
        return out;
    }
};

#endif //INC_3_STUDENT_H
