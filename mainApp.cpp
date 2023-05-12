#include <iostream>
#include "heap.cpp"
#include "BST.cpp"

using namespace std;

int menuMain() {
    int choice;
    cout << "1-BST\n"
            "2-AVL\n"
            "3-Min heap\n"
            "4-Max heap\n"
            "5-Exit\n";
    cin >> choice;
    return choice;
}

int menuBST() {
    int choice;
    cout << "1-Add Student\n"
            "2-Remove Student\n"
            "3-Search Student\n"
            "4-Print all (sorted by ID)\n"
            "5-Return to main menu\n";
    cin >> choice;
    return choice;
}

int main() {
    while (true) {
        int choice = menuMain();
        if (choice == 1) {
            BST obj;
            obj.loadStudents();
            while (true) {
                int x = menuBST();
                if (x == 1) {
                    string name, dept, id;
                    double gpa;
                    cout << "Name=\n";
                    cin.ignore();
                    getline(cin, name, '\n');
                    cout << "ID=\n";
                    cin >> id;
                    cout << "GPA=\n";
                    cin >> gpa;
                    cout << "Department=\n";
                    cin >> dept;
                    obj.addStudents(Student(name, id, gpa, dept));
                    cout << "Student added!" << endl;
                } else if (x == 2) {
                    string id;
                    cout << "Enter Student ID=";
                    cin >> id;
                    obj.delStud(id);
                    cout << "Student removed!" << endl;
                } else if (x == 3) {
                    string id;
                    cout << "Enter Student ID=";
                    cin >> id;
                    if (obj.searchStud(id) == nullptr) {
                        cout << "Student not found!" << endl;
                    } else {
                        cout << "Student found! Student info:" << endl;
                        cout << obj.searchStud(id)->data;
                    }
                } else if (x == 4) {
                    obj.printByID();
                } else if (x == 5) {
                    break;
                } else {
                    cout << "invalid input! please try again" << endl;
                }
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "invalid input! please try again" << endl;
        }
    }
}