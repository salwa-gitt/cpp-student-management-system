#include "StudentManager.h"
#include <iostream>
#include <string>

void StudentManager::addStudent(const Student& s)
{
    students.push_back(s);
    
    std::cout << "Student added successfully!" << std::endl;
}

void StudentManager::deleteStudent(const std::string& id)
{
    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (it->getStudentId() == id)
        {
            students.erase(it);
            std::cout << "\nStudent deleted successfully!\n";
            return;
        }

    }
    std::cout << "Student not found\n";
}

void StudentManager::searchStudent(const std::string& id)
{
    Student* student = findStudentById(id);

    if (student != nullptr)
    {
        std::cout << "\n";
        student->displayStudent();
    }
    else
    {
        std::cout << "\nStudent not found!\n";
    }
    

}

Student* StudentManager::findStudentById(const std::string& id)
{
    for (auto& student : students)
    {
        if (student.getStudentId() == id)
        {
            return &student;
        }
    }
    
    return nullptr;
}

void StudentManager::updateStudent(const std::string& id)
{
    Student* student = findStudentById(id);

    if (student == nullptr)
    {
        std::cout << "Student not found...\n";
        return;
    }

    int input;

    std::cout << "\n1. ID"  << std::endl;
    std::cout << "2. Name" << std::endl;
    std::cout << "3. Age" << std::endl;
    std::cout << "4. CGPA" << std::endl;
    std::cout << "5. Department" << std::endl;
    std::cout << "6. Attendece Percentage" << std::endl;

    std::cout << "\nEnter the number you want to update: ";
    std::cin >> input;

    switch (input)
    {
        case 1:
        {
            std::string newId;

            std::cout << "Enter the new ID: ";
            std::cin >> newId;

            student->setStudentId(newId);
            break;
        }
        case 2:
        {
            std::string newName;

            std::cout << "Enter the new Name: ";
            std::cin >> newName;
            
            student->setName(newName);
            break;
        }
        case 3:
        {
            int newAge;

            std::cout << "Enter the new Age: ";
            std::cin >> newAge;
            
            student->setAge(newAge);
            break;
        }
        case 4:
        {
            float newCgpa;

            std::cout << "Enter the new CGPA: ";
            std::cin >> newCgpa;
            
            student->setCgpa(newCgpa);
            break;
        }
        case 5:
        {
            std::string newDepartment;

            std::cout << "Enter the new Department: ";
            std::cin >> newDepartment;
            
            student->setDepartment(newDepartment);
            break;
        }
        case 6:
        {
            float newAttenPercentage;

            std::cout << "Enter the new Attendance Percentage: ";
            std::cin >> newAttenPercentage;
            
            student->setAttendancePercentage(newAttenPercentage);
            break;
        }
        default:
        {
            std::cout << "Invalid Number...\n";
            break;
        }
    }
}

void StudentManager::displayAllStudents()
{

    if (students.empty())
    {
        std::cout << "\nno students availabe\n";
        return;
    }

    for (auto& student: students)
    {
        std::cout << "\n";
        student.displayStudent();
        std::cout << "\n";
        
    }
}

bool StudentManager::idExists(const std::string& id)
{
    return findStudentById(id) != nullptr;
}