#include <iostream>
#include "student.cpp"
using namespace std;

void menu(Student* students, int numberStudents);
void insertStudent(Student* students, int arrayPlace, int numberStudents);
void listAllStudents (Student* students, int numberStudents);
int getStudent (Student* students, string id, int numberStudents);

int main() {
    int numberStudents = 20;
    Student students[numberStudents];
    menu(students, numberStudents);
    return 0;
}

void menu(Student* students, int numberStudents) {
    int option = 0;
    int arrayPlace = 0;
    int studentPlace = 0;
    string id;
    while (option != 5) {
        cout << endl;
        cout << "Escolha uma opcao:\n";
        cout << "1. Adicionar um aluno\n";
        cout << "2. Editar um aluno\n";
        cout << "3. Mostrar um aluno\n";
        cout << "4. Listar todos os alunos\n";
        cout << "5. Sair\n\n";
        cin >> option;
        cout << endl;

        switch(option) {
            case 1:
                if (arrayPlace == numberStudents) {
                    cout << "Memoria cheia, altere um aluno existente.\n\n";
                } else {
                    insertStudent(students, arrayPlace, numberStudents);
                    arrayPlace++;
                }
                break;
            case 2:
                cout << "Escolha uma matricula de um aluno para editar" << endl;
                cin >> id;
                studentPlace = getStudent(students, id, numberStudents);
                if (studentPlace == numberStudents) {
                    cout << "Aluno inexistente com esta matricula" << endl;
                } else {
                    insertStudent(students, studentPlace, numberStudents);
                }
                break;
            case 3:
                cout << "Escolha uma matri3cula de um aluno para mostrar" << endl;
                cin >> id;
                studentPlace = getStudent(students, id, numberStudents);
                if (studentPlace == numberStudents) {
                    cout << endl << "Aluno inexistente com esta matricula" << endl;
                } else {
                    cout << endl << students[studentPlace].toString() << endl;
                }
                break;
            case 4:
                listAllStudents (students, numberStudents);
                break;
            case 5:
                cout << endl << "Adeus!" << endl;
                break;
            default:
                cout << "Opcao invalida, tente novamente\n\n";
                break;
        }

    }
}

void insertStudent(Student* students, int arrayPlace, int numberStudents) {
    string tempString;
    int tempInt;
    float tempFloat;

    cout << "Insira a matricula do aluno:" << endl;
    cin >> tempString;
    if (getStudent (students, tempString, numberStudents) != numberStudents) {
        cout << endl << "Matricula existente, saindo deste menu, tente novamente...\n\n";
    } else {
        students[arrayPlace].setId(tempString);

        cout << "Insira o nome do aluno:" << endl;
        cin >> tempString;
        students[arrayPlace].setName(tempString);

        cout << "Insira a nota da prova 1 do aluno:" << endl;
        cin >> tempFloat;
        students[arrayPlace].setGrade1(tempFloat);

        cout << "Insira a nota da prova 2 do aluno:" << endl;
        cin >> tempFloat;
        students[arrayPlace].setGrade2(tempFloat);

        cout << "Insira as faltas do aluno:" << endl;
        cin >> tempInt;
        students[arrayPlace].setAbsence(tempInt);
    }
}

void listAllStudents (Student* students, int numberStudents) {
    cout << "\n\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < numberStudents; i++) {
        cout << students[i].toString() << endl;
    }
}

int getStudent (Student* students, string id, int numberStudents) {
    int studentPlace = numberStudents;
    int i = 0;
    while (i < numberStudents) {
        if (students[i].getId() == id) {
            studentPlace = i;
        }
        i++;
    }
    return studentPlace;
}
