#include <iostream>
#include <string>
#include <limits>
#include "Student.h"
#include "StudentManager.h"

void clearInputBuffer();

int main(void)
{
    StudentManager manager;

    while (true)
    {
        std::cout << "\n===== STUDENT SYSTEM =====\n" << std::endl;

        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Delete Student" << std::endl;
        std::cout << "3. Search Student" << std::endl;
        std::cout << "4. Update Student" << std::endl;
        std::cout << "5. Display All Students" << std::endl;
        std::cout << "0. Exit\n" << std::endl;

        int inputChoice;

        std::cout << "Enter your choice (Num only): ";
        

        if (!(std::cin >> inputChoice))
        {
            std::cout << "Invalid Input!\n";
            std::cin.clear(); // reset error state
            clearInputBuffer(); // “Throw away everything left in the input buffer until I hit a newline.
            continue;
        }

        std::cout << "\n";
        clearInputBuffer();

        switch (inputChoice)
        {
        case 1:
        {
            std::string studentId;
            bool idExist = false;
            
            std::cout << "Enter ID to add: ";
            std::getline(std::cin, studentId);

            
            idExist = manager.idExists(studentId);

            if (idExist == true)
            {
                std::cout << "ID Exists Already!" << std::endl;
                break;
            }
            else
            {
                int studentAge;
                std::string studentName, studentDepartment;
                float studentCGPA, studentAttenPercent;

                std::cout << "Enter Name: ";
                std::getline(std::cin, studentName);

                while (true)
                {
                    std::cout << "Enter Age: ";
                    if (!(std::cin >> studentAge))
                    {
                        std::cout << "Invalid Input!\n";
                        std::cin.clear();
                        clearInputBuffer();
                        continue;
                    }
                    clearInputBuffer();

                    if (studentAge > 0)
                    {
                        break;
                    }

                    std::cout << "Invalid Input. Try Again\n";
                }


                std::cout << "Enter Department: ";
                std::getline(std::cin, studentDepartment);

                while (true)
                {
                    std::cout << "Enter CGPA: ";

                    if (!(std::cin >> studentCGPA))
                    {
                        std::cout << "Invalid Input.\n";
                        std::cin.clear();
                        clearInputBuffer();
                        continue;
                    }
                    clearInputBuffer();

                    if (studentCGPA >= 0.0 && studentCGPA <= 4.0)
                    {
                        break;
                    }

                    std::cout << "Invalid Input. Try Again!\n";
                }

                
                while (true)
                {
                    std::cout << "Enter Attendance Percentage: ";

                    if (!(std::cin >> studentAttenPercent))
                    {
                        std::cout << "Invalid Input!\n";
                        std::cin.clear();
                        clearInputBuffer();
                        continue;
                    }
                    clearInputBuffer();

                    if (studentAttenPercent >= 0.0 && studentAttenPercent <= 100.0)
                    {
                        break;
                    }

                    std::cout << "Invalid Input. Try Again!\n";
                }

                Student student(studentId, studentName,
                    studentAge, studentCGPA, studentDepartment, studentAttenPercent);
                
                manager.addStudent(student);


    
            }

            break;
        }
        
        case 2:
        {
            std::string studentId;

            std::cout << "Enter ID to delete: ";
            std::getline(std::cin, studentId);

            manager.deleteStudent(studentId);

            break;
        }

        case 3:
        {
            manager.searchStudent();
            break;
        }

        case 4:
        {
            std::string studentId;

            std::cout << "Enter ID to update: ";
            std::getline(std::cin, studentId);

            manager.updateStudent(studentId);

            break;
        }

        case 5:
        {

            manager.displayAllStudents();
            break;
        }

        case 0:
        {
            std::cout << "\nExiting Program..." << std::endl;
            return 0;
        }
        
        default:

            std::cout << "Invalid Input!" << std::endl;
            break;
        }
    }

    

    return 0;
}

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}