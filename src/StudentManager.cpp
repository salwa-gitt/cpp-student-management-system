#include "StudentManager.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

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

void StudentManager::searchStudent()

{
    int userChoice;

    std::cout << "Choose search type:\n";
    std::cout << "1. Search by ID\n";
    std::cout << "2. Search by Name\n";

    while (true)
    {
        std::cout << "Enter search type (Num only): ";

        if (!(std::cin >> userChoice))
        {
            std::cout << "Invalid Input!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        break;

    }

    switch (userChoice)
    {  
        case 1:
        {
            std::string stdId;

            std::cout << "Enter ID to search: ";
            std::cin.ignore();
            std::getline(std::cin, stdId);

            searchStudentById(stdId);

            break;
        }

        case 2:
        {
            std::string stdName;

            std::cout << "Enter Name to search: ";
            std::cin.ignore();
            std::getline(std::cin, stdName);

            searchStudentByName(stdName);

            break;
        }
        
        default:
        {
            std::cout << "Invalid Input!\n";
            break;
        }
         
    }

}

void StudentManager::searchStudentById(const std::string& id)
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



void StudentManager::searchStudentByName(const std::string& name)
{
    for (auto& student : students)
    {
        if (student.getName() == name)
        {
            std::cout << "\n";
            student.displayStudent();
        }
    }

    std::cout << "Student Not Found.\n";
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
        std::cout << "1. Sort by A to Z\n";
        std::cout << "2. Sort by Z to A\n";

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

            std::cout << "\n+++-Sorted By Name (A-Z)-+++\n" << std::endl;

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

            std::cout << "\n+++-Sorted By Name (Z-A)-+++\n" << std::endl;

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
        std::cout << "Choose Sort type:\n" << std::endl;
        std::cout << "1. Sort by CGPA\n";
        std::cout << "2. Sort by Name\n";

        std::cout << "\nEnter Your Choice (num only): ";
        
        if (!(std::cin >> userChoice))
        {
            std::cout << "Invalid Input!" << std::endl;
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
            sortByCgpa();
            break;
        }
        
        case 2:
        {
            sortByName();
            break;
        }
        
        default:
        {
            std::cout << "Invalid Input!" << std::endl;
            break;
        }
            
    }

}

void StudentManager::clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


//average cgpa of all students
void StudentManager::averageCgpa()
{
    if (students.empty())
    {
        std::cout << "\nNo students available.\n";
        return;
    }
    
    
    std::vector<Student> temp = students;

    float totalCgpa = 0;
    int size = students.size();
    float averageCgpa = 0;

    for (auto& student : temp)
    {
        totalCgpa += student.getCgpa();
    }

    averageCgpa = totalCgpa/size;

    std::cout << "\nAverage CGPA: " << averageCgpa << std::endl;


}

//getting highest student among all students
void StudentManager::highestCgpaStudent()
{
    if (students.empty())
    {
        std::cout << "No students available.\n";
        return;
    }

    const Student* best = &students[0];

    for (const auto& student : students)
    {
        if (student.getCgpa()> best->getCgpa())
        {
            best = &student;
        }
    }

    std::cout << "Highest CGPA Student:\n\n";
    std::cout << "Name: " << best->getName() << std::endl;
    std::cout << "CGPA: " << best->getCgpa() << std::endl;
}

void StudentManager::lowestCgpaStudent()
{
    if (students.empty())
    {
        std::cout << "No students Available." << std::endl;
        return;
    }

    const Student* worst = &students[0];

    for (const auto& student : students)
    {
        if (student.getCgpa() < worst->getCgpa())
        {
            worst = &student;
        }
    }

    std::cout << "Lowest CGPA Student:\n\n";
    std::cout << "Name: " << worst->getName() << std::endl;
    std::cout << "CGPA: " << worst->getCgpa() << std::endl;
}

void StudentManager::totalStudents()
{
    std::cout << "Total Students: " << students.size() << std::endl;
}

void StudentManager::studentBelowThreshold()
{
    if (students.empty())
    {
        std::cout << "\nNo Students Available.\n";
        return;
    }

    //At Risk Students (Attendance < 75%)

    for (const auto& student : students)
    {
        if (student.getAttendancePercentage() <= 75)
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
        std::cout << "No Students Availabe.\n" << std::endl;
        return;
    }

    std::string filter = "";

    std::cout << "Enter department to filter: ";
    std::cin >> filter;

    for (const auto& student : students)
    {
        if (student.getDepartment() == filter)
        {
            std::cout << "\n\n";
            student.displayStudent();
            std::cout << "\n\n";
        }
    }
    
    else
    {
        std::cout << "Department Not Found!\n";
    }
}