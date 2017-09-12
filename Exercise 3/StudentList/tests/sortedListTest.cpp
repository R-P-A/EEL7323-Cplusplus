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
    cout << endl;
    cout << list->find(2).getId() << endl;
    cout << list->find(1).getId() << endl;
    cout << list->find(5).getId() << endl;
    cout << list->find(0).getId() << endl;
    cout << list->find(6).getId() << endl;
    cout << endl;
    list->remove(0);
    list->listAll();
    list->remove(1);
    list->listAll();
    list->remove(5);
    list->listAll();
    list->remove(2);
    list->listAll();
    list->remove(3);
    list->listAll();
    list->remove(4);
    list->listAll();

    //getchar();
    delete list;
    //Student* result = (Student*) lista->find(10);
    //cout << result->toString() << endl;
    return 0;
}