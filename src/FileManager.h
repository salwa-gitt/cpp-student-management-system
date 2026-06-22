#pragma once
#include <string>
#include <vector>
#include "Student.h"

class FileManager{
    
    private:
        std::string filePath;

    public:

        // Optional path parameter makes the data file configurable for testing
        FileManager(const std::string& path = "data/students.txt");

        // Save the full student list (overwrites file, writes header)
        void saveToFile(const std::vector<Student>& students);

        // Load all students from the data file
        std::vector<Student> loadFromFile();

        // Trim whitespace from strings
        void trim(std::string& str);

        // Ensure the data file and its directory exist
        void ensureFileExists();

    
};