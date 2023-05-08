#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class student{
private:
    string name;
    string id;
    double gpa;
    string department;
public:
    student() = default;
    student(string name,string id,double gpa,string department){
        this->name= name;
        this->id= id;
        this->gpa = gpa;
        this->department = department;
    }
    student(nullptr_t pVoid){}
    bool operator <(const student &other) const{
        return this->gpa < other.gpa;
    }
    bool operator >(const student &other) const{
        return this->gpa > other.gpa;
  }
    student& operator =(const student &other){
        this->name=other.name;
        this->id=other.id;
        this->gpa=other.gpa;
        this->department=other.department;
        return *this;
    }
friend ostream& operator<< (ostream &out , const student& stdu);

};
ostream& operator<< (ostream &out , const student& stdu){
    out << stdu.name<<endl;
    out<<stdu.id<<endl;
    out<<stdu.gpa<<endl;
    out<<stdu.department<<endl;
    return out;
}



template<class obj>
class minheap{
private:
    obj* arr;
    obj root;
    int length;
    int capacity;
public:
    minheap(){
        arr = new obj[0];
        root = arr[0];
        length =0;
        capacity=0;
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
        getline(data,line);

        while (!data.eof())
        {
            data_holder.push_back(line);
            getline(data,line);
        }

        for (int i = 0; i < data_holder.size(); i+=4)
        {
            obj stu(data_holder[i],data_holder[i+1], stod(data_holder[i+2]),data_holder[i+3]);
            min_insert(stu);
            index++;
        }

    }

    int parent (int index)
    {
        return (index - 1)/2;
    }
    int right(int index)
    {
        return (2 * index + 1);
    }
    int left(int index)
    {
        return (2 * index + 2);
    }

    void min_insert(obj element){
        if (length >= capacity)
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

    void minHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if (l < length && arr[l] < arr[index])
            smallest = l;
        if (r < length && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != index) {
            swap( arr[index], arr[smallest]);
            minHeapify(smallest);
        }
    }

    obj extractMin()
    {
        if (length <= 0)
            return nullptr;
        if (length == 1)
        {
            length--;
            root = arr[0];
            return root;
        }
        root = arr[0];
        length--;
        arr[0] = arr[length];
        //delete_element(length-1);
        minHeapify(0);
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

    void print(int index)
    {
        for (int i = 0; i < length; ++i)
        {
            cout << arr[i];
        }
        cout<<endl;
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
public:
    maxheap(){
        arr = new obj[0];
        root = arr[0];
        length =0;
        capacity=0;
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
        getline(data,line);

        while (!data.eof())
        {
            data_holder.push_back(line);
            getline(data,line);
        }

        for (int i = 0; i < data_holder.size(); i+=4)
        {
            obj stu(data_holder[i],data_holder[i+1], stod(data_holder[i+2]),data_holder[i+3]);
            max_insert(stu);
            index++;
        }

    }

    int parent (int index)
    {
        return (index - 1)/2;
    }
    int right(int index)
    {
        return (2 * index + 1);
    }
    int left(int index)
    {
        return (2 * index + 2);
    }

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

    void maxHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int biggest = index;
        if (l < length && arr[l] > arr[index])
            biggest = l;
        if (r < length && arr[r] > arr[biggest])
            biggest = r;
        if (biggest != index) {
            swap(arr[index],arr[biggest]);
            maxHeapify(biggest);
        }
    }

    obj extractMax()
    {
        if (length <= 0)
            return nullptr;
        if (length == 1)
        {
            length--;
            root = arr[0];
            return root;
        }
        root = arr[0];
        length--;
        arr[0] = arr[length];
        //delete_element(length-1);
        maxHeapify(0);
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

    void print(int index)
    {
        for (int i = 0; i < length; ++i)
        {
            cout << arr[i];
        }
        cout<<endl;
    }

    int size()
    {
        return length;
    }
};









int main() {
    minheap<student>test("heaptest.txt",20);
    cout<< test.extractMin();
    maxheap<student>test2("heaptest.txt",20);
    cout <<test2.extractMax();
    //test.print(0);
//student x("omar","2020",3.3,"gen");
//student y("omar","2020",3.5,"gen");
////cout<<x<<y;
//
//student *arr = new student[2];
//
//arr[0]=x;
//arr[1]=y;
//arr[3]=x;
//cout << arr[0];
//cout<<arr[1];
//cout<<arr[3];
//   test.min_insert(0);
//   test.min_insert(6);
//   test.min_insert(5);
//   test.min_insert(7);
//   test.min_insert(10);
//   test.min_insert(9);
//    while (test.size()>0) {
//        cout<<test.extractMin()<<" "<<test.size()<<endl;
//        test.print(0);
//        cout<<endl;
//    }
//    fstream file("heaptest.txt");
//    string line;
//    //getline(file,line,'.');
//    while (getline(file,line)){
//        cout<<line<<endl;
//    }
//    cout<<line;
    return 0;
}
