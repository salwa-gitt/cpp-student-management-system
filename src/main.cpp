#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
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
        std::cout << "6. Sort All Students" << std::endl;
        std::cout << "7. Show Statistics" << std::endl;
        std::cout << "8. Filter by department" << std::endl;
        std::cout << "9. Show students at risk" << std::endl;
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
            std::cout << "\n========================================= STUDENTS DISPLAY =========================================\n";
            manager.displayAllStudents();
            break;
        }

        case 6:
        {
            manager.sortStudents();
            break;
        }

        case 7:
        {

            std::cout << "\n========================================= SYSTEM STATISTICS =========================================\n";
            

            std::cout << std::left 
            << std::setw(15) << "Total Students"
            << std::setw(15) << "Avg CGPA"
            << std::setw(25) << "Highest CGPA Student"
            << std::setw(25) << "Lowest CGPA Student"
            << std::endl;

            std::cout << "-------------------------------------------------------------------------------------------------\n";

            std::cout << std::left 
            << std::setw(15) << manager.totalStudents()
            << std::setw(15) << manager.averageCgpa()
            << std::setw(25) << manager.highestCgpaStudent()
            << std::setw(25) << manager.lowestCgpaStudent()
            << std::endl;
            
            std::cout << "=================================================================================================\n";

            break;
        }

        case 8:
        {
            manager.filterByDepartment();
            break;
        }

        case 9:
        {
            std::cout << "\n========================================= STUDENTS AT RISK =========================================\n";
            std::cout << "\n------------------------------------------- attendance < 75% -------------------------------------------\n";
            manager.studentBelowThreshold();
            std::cout << "-------------------------------------------------------------------------------------------------\n";
        }

        case 0:
        {
            std::cout << "\nExiting Program..." << std::endl;
            return 0;
        }
        
        default:

            std::cout << "\nInvalid Input!" << std::endl;
            break;
        }
    }

    return 0;
}

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}