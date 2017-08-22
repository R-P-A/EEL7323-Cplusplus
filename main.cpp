#include <iostream>
#include "student.cpp"
using namespace std;

void menu(Student* students, int numberStudents);
void zeroStudents(Student* students, int numberStudents);
void insertStudent(Student* students, int i);
void listAllStudents (Student* students, int numberStudents);
Student getStudent (Student* students, string id, int numberStudents);

int main() {
    int numberStudents = 20;
    Student students[numberStudents];
    zeroStudents(students, numberStudents);
    menu(students, numberStudents);
    return 0;
}

void menu(Student* students, int numberStudents) {
    int option;
    cout << "Escolha uma opcao:\n";
    cout << "1. Adicionar um aluno\n";
    cout << "2. Editar um aluno\n";
    cout << "3. Mostrar um aluno\n";
    cout << "4. Listar todos os alunos\n";
    cout << "5. Sair\n";
    cin >> option;
// 
    switch(option) {
        case 1:
            insertStudent(students, 0);
            cout << students[0].toString();
            listAllStudents(students, numberStudents);
            cout << getStudent(students, "123", 3).toString();
            break;
    }
}

void zeroStudents(Student* students, int numberStudents) {
    string tempString = "\0";
    int tempInt = 0;
    float tempFloat = 0;

    for (int i = 0; i < numberStudents; i++) {
        students[i].setName(tempString);
        students[i].setId(tempString);
        students[i].setGrade1(tempFloat);
        students[i].setGrade2(tempFloat);
        students[i].setAbsence(tempInt);
    }    
}

void insertStudent(Student* students, int stringPlace) {
    string tempString;
    int tempInt;
    float tempFloat;

    cout << "Insira o nome do aluno:" << endl;
    cin >> tempString;
    students[stringPlace].setName(tempString);

    cout << "Insira a matricula do aluno:" << endl;
    cin >> tempString;
    students[stringPlace].setId(tempString);

    cout << "Insira a nota da prova 1 do aluno:" << endl;
    cin >> tempFloat;
    students[stringPlace].setGrade1(tempFloat);

    cout << "Insira a nota da prova 2 do aluno:" << endl;
    cin >> tempFloat;
    students[stringPlace].setGrade2(tempFloat);

    cout << "Insira as faltas do aluno:" << endl;
    cin >> tempInt;
    students[stringPlace].setAbsence(tempInt);
}

void listAllStudents (Student* students, int numberStudents) {
    cout << "\n\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < numberStudents; i++) {
        cout << students[i].toString() << endl;
    }
}

Student getStudent (Student* students, string id, int numberStudents) {
    int i = 0;
    while (students[i].getId() != id && i < numberStudents) 
        i++;
    return students[i];
}