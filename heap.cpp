#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

template<class obj>
class minheap{
private:
    obj* arr;
    obj root;
    int length;
    int capacity;
    int cntCs=0,cntIs=0,cntIt=0,CntDs=0,CntAi=0,cntGeneral=0;
public:
    minheap(){
        arr = new obj[100];
        root = arr[0];
        length =0;
        capacity=100;
    }
    minheap(const string& filename,int size){
        capacity= size;
        arr = new obj[capacity];
        root = arr[0];
        length =0;
        fstream data(filename);
        string line;
        int index=0;
        vector<string> data_holder;

        if (data.fail())
        {
            cout<< "loading data Failed"<<endl;
        }

        while (getline(data,line))
        {
            data_holder.push_back(line);
            //getline(data,line);
        }
//        for (int i = 0; i < data_holder.size(); i++) {
//            cout<<data_holder[i]<<endl;
//        }

        for (int i = 0; i < data_holder.size(); i+=4)
        {
            //obj stu(data_holder[i],data_holder[i+1], stod(data_holder[i+2]),data_holder[i+3]);
            min_insert(obj(data_holder[i],data_holder[i+1], stod(data_holder[i+2]),data_holder[i+3]));
            //index++;
        }

    }

    void countDepStudents(int index) {
        if(index == length){
            return;
        }

        if(arr[index].getDepartment()=="CS"){
            cntCs++;
        } else if(arr[index].getDepartment()=="IT"){
            cntIt++;
        } else if(arr[index].getDepartment()=="IS"){
            cntIs++;
        } else if(arr[index].getDepartment()=="DS"){
            CntDs++;
        } else if(arr[index].getDepartment()=="AI"){
            CntAi++;
        }
        else if(arr[index].getDepartment()=="gen"){
            cntGeneral++;
        }
        countDepStudents(2 * index + 1);
        countDepStudents(2 * index + 2);
    }

    void printTheCountDepStudents(){
        countDepStudents(0);
        cout<<"Number of students in CS: "<<cntCs<<endl;
        cout<<"Number of students in IT: "<<cntIt<<endl;
        cout<<"Number of students in IS: "<<cntIs<<endl;
        cout<<"Number of students in DS: "<<CntDs<<endl;
        cout<<"Number of students in AI: "<<CntAi<<endl;
        cout << "Number of students in general: " << cntGeneral << endl;
        cntCs=0;cntIs=0;cntIt=0;CntDs=0;CntAi=0;cntGeneral=0;
    }

    int parent (int index)
    {
        return (index - 1)/2;
    }
//    int right(int index)
//    {
//        return (2 * index + 1);
//    }
//    int left(int index)
//    {
//        return (2 * index + 2);
//    }

    void min_insert(obj element){
        if (length == capacity)
        {
            cout << "index out of range" <<endl;
        }
        length++;
        int index = length - 1;
        arr[index] = element;

        while (index != 0 && arr[parent(index)] > arr[index]) {
            swap(arr[index], arr[parent(index)]);
            index= parent(index);
        }
    }
    void minheapify(int n,int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        int max=i;
        if(l<n&&arr[l]>arr[max])
            max=l;
        if(r<n&&arr[r]>arr[max])
            max=r;

        if(max != i){
            swap(arr[i],arr[max]);
            minheapify(n,max);
        }
    }

    void Heap_helper(int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            minheapify(n, i);
    }

    void heapSort(int n)
    {
        Heap_helper(n);
        for (int i = n-1; i >=0; i--)
        {
            swap(arr[0], arr[i]);
            minheapify(i, 0);
        }

    }

    obj extractMin()
    {
        if (length <= 0)
            return obj("","",INT_MAX,"");
        if (length == 1)
        {
            length--;
            //root = arr[0];
            return arr[0];
        }
        root = arr[0];
        arr[0] = arr[length-1];
        length--;
        //delete_element(length-1);
        minheapify(length,0);
        return root;

    }

    void min_delete(int index)
    {
        arr[index] = INT_MIN;
        while (index != 0 && arr[parent(index)] > arr[index])
        {
            swap(arr[index], arr[parent(index)]);
            index= parent(index);
        }
        extractMin();
    }

