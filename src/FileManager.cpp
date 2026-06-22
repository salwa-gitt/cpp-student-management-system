#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "Student.h"
#include "FileManager.h"

FileManager::FileManager(const std::string& path)
    : filePath(path)
{
    ensureFileExists();
}

void FileManager::saveToFile(const std::vector<Student>& students)
{
    // Ensure the directory and file exist before writing
    ensureFileExists();

    std::ofstream file(filePath);
    
    if (!file)
    {
        std::cout << "Error: could not open file for writing: " << filePath << std::endl;
        return;
    }

    // write header first
    file << "ID | Name | Age | Department | CGPA | Attendance%\n";

    // writing each student as a line
    for (const auto& student: students)
    {
        file << student.getStudentId() << " | "
             << student.getName() << " | "
             << student.getAge() << " | "
             << student.getDepartment() << " | "
             << student.getCgpa() << " | "
             << student.getAttendancePercentage() << '\n';
    }
    // RAII will close stream
}


std::vector<Student> FileManager::loadFromFile()
{
    std::vector<Student> students;

    std::ifstream file(filePath);
    if (!file)
    {
        return students;
    }

    std::string line;

    // read header (if present) and ignore
    if (!std::getline(file, line))
        return students;

    while (std::getline(file, line))
    {
        // Skip entirely empty lines
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            continue;

        std::stringstream ss(line);

        std::string idStr, name, ageStr, dept, cgpaStr, attStr;

        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, ageStr, '|');
        std::getline(ss, dept, '|');
        std::getline(ss, cgpaStr, '|');
        std::getline(ss, attStr, '|');

        trim(idStr);
        trim(name);
        trim(ageStr);
        trim(dept);
        trim(cgpaStr);
        trim(attStr);

        if (ageStr.empty() || cgpaStr.empty() || attStr.empty())
            continue;

        int age = 0;
        double cgpa = 0.0;
        int attendance = 0;

        try {
            age = std::stoi(ageStr);
            cgpa = std::stod(cgpaStr);
            attendance = std::stoi(attStr);
        } catch (...) {
            // skip malformed lines
            continue;
        }

        Student s(idStr, name, age, cgpa, dept, attendance);
        students.push_back(s);
    }

    return students;
}

void FileManager::trim(std::string& str)
{
    const std::string whitespace = " \t\n\r\f\v";

    const auto start = str.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        str.clear();
        return;
    }

    const auto end = str.find_last_not_of(whitespace);
    str = str.substr(start, end - start + 1);
}

void FileManager::ensureFileExists()
{
    // ensure directory exists
    std::filesystem::path p = std::filesystem::path(filePath).parent_path();
    if (!p.empty())
    {
        std::filesystem::create_directories(p);
    }

    // if file doesn't exist, create and write header
    if (!std::filesystem::exists(filePath))
    {
        std::ofstream createFile(filePath);
        if (createFile)
        {
            createFile << "ID | Name | Age | Department | CGPA | Attendance%\n";
        }
    }
}
