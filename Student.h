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
    Student(Student const &other){
        this->name = other.name;
        this->gpa=other.gpa;
        this->id=other.id;
        this->department = other.department;
    };
    Student& operator = (Student const &other){
        this->name = other.name;
        this->gpa=other.gpa;
        this->id=other.id;
        this->department = other.department;
        return *this;
    }
    Student(string name, string id, double gpa, string department) {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
        this->department = department;
    }

    const string &getDepartment() const {
        return department;
    }

    Student(nullptr_t pVoid) {}

    bool operator<(const Student &other) const {
        return this->gpa < other.gpa;
    }

    bool operator>(const Student &other) const {
        return this->gpa > other.gpa;
    }

    const string &getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    const double &getGPA() const {
        return gpa;
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
