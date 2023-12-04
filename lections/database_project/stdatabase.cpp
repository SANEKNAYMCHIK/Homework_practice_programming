#include "stdatabase.h"
#include "utils.h"
#include <fstream>


void printDB(const DataBase& DB) {
    for (int i = 0; i < DB.count; ++i) {
        std::cout << DB.data[i] << std::endl;
    }
}


int addRecord(DataBase& DB) {
    if (DB.count >= DB.maxSize) {
        DB.maxSize = (DB.maxSize > 0) ? 2 * DB.maxSize : 1;
        student* tmp = new student[DB.maxSize];
        for (int i = 0; i < DB.count; ++i) {
            tmp[i] = DB.data[i];
        }
        if (DB.data)
            delete[] DB.data;
        DB.data = tmp;
    }
    std::cin >> DB.data[DB.count];
    ++DB.count;
    return DB.count;
}


void saveDB(const DataBase& DB, const char filename[]) {
    std::ofstream outFile(filename, std::ios_base::binary);
    if (!outFile) {
        std::cout << "Can not open file" << filename << std::endl;
        return;
    }
    outFile.write((const char*) (&DB.count), sizeof(DB.count));
    outFile.write((const char*) DB.data, DB.count * sizeof(DB.data[0]));
    outFile.close();
}


int openDB(DataBase& DB, const char filename[]) {
    std::ifstream inFile(filename, std::ios_base::binary);
    if (!inFile.is_open()) {
        std::cout << "Can not open file" << filename << std::endl;
        return 0;
    }
    int count;
    inFile.read((char*) (&count), sizeof(count));
    if (DB.data) {
        delete[] DB.data;
    }
    DB.data = new student[count];
    DB.count = count;
    DB.maxSize = count;
    inFile.read((char*) (DB.data), count * sizeof(DB.data[0]));
    inFile.close();
    return count;
}


void exportDB(const DataBase& DB, const char filename[]) {
    std::ofstream outFile(filename, std::ios_base::binary);
    if (!outFile) {
        std::cout << "Can not open file" << filename << std::endl;
        return;
    }
    for (int i = 0; i < DB.count; ++i) {
        outFile << DB.data[i] << std::endl;
    }
    outFile.close();
}

int findRecord(const DataBase& DB) {
    std::cout << "Student number: ";
    int tmp = getInt();
    for (int i = 0; i < DB.count; ++i) {
        if (DB.data[i].number == tmp) {
            return i;
        }
    }
    return -1;
}

void setMarks(const DataBase& DB) {
    int index = findRecord(DB);
    if (index < 0) {
        std::cout << "There are no such student in DB" << std::endl;
        return ;
    }
    std::cout << "Input " << marksCount << "marks for student " 
    << DB.data[index].surname << " " 
    << DB.data[index].name << ": ";
    int tmp;
    for (int i = 0; i < marksCount; ++i) {
        tmp = getInt();
        DB.data[index].marks[i] = (tmp < 0) ? -tmp : tmp;

    }
}

void deleteRecord(DataBase& DB) {
    int index = findRecord(DB);
    if (index < 0)
        return ;
    std::cout << "Are you sure? (Y/N)";
    char str[128];
    std::cin.get(str, 128);
    if ((str[0] == 'Y') || (str[0] == 'y')) {
        DB.data[index] = DB.data[DB.count - 1];
        --DB.count;
    }
}

int sortMenu() {
    std::cout << "-------------------- Sorting methods -----------------------\n";
    std::cout << "1. By number\n";
    std::cout << "2. By surname name\n";
    std::cout << "3. By marks" << std::endl;
    return getInt();
}

void sort(DataBase& DB) {
    int action;
    do {
        action = sortMenu();
    } while ((action < 1) || (action > 3));
    switch (action) {
    case 1: mySort(DB.data, DB.count, compareByNumber); break;
    case 2: mySort(DB.data, DB.count, compareBySurname); break;
    case 3: mySort(DB.data, DB.count, compareByMarks); break;
    }
    std::cout << "Database sorted" << std::endl;
}