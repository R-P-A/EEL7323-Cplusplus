#include "../sortedList.h"
#include "../student.h"
#include <iostream>

using namespace std;

int main () {
    Student* joao = new Student();
    joao->setId(2);
    cout << joao->getId() << endl;
    delete joao;
    return 0;
}