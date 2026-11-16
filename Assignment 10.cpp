// Assignment 10: CSV file reader/writer using fstream and file pointers
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName = "students.csv";
    fstream file;

    // Write records to CSV file
    file.open(fileName, ios::out);
    if (!file.is_open()) {
        cout << "File could not be created." << endl;
        return 1;
    }

    file << "Roll,Name,Marks" << endl;
    file << "1,Amit,85" << endl;
    file << "2,Neha,92" << endl;
    file << "3,Rahul,78" << endl;

    cout << "Write pointer position (tellp): " << file.tellp() << endl;
    file.close();

    // Read records from CSV file
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    cout << "\nCSV File Contents:" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "Read pointer position (tellg): " << file.tellg() << endl;

    // seekg moves the reading pointer
    file.clear(); // Clear end-of-file state
    file.seekg(0, ios::beg);
    cout << "\nAfter seekg(0), first line: ";
    getline(file, line);
    cout << line << endl;
    cout << "Read pointer after seekg (tellg): " << file.tellg() << endl;
    file.close();

    // seekp moves the writing pointer
    file.open(fileName, ios::in | ios::out);
    if (!file.is_open()) {
        cout << "File could not be opened for updating." << endl;
        return 1;
    }

    file.seekp(0, ios::end);
    cout << "\nWrite pointer before adding record (tellp): "
         << file.tellp() << endl;
    file << "4,John,88" << endl;
    cout << "Write pointer after adding record (tellp): "
         << file.tellp() << endl;

    file.close();
    cout << "\nUpdated CSV file: " << fileName << endl;

    return 0;
}
