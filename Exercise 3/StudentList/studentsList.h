class StudentsList {
    private:
        Student* head;

    public:
        StudentsList(Student* list);
        ~StudentsList();

        Student* getHead();

        void insert(Student* student);

        void remove(int id);

        void edit(Student* student);

        void search(int id);

        void listAll();
};
