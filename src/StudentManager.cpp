#include "StudentManager.h"
#include "FileManager.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

StudentManager::StudentManager()
{
    // Loading all the student objs that are saved in a txt file;
    students = fileManager.loadFromFile();
    
}

void StudentManager::addStudent(const Student& s)
{
    students.push_back(s);
    fileManager.saveToFile(students);
    std::cout << "\nStudent added successfully!" << std::endl;
}

void StudentManager::deleteStudent(const std::string& id)
{
    bool found = false;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (it->getStudentId() == id)
        {
            students.erase(it);
            std::cout << "\nStudent deleted successfully!\n";
            fileManager.saveToFile(students);
            found = true;
            return;
        }

    }
    if(!found)
    {
        std::cout << "\nStudent not found\n";
    }
    
}

void StudentManager::searchStudent()

{
    int userChoice;

    std::cout << "Choose search type:\n";
    std::cout << "1. Search by ID\n";
    std::cout << "2. Search by Name\n";

    while (true)
    {
        std::cout << "\nEnter search type (Num only): ";

        if (!(std::cin >> userChoice))
        {
            std::cout << "\nInvalid Input!\n";
            std::cin.clear();
            clearInputBuffer();
            continue;
        }

        break;

    }

    switch (userChoice)
    {  
        case 1:
        {
            std::string stdId;

            std::cout << "\nEnter ID to search: ";
            std::cin.ignore();
            std::getline(std::cin, stdId);

            std::cout << "\n========================================= SEARCH RESULT =========================================\n";
            searchStudentById(stdId);
            std::cout << "=================================================================================================\n";

            break;
        }

        case 2:
        {
            std::string stdName;

            std::cout << "\nEnter Name to search: ";
            std::cin.ignore();
            std::getline(std::cin, stdName);

            std::cout << "\n========================================= SEARCH RESULT =========================================\n";
            searchStudentByName(stdName);
            std::cout << "=================================================================================================\n";

            break;
        }
        
        default:
        {
            std::cout << "\nInvalid Input!\n";
            break;
        }
         
    }

}

void StudentManager::searchStudentById(const std::string& id)
{

    Student* student = findStudentById(id);
    bool found = false;

    if (student != nullptr)
    {
        std::cout << "\n";
        student->displayStudent();
        found = true;
    }

    if (!found)
    {
        std::cout << "\nStudent not found!\n";
    }
    

}

void StudentManager::searchStudentByName(const std::string& name)
{
    bool found = false;

    for (auto& student : students)
    {
        if (student.getName() == name)
        {
            std::cout << "\n";
            student.displayStudent();
            std::cout << "\n-------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }
    
    if(!found)
    {
        std::cout << "\nStudent Not Found!\n";
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
        std::cout << "\nStudent not found!\n";
        return;
    }

    int input;

    std::cout << "\n1. Name" << std::endl;
    std::cout << "2. Age" << std::endl;
    std::cout << "3. CGPA" << std::endl;
    std::cout << "4. Department" << std::endl;
    std::cout << "5. Attandece %" << std::endl;

    std::cout << "\nEnter the number you want to update: ";
    std::cin >> input;
    clearInputBuffer();

    switch (input)
    {

        case 1:
        {
            std::string newName;

            std::cout << "\nEnter the new Name: ";
            std::getline(std::cin, newName);
            
            student->setName(newName);
            std::cout << "\nName updated successfully!\n";
            break;
        }
        case 2:
        {
            int newAge;

            std::cout << "\nEnter the new Age: ";
            std::cin >> newAge;
            
            student->setAge(newAge);
            std::cout << "\nAge updated successfully!\n";
            break;
        }
        case 3:
        {
            float newCgpa;

            std::cout << "\nEnter the new CGPA: ";
            std::cin >> newCgpa;
            
            student->setCgpa(newCgpa);
            std::cout << "\nCGPA updated successfully!\n";
            break;
        }
        case 4:
        {
            std::string newDepartment;

            std::cout << "\nEnter the new Department: ";
            std::getline(std::cin, newDepartment);
            
            student->setDepartment(newDepartment);
            std::cout << "\nDepartment updated successfully!\n";
            break;
        }
        case 5:
        {
            float newAttenPercentage;

            std::cout << "\nEnter the new Attendance %: ";
            std::cin >> newAttenPercentage;
            
            student->setAttendancePercentage(newAttenPercentage);
            std::cout << "\nAttendence % updated successfully!\n";
            break;
        }
        default:
        {
            std::cout << "\nInvalid Number!\n";
            break;
        }
    }

    fileManager.saveToFile(students);
}

void StudentManager::displayAllStudents()
{

    if (students.empty())
    {
        std::cout << "\nNo students availabe!\n";
        return;
    }

    for (auto& student: students)
    {
        std::cout << "\n";
        student.displayStudent();
        std::cout << "\n-------------------------------------------------------------------------------------------------\n";
        
    }
}

bool StudentManager::idExists(const std::string& id)
{
    return findStudentById(id) != nullptr;
}

void StudentManager::sortByCgpa()
{
    if (students.empty())
    {
        std::cout << "\nNo students available to sort.\n";
        return;
    }


    std::vector<Student> temp = students;

    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = i + 1; j < temp.size(); j++)
        {
            if (temp[i].getCgpa() < temp[j].getCgpa())
            {
                std::swap(temp[i], temp[j]);
            }
        }

    }

    std::cout << "\n+++++ -Sorted By CGPA- +++++\n" << std::endl;

    std::cout << std::left << std::setw(25)
    << "Name" << std::setw(10) << "CGPA"
    << "\n";
    
    for (auto& student : temp)
    {
        std::cout << std::left << std::setw(25)
        << student.getName() << std::setw(10) 
        << student.getCgpa() << std::endl;
    }
}