    void print()
    {
        for (int i = 0; i < length; ++i) {
            cout<<arr[i]<< endl;
        }
    }

    int size()
    {
        return length;
    }

};


template<typename obj>
class maxheap{
private:
    obj* arr;
    obj root;
    int length;
    int capacity;
    int cntCs=0,cntIs=0,cntIt=0,CntDs=0,CntAi=0,cntGeneral=0;
public:
    maxheap(){
        arr = new obj[100];
        root = arr[0];
        length =0;
        capacity=100;
    }
    maxheap(const string& filename,int size){
        capacity= size;
        arr = new obj[capacity];
        root = arr[0];
        length =0;
        fstream data(filename);
        string line;
        int index=0;
        vector<string> data_holder;

        if (data.fail())
        {
            cout<< "loading data Failed"<<endl;
        }


        while ( getline(data,line))
        {
            data_holder.push_back(line);

        }

        for (int i = 0; i < data_holder.size(); i+=4)
        {
            max_insert(obj(data_holder[i],data_holder[i+1], stod(data_holder[i+2]),data_holder[i+3]));

        }

    }
    void countDepStudents() {
//        if(index == length){
//            return;
//        }
        for (int i = 0; i < length; ++i) {
            if(arr[i].getDepartment()=="CS"){
                cntCs++;
            } else if(arr[i].getDepartment()=="IT"){
                cntIt++;
            } else if(arr[i].getDepartment()=="IS"){
                cntIs++;
            } else if(arr[i].getDepartment()=="DS"){
                CntDs++;
            } else if(arr[i].getDepartment()=="AI"){
                CntAi++;
            }
            else if(arr[i].getDepartment()=="gen"){
                cntGeneral++;
            }
        }
//        countDepStudents(2 * index + 1);
//        countDepStudents(2 * index + 2);
    }

    void printTheCountDepStudents(){
        countDepStudents();
        cout<<"Number of students in CS: "<<cntCs<<endl;
        cout<<"Number of students in IT: "<<cntIt<<endl;
        cout<<"Number of students in IS: "<<cntIs<<endl;
        cout<<"Number of students in DS: "<<CntDs<<endl;
        cout<<"Number of students in AI: "<<CntAi<<endl;
        cout << "Number of students in general: " << cntGeneral << endl;
        cntCs=0;cntIs=0;cntIt=0;CntDs=0;CntAi=0;cntGeneral=0;
    }

    int parent (int index)
    {
        return (index - 1)/2;
    }
//    int right(int index)
//    {
//        return (2 * index + 1);
//    }
//    int left(int index)
//    {
//        return (2 * index + 2);
//    }

    void max_insert(const obj& element)
    {
        if (length == capacity)
        {
            cout << "index out of range" <<endl;
        }
        length++;
        int index = length - 1;
        arr[index] = element;

        while (index != 0 && arr[parent(index)] < arr[index]) {
            swap(arr[index], arr[parent(index)]);
            index= parent(index);
        }
    }
    void maxheapify(int n,int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        int max=i;
        if(l<n&&arr[l]<arr[max])
            max=l;
        if(r<n&&arr[r]<arr[max])
            max=r;

        if(max != i){
            swap(arr[i],arr[max]);
            maxheapify(n,max);
        }
    }

    void Heap_helper(int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapify(n, i);
    }

    void heapSort(int n)
    {

        Heap_helper(n);
        for (int i = n-1; i >=0; i--)
        {
            swap(arr[0], arr[i]);
            maxheapify(i, 0);
        }

    }
    obj extractMax()
    {
        if (length <= 0)
            return obj("","",INT_MIN,"");;
        if (length == 1)
        {
            length--;
            return arr[0];
        }
        root = arr[0];
        arr[0] = arr[length];
        length--;
        //delete_element(length-1);
        maxheapify(length,0);
        return root;
    }

    void max_delete(int index)
    {
        arr[index] = INT_MAX;
        while (index != 0 && arr[parent(index)] < arr[index])
        {
            swap(arr[index], arr[parent(index)]);
            index= parent(index);
        }
        extractMax();
    }

    void print()
        {
            for (int i = 0; i < length; ++i) {
                cout<<arr[i]<< endl;
            }
        }




    int size()
    {
        return length;
    }
};


