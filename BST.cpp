#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

struct BST_Node {
    Student data;
    BST_Node *left;
    BST_Node *right;

    BST_Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    BST_Node *root;

    void print(BST_Node *x) {
        if (x != nullptr) {
            print(x->left);
            cout << x->data << "--------------------" << endl;
            print(x->right);
        }
    }

    BST_Node *search(BST_Node *ptrNode, const string &id) {
        if (ptrNode == nullptr || ptrNode->data.getId() == id) {
            return ptrNode;
        }
        if (lessThan(ptrNode->data.getId(), id)) {
            return search(ptrNode->right, id);
        } else {
            return search(ptrNode->left, id);
        }
    }

    BST_Node *leftMost(BST_Node *x) {
        BST_Node *curr = x;
        while (curr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    BST_Node *del(BST_Node *pNode, const string &id) {
        if (pNode == nullptr) {
            return pNode;
        }
        if (lessThan(id, pNode->data.getId())) {
            pNode->left = del(pNode->left, id);
        } else if (lessThan(pNode->data.getId(), id)) {
            pNode->right = del(pNode->right, id);
        } else {
            if (pNode->right == nullptr && pNode->left == nullptr) {
                return nullptr;
            } else if (pNode->left == nullptr) {
                BST_Node *tmp = pNode->right;
                delete pNode;
                return tmp;
            } else if (pNode->right == nullptr) {
                BST_Node *tmp = pNode->left;
                delete pNode;
                return tmp;
            } else {
                BST_Node *tmp = leftMost(pNode->right);
                pNode->data = tmp->data;
                pNode->right = del(pNode->right, tmp->data.getId());
            }
        }
        return pNode;
    }

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

public:
    BST() {
        root = nullptr;
    }

    void loadStudents() {
        vector<string> temp = openFile();
        this->root = insertNode(root, Student(temp[0], temp[1], stod(temp[2]), temp[3]));
        for (int i = 4; i < temp.size(); i += 4) {
            Student st(temp[i], temp[i + 1], stod(temp[i + 2]), temp[i + 3]);
            insertNode(root, st);
        }
    }

    BST_Node *createNode(const Student &s) {
        BST_Node *temp = new BST_Node();
        temp->right = nullptr;
        temp->left = nullptr;
        temp->data = s;
        return temp;
    }

    bool lessThan(string first, string second) {
        for (int i = 0; i < first.length(); ++i) {
            if (first[i] != '0') {
                break;
            } else {
                first.erase(i, 1);
            }
        }
        for (int i = 0; i < second.length(); ++i) {
            if (second[i] != '0') {
                break;
            } else {
                second.erase(i, 1);
            }
        }
        if (first.length() < second.length()) {
            return true;
        } else if (first.length() > second.length()) {
            return false;
        }
        for (int i = 0; i < first.length(); ++i) {
            if ((first[i] - '0') < (second[i] - '0')) {
                return true;
            } else if ((first[i] - '0') > (second[i] - '0')) {
                return false;
            }
        }
        return false;
    }

    BST_Node *insertNode(BST_Node *ptrNode, const Student &data) {
        if (ptrNode == nullptr) {
            return createNode(data);
        }
        if (lessThan(data.getId(), ptrNode->data.getId())) {
            ptrNode->left = insertNode(ptrNode->left, data);
        } else if (lessThan(ptrNode->data.getId(), data.getId())) {
            ptrNode->right = insertNode(ptrNode->right, data);
        }
        return ptrNode;
    }

    void printByID() {
        print(root);
    }

    void addStudents(const Student &x) {
        insertNode(root, x);
    }

    BST_Node *searchStud(const string &id) {
        return search(root, id);
    }

    void delStud(const string &id) {
        root = del(root, id);
    }
};