void StudentManager::sortByName()
{
    

    if (students.empty())
    {
        std::cout << "\nNo students available to sort.\n";
        return;
    }
    
    
    std::vector<Student> temp = students;

    
    int userChoice;

    while (true)
    {
        std::cout << "Choose search type:\n";
        std::cout << "1. Sort by A-Z\n";
        std::cout << "2. Sort by Z-A\n";

        std::cout << "\nEnter Your Choice (num only): ";
        
        if (!(std::cin >> userChoice))
        {
            std::cout << "Invalid Input!\n";
            std::cin.clear();
            clearInputBuffer();
            continue;
        }

        std::cout << "\n";
        break;
    }

    switch (userChoice)
    {
        case 1:
        {
            for (int i = 0; i < temp.size(); i++)
            {
                for (int j = i + 1; j < temp.size(); j++)
                {
                    if (temp[i].getName() > temp[j].getName())
                    {
                        std::swap(temp[i], temp[j]);
                    }
                }

            }

            std::cout << "\n+++-Sorted By Name(A-Z)-+++\n" << std::endl;

            std::cout << std::left << std::setw(25)
            << "Name" << std::setw(10) << "CGPA"
            << "\n";
                
            for (auto& student : temp)
            {
                std::cout << std::left << std::setw(25)
                << student.getName() << std::setw(10) 
                << student.getCgpa() << '\n';
            }

            break;
        }

        case 2:
        {
            for (int i = 0; i < temp.size(); i++)
            {
                for (int j = i + 1; j < temp.size(); j++)
                {
                    if (temp[i].getName() < temp[j].getName())
                    {
                        std::swap(temp[i], temp[j]);
                    }
                }

            }

            std::cout << "\n+++-Sorted By Name(Z-A)-+++\n" << std::endl;

            std::cout << std::left
            << std::setw(25) << "Name"
            << std::setw(10) << "CGPA"
            << "\n";

            
            for (auto& student : temp)
            {
                std::cout << std::left
                << std::setw(25) << student.getName()
                << std::setw(10) << student.getCgpa()
                << '\n';
            }

            break;
        }
        
        default:
        {
            std::cout << "Invalid Input!" << std::endl;
            break;
        }
    }


    
}

void StudentManager::sortStudents()
{
    int userChoice;

    while (true)
    {
        std::cout << "Choose Sort type:" << std::endl;
        std::cout << "1. Sort by CGPA\n";
        std::cout << "2. Sort by Name\n";

        std::cout << "\nEnter Your Choice (num only): ";
        
        if (!(std::cin >> userChoice))
        {
            std::cout << "\nInvalid Input!" << std::endl;
            std::cin.clear();
            clearInputBuffer();
            continue;
        }

        std::cout << "\n";
        clearInputBuffer();

        break;
    }

    switch (userChoice)
    {

        case 1:
        {
            sortByCgpa();
            std::cout << "-------------------------------------------------------------------------------------------------\n";
            break;
        }
        
        case 2:
        {
            sortByName();
            std::cout << "-------------------------------------------------------------------------------------------------\n";
            break;
        }
        
        default:
        {
            std::cout << "\nInvalid Input!" << std::endl;
            break;
        }
            
    }

}

void StudentManager::clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//average cgpa of all students
float StudentManager::averageCgpa()
{
    if (students.empty())
    {
        return 0.0f;
    }
    
    
    std::vector<Student> temp = students;

    float totalCgpa = 0;

    for (auto& student : temp)
    {
        totalCgpa += student.getCgpa();
    }

    return totalCgpa / students.size();
}

//getting highest student among all students
std::string StudentManager::highestCgpaStudent()
{
    if (students.empty())
    {
        return "N/A";
    }

    const Student* best = &students[0];

    for (const auto& student : students)
    {
        if (student.getCgpa()> best->getCgpa())
        {
            best = &student;
        }
    }

    return best->getName() + " (" + std::to_string(best->getCgpa()) + ")";
}

std::string StudentManager::lowestCgpaStudent()
{
    if (students.empty())
    {
        return "N/A";
    }

    const Student* worst = &students[0];

    for (const auto& student : students)
    {
        if (student.getCgpa() < worst->getCgpa())
        {
            worst = &student;
        }
    }

    return worst->getName() + " (" + std::to_string(worst->getCgpa()) + ")";
}

int StudentManager::totalStudents()
{
    return students.size();
}

void StudentManager::studentBelowThreshold()
{
    if (students.empty())
    {
        std::cout << "\nNo Students Available!\n";
        return;
    }

    //At Risk Students (Attendance < 75%)

    for (const auto& student : students)
    {
        if (student.getAttendancePercentage() < 75)
        {
            std::cout << "\n";
            std::cout << "Name: " << student.getName() << std::endl;
            std::cout << "Attendance Percentage: " 
            << student.getAttendancePercentage() << std::endl;
            std::cout << "\n";
        }
    }
}

void StudentManager::filterByDepartment()
{
    if (students.empty())
    {
        std::cout << "\nNo Students Availabe!\n" << std::endl;
        return;
    }

    std::string filter = "";

    std::cout << "Enter department to filter: ";
    std::getline(std::cin, filter);
    bool found = false;


    std::cout << "\n========================================= DEPARTMENT: " << filter << " =========================================\n";

    for (const auto& student : students)
    {
        if (student.getDepartment() == filter)
        {
            std::cout << "\n";
            student.displayStudent();
            std::cout << "-------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }


    if (found == false)
    {
        std::cout << "               [ No students found in this department ]                          \n";
    }
}