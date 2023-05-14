#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

class Node {
public:
    Student data;
    Node *left;
    Node *right;
    int height;

    Node() {
        left = right = nullptr;
        data = nullptr;
        height = 0;
    }

    Node(Student &ele, Node *left, Node *right) {
        this->data = ele;
        this->left = left;
        this->right = right;
        this->height = 0;
    }


};

class AVL {
private:
    Node *root;
    vector<string> openFile() {
        vector<string> arr;
        string text, token;
        fstream file;
        file.open("inputFile.txt");
        getline(file, text, '\0');
        for (int i = 0; i <= text.length(); ++i) {
            if (text[i] == '\n' || i == text.length()) {
                arr.push_back(token);
                token = "";
            } else {
                token += text[i];
            }
        }
        return arr;
    }
    Node *leftMost(Node *x) {
        Node *curr = x;
        while (curr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }
    void printStudents(Node *node) {
        if (node == nullptr) {
            return;
        }
        printStudents(node->left);
        cout << node->data << endl;
        printStudents(node->right);
    }
    Node *del(Node *pNode, const string &id) {
        if (pNode == nullptr) {
            return pNode;
        }
        if (id< pNode->data.getId()) {
            pNode->left = del(pNode->left, id);
        } else if (pNode->data.getId()< id) {
            pNode->right = del(pNode->right, id);
        } else {
            if (pNode->right == nullptr && pNode->left == nullptr) {
                return nullptr;
            } else if (pNode->left == nullptr) {
                Node *tmp = pNode->right;
                delete pNode;
                return tmp;
            } else if (pNode->right == nullptr) {
                Node *tmp = pNode->left;
                delete pNode;
                return tmp;
            } else {
                Node *tmp = leftMost(pNode->right);
                pNode->data = tmp->data;
                pNode->right = del(pNode->right, tmp->data.getId());
            }
        }
        return pNode;
    }
    Node *insertHelper(Node *node, Student ele) {
        if (node == nullptr) {
            node = new Node(ele, nullptr, nullptr);
        } else if (ele.getId() < node->data.getId()) {
            node->left = insertHelper(node->left, ele);
            if (getHeight(node->left) - getHeight(node->right) == 2) {
                if (ele < node->left->data) {
                    singleRotation(node, false);
                } else {
                    doubleRotation(node, false);
                }
            }
        } else if (ele.getId() > node->data.getId()) {
            node->right = insertHelper(node->right, ele);
            if (getHeight(node->right) - getHeight(node->left) == 2) {
                if (ele > node->right->data) {
                    singleRotation(node, true);
                } else {
                    doubleRotation(node, true);
                }
            }
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        return node;
    }
    void insert(Student ele) {
        root = insertHelper(root, ele);
    }
    void singleRotation(Node *&node, bool isLeft) {
        Node *temp = nullptr;
        if (isLeft) {
            temp = node->right;
            node->right = temp->left;
            temp->left = node;
        } else {
            temp = node->left;
            node->left = temp->right;
            temp->right = node;
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
        node = temp;
    }

    void doubleRotation(Node *&node, bool isLeft) {
        if (isLeft) {
            singleRotation(node->right, false);
            singleRotation(node, true);
        } else {
            singleRotation(node->left, true);
            singleRotation(node, false);
        }
    }
    int getHeight(Node *node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

public:
    AVL() {
        root = nullptr;
    }

    Node *getRoot() {
        return root;
    }
    void loadStudents() {
        vector<string> temp = openFile();
        Student st(temp[0], temp[1], stod(temp[2]), temp[3]);
        root = new Node(st, nullptr, nullptr);
        for (int i = 4; i < temp.size(); i += 4) {
            Student st1(temp[i], temp[i + 1], stod(temp[i + 2]), temp[i + 3]);
            insert(st1);
        }
    }

    void searchStudent(){
        string id;
        cout << "Enter the id of the student you want to search for: ";
        cin >> id;
        Node *temp = root;
        while (temp != nullptr) {
            if (temp->data.getId() == id) {
                cout << temp->data << endl;
                return;
            } else if (temp->data.getId() > id) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        cout << "Student not found" << endl;
    }
    bool SearchStudent(string id){
        Node *temp = root;
        while (temp != nullptr) {
            if (temp->data.getId() == id) {
                return true;
            } else if (temp->data.getId() > id) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return false;

    }
    void addStudent(){
        string name, id, major;
        double gpa;
        cout<<"Enter the name of the student: ";
        cin.ignore();
        getline(cin, name, '\n');
        cout<<"Enter the id of the student: ";
        cin>>id;
        cout<<"Enter the gpa of the student: ";
        cin>>gpa;
        cout<<"Enter the major of the student: ";
        cin>>major;
        Student st(name, id, gpa, major);
        insert(st);
    }
    void delStud() {
        string id;
        cout<<"Enter the id of the student you want to delete: ";
        cin>>id;
        if(!SearchStudent(id) ){
            cout<<"Student not found"<<endl;
            return;
        }
        root = del(root, id);
        cout<<"Student deleted\n"<<endl;
    }

    void printStudents() {
        printStudents(root);
    }
};