#include <vector>

class StudentManager
{
    private:
        // making a database which stores all the student objects.
        std::vector<Student> students;

    public:

        void addStudent();
        void deleteStudent();
        void searchStudent();
        void updateStudent();
        void displayAllStudents();
        
};