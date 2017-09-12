#include "../sortedList.h"
#include "../student.h"
#include "../model.h"
#include "../node.h"
#include <iostream>

using namespace std;

int main () {
    SortedList* list = new SortedList();
    Student s1 = Student(1);
    Student s2 = Student(2);
    Student s3 = Student(3);
    Student s4 = Student(4);
    Student s5 = Student(5);
    list->insert(s2);
    list->insert(s4);
    list->insert(s1);
    list->insert(s3);
    list->insert(s5);
    list->listAll();
    //getchar();
    delete list;
    //Student* result = (Student*) lista->find(10);
    //cout << result->toString() << endl;
    return 0;
}