#include "../sortedList.h"
#include "../student.h"
#include "../model.h"
#include <iostream>

using namespace std;

int main () {
    Model* joao = new Student();
    Student* sjoao = (Student*) joao;
    sjoao->setName("joao");
    cout << sjoao->getName() << endl;
    joao->setId(2);
    cout << joao->getId() << endl;
    delete joao;
    //Student* result = (Student*) lista->find(10);
    //cout << result->toString() << endl;
    return 0;
}