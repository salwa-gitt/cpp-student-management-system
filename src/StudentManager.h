#pragma once
#include "Student.h"
#include <vector>
#include <string>

class StudentManager
{
    private:
        // making a database which stores all the student objects.
        std::vector<Student> students;

    public:

        void addStudent(const Student& s);

        void deleteStudent(const std::string& id);

        void searchStudent();

        void searchStudentByName(const std::string& name);

        void searchStudentById(const std::string& id);

        Student* findStudentById(const std::string& id);

        void updateStudent(const std::string& id);

        void displayAllStudents();

        bool idExists(const std::string& id);

        void sortStudents();

        void sortByCgpa();
        
        void sortByName();

        void clearInputBuffer();

        // Average CGPA of all Students
        void averageCgpa();

        //getting highest CGPA
        void highestCgpaStudent();

        //getting lower CGPA
        void lowestCgpaStudent();

        //Total students
        void totalStudents();

        //student below 75% in attendence
        void studentBelowThreshold();

        // filter by department
        void filterByDepartment();
        
};