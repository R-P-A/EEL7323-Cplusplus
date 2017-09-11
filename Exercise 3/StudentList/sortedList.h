class SortedList {
    private:
        Node* head;

    public:
        SortedList(Node* list);
        ~SortedList();

        void insert(Node* student);

        void remove(int id);

        void edit(Node* student);

        void search(int id);

        void listAll();
};
