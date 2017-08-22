#include <iostream>
#include "student.cpp"
using namespace std;

void menu(Student** students);
Student* createStudent();

int main() {
    Student students[20];
    menu(students);
    for(int i = 0; i < 20; ++i)
        delete [] students[i]; 
    return 0;
}

void menu(Student** students) {
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
            students[0] = createStudent();
            break;
    }
}

Student* createStudent() {
    Student* student = new Student();
    string tempString;
    int tempInt;
    float tempFloat;

    cout << "Insira o nome do aluno:" << endl;
    cin >> tempString;
    student->setName(tempString);

    cout << "Insira a matricula do aluno:" << endl;
    cin >> tempString;
    student->setId(tempString);

    cout << "Insira a nota da prova 1 do aluno:" << endl;
    cin >> tempFloat;
    student->setGrade1(tempFloat);

    cout << "Insira a nota da prova 2 do aluno:" << endl;
    cin >> tempFloat;
    student->setGrade2(tempFloat);

    cout << "Insira as faltas do aluno:" << endl;
    cin >> tempInt;
    student->setAbsence(tempInt);

    return student;
}
