#include <iostream>
#include "heap.cpp"
#include "BST.cpp"
#include "AVL.cpp"
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

int BST_AVLMenu() {
    int choice;
    cout << "1-Add Student\n"
            "2-Remove Student\n"
            "3-Search Student\n"
            "4-Print all (sorted by ID)\n"
            "5-Return to main menu\n";
    cin >> choice;
    return choice;
}
int maxHeapMenu() {
    int choice;
    cout << "1-Add Student\n"
            "2-Print all (sorted by GPA)\n"
            "3-Return to main menu\n";
    cin >> choice;
    return choice;
}
int minHeapMenu() {
    int choice;
    cout << "1-Add Student\n"
            "2-Print all (sorted by GPA)\n"
            "3-Return to main menu\n";
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
                int x = BST_AVLMenu();
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
                    obj.printTheCountDepStudents();
                } else if (x == 5) {
                    break;
                } else {
                    cout << "invalid input! please try again" << endl;
                }
            }
        }else if(choice==2) {
            AVL obj;
            obj.loadStudents();
            while (true) {
                int x = BST_AVLMenu();
                if (x == 1) {
                    obj.addStudent();
                    cout << "Student added!" << endl;
                } else if (x == 2) {
                    obj.delStud();
                    cout << "Student removed!" << endl;
                } else if (x == 3) {
                    obj.searchStudent();
                } else if (x == 4) {
                    obj.printStudents();
                    obj.printTheCountDepStudents();
                } else if (x == 5) {
                    break;
                } else {
                    cout << "invalid input! please try again" << endl;
                }
            }
        }else if(choice==3){
            minheap<Student>obj("inputFile.txt",100);
            obj.heapSort(obj.size());
            while (true) {
                int x = minHeapMenu();
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
                    obj.min_insert(Student(name, id, gpa, dept));
                    cout << "Student added!" << endl;
                    obj.heapSort(obj.size());
                } else if (x == 2) {;
                    obj.print();
                    obj.printTheCountDepStudents();
                    cout<<endl;
                } else {
                    cout << "invalid input! please try again" << endl;
                    break;
                }
            }
        }else if(choice==4) {
            maxheap<Student> obj("inputFile.txt", 100);
            obj.heapSort(obj.size());
            while (true) {
                int x = maxHeapMenu();
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
                    obj.max_insert(Student(name, id, gpa, dept));
                    cout << "Student added!" << endl;
                    obj.heapSort(obj.size());
                } else if (x == 2) {
                    obj.print();
                    obj.printTheCountDepStudents();
                    cout << endl;
                } else {
                    cout << "invalid input! please try again" << endl;
                    break;
                }
            }
        }
        else if (choice == 5) {
            break;
        } else {
            cout << "invalid input! please try again" << endl;
        }
    }
}