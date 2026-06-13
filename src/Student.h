#pragma once
#include <string>

/*
defines Student class
contains Student data model for the system
*/


/*
represents a student and stores their information
*/
class Student
{
    private:
        std::string studentId;
        std::string name;
        int age;
        float cgpa;
        std::string department;
        float attendancePercentage;
    
    public:

        // constructors declaration
        Student(const std::string& studentId = "",
        const std::string& name = "",
        int age = 0, float cgpa = 0,
        const std::string& department = "",
        float attendancePercentage = 0);


        void setStudentId(const std::string& studentId);

        void setName(const std::string& name);

        void setAge(int age);

        void setCgpa(float cgpa);

        void setDepartment(const std::string& department);

        void setAttendancePercentage(float attendencePercentage);


        std::string getStudentId() const;

        std::string getName() const;

        int getAge() const;

        float getCgpa() const;

        std::string getDepartment() const;

        float getAttendancePercentage() const;
        

        // display function declaration
        void displayStudent();
};

