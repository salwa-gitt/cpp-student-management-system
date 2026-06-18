#include <iostream>
#include <string>
#include "Student.h"


// parametrized constructor
Student::Student(const std::string& studentId,
        const std::string& name,
        int age, float cgpa,
        const std::string& department,
        float attendancePercentage)
{
    setStudentId(studentId);
    setName(name);
    setAge(age);
    setCgpa(cgpa);
    setDepartment(department);
    setAttendancePercentage(attendancePercentage);
    
}


void Student::setStudentId(const std::string& studentId)
{
    this->studentId = studentId;
}

void Student::setName(const std::string& name)
{
    this->name = name;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setCgpa(float cgpa)
{
    this->cgpa = cgpa;
}

void Student::setDepartment(const std::string& department)
{
    this->department = department;
}

void Student::setAttendancePercentage(float attendancePercentage)
{
    this->attendancePercentage = attendancePercentage;
}


std::string Student::getStudentId() const
{
    return studentId;
}

std::string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

float Student::getCgpa() const
{
    return cgpa;
}

std::string Student::getDepartment() const
{
    return department;
}

float Student::getAttendancePercentage() const
{
    return attendancePercentage;
}


void Student::displayStudent() const
{
    std::cout << "Student ID: " << getStudentId() << std::endl;
    std::cout << "Student Name: " << getName() << std::endl;
    std::cout << "Student Age: " << getAge() << std::endl;
    std::cout << "Student CGPA: " << getCgpa() << std::endl;
    std::cout << "Student Department: " << getDepartment() << std::endl;
    std::cout << "Student Attendance Percentage: " 
         << getAttendancePercentage() << "%" << std::endl;
}