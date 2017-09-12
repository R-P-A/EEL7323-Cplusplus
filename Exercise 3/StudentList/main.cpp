#include <iostream>
#include "sortedList.h"
#include "student.h"
#include "model.h"
#include "node.h"
#include "menu.h"

using namespace std;


int main() {
    SortedList* studentList = new SortedList();
    bool cont = true;
    Menu* menu = new Menu();
    while (cont) {
        cont = menu->mainMenu(studentList);
    }
    delete menu;
    delete studentList;
    return 0;
}
