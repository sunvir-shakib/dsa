#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const{
        return this -> marks < obj. marks;
    }
};

int main() 
{
    priority_queue<Student> pq;
    pq.push(Student("sunvir", 77));
    pq.push(Student("avi", 88));
    pq.push(Student("sany", 66));

        while(!pq.empty()) {
        Student topStudent = pq.top();  // store in variable
        cout << "Top: " << topStudent.name << ", " << topStudent.marks << endl;
        pq.pop();
    }
   
   
    return 0;
}
