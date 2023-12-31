#include "stdatabase.h"
#include "utils.h"
#include <fstream>


void printDB(const DataBase& DB) {
    Node* now = DB.begin;
    for (int i = 0; i < DB.count; ++i) {
        std::cout << now -> data << std::endl;
        now = now -> next;
    }
}


inline void push_back(DataBase& DB, const student& tmp) {
    Node *newNode = new Node;
    newNode -> data = tmp;
    newNode -> next = nullptr;
    if (DB.begin == nullptr) {
        DB.begin = DB.end = newNode;
    } else {
        DB.end -> next = newNode;
        DB.end = newNode;
    }
    ++DB.count;
}


int addRecord(DataBase& DB) {
    student tmp;
    std::cin >> tmp;
    push_back(DB, tmp);
    return DB.count;
}


void deleteDB(DataBase& DB) {
    Node* now;
    while (DB.begin) {
        now = DB.begin -> next;
        delete DB.begin;
        DB.begin = now;
    }
    DB.end = nullptr;
    DB.count = 0;
}


void saveDB(const DataBase& DB, const char filename[]) {
    std::ofstream outFile(filename, std::ios_base::binary);
    if (!outFile) {
        std::cout << "Can not open file" << filename << std::endl;
        return;
    }
    outFile.write((const char*) (&DB.count), sizeof(DB.count));
    //outFile.write((const char*) DB.data, DB.count * sizeof(DB.data[0]));
    Node* now = DB.begin;
    while (now) {
        outFile.write((const char*) &(now -> data), sizeof(student));
        now = now -> next;
    }
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
    deleteDB(DB);
    student tmp;
    while (inFile.peek() != EOF) {
        inFile.read((char*)&tmp, sizeof(student));
        push_back(DB, tmp);
    }
    
    inFile.close();
    return count;
}


void exportDB(const DataBase& DB, const char filename[]) {
    std::ofstream outFile(filename, std::ios_base::binary);
    if (!outFile) {
        std::cout << "Can not open file" << filename << std::endl;
        return;
    }
    Node* now;
    while (now) {
        outFile << now -> data << std::endl;
        now = now -> next;
    }
    
    outFile.close();
}

Node* findRecord(const DataBase& DB) {
    std::cout << "Student number: ";
    int tmp = getInt();
    Node* now = DB.begin;
    while (now) {
        if (now -> data.number == tmp) {
            return now;
        }
        now = now -> next;
    }
    return nullptr;
}

void setMarks(const DataBase& DB) {
    Node* index = findRecord(DB);
    if (index == nullptr) {
        std::cout << "There are no such student in DB" << std::endl;
        return ;
    }
    std::cout << "Input " << marksCount << "marks for student " 
    << index -> data.surname << " " 
    << index -> data.name << ": ";
    int tmp;
    for (int i = 0; i < marksCount; ++i) {
        tmp = getInt();
        index -> data.marks[i] = (tmp < 0) ? -tmp : tmp;

    }
}

void deleteRecord(DataBase& DB) {
    Node* index = findRecord(DB);
    if (index == nullptr)
        return ;
    std::cout << "Are you sure? (Y/N)";
    char str[128];
    std::cin.get(str, 128);
    if ((str[0] == 'Y') || (str[0] == 'y')) {
        Node* parent = nullptr;
        Node* now = DB.begin;
        while (now != index) {
            parent = now;
            now = now -> next;
        }
        if (now) {
            if (index == DB.end) {
                DB.end = parent;
            }
        }
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


void mySort(DataBase& DB, bool (*comparator)(const student&, const student&)) {
    if (DB.begin == DB.end) {
        return ;
    }
    bool isSorted = false;
    do {
        //split
        DataBase tmp[2];
        unsigned char p = 0; //Number of current list (There is we add values)
        tmp[p].begin = tmp[p].end = DB.begin;
        DB.begin = DB.begin -> next;
        tmp[1 - p].begin = tmp[1 - p].end = nullptr;
        while (DB.begin != nullptr) {
            if (comparator(DB.begin -> data, tmp[p].end -> data)) {
                p = 1 - p;
            }
            if (tmp[p].begin) {
                tmp[p].end -> next = DB.begin;
            } else {
                tmp[p].begin = DB.begin;
            }
            tmp[p].end = DB.begin;
            DB.begin = DB.begin -> next;
        }
        if (tmp[p].end) {
            tmp[p].end -> next = nullptr;
        }
        if (tmp[1 - p].end) {
            tmp[1 - p].end -> next = nullptr;
        }
        
        //Merge
        if (tmp[1 - p].begin != nullptr) {
            //There are 2 lists
            p = comparator(tmp[0].begin -> data, tmp[1].begin -> data) ? 0 : 1;
            DB.begin = DB.end = tmp[p].begin;
            tmp[p].begin = tmp[p].begin -> next;
            while (tmp[p].begin) {
                bool s1 = comparator(tmp[p].begin -> data, DB.end -> data);
                bool s2 = comparator(tmp[1 - p].begin -> data, DB.end -> data);
                if (s1 == s2) {
                    p = comparator(tmp[0].begin -> data, tmp[1].begin -> data) ? 0 : 1;
                } else if(s1) {
                    p = 1 - p;
                }
                DB.end -> next = tmp[p].begin;
                DB.end = DB.end -> next;
                tmp[p].begin = tmp[p].begin -> next;
            }
            DB.end -> next = tmp[1 - p].begin;
            DB.end = tmp[1 - p].end;
        } else {
            //We have only one list, this means the list is already sorted
            DB.begin = tmp[p].begin;
            DB.end = tmp[p].end;
            isSorted = true;
        }
    } while (!isSorted);
    
}


void sort(DataBase& DB) {
    int action;
    do {
        action = sortMenu();
    } while ((action < 1) || (action > 3));
    switch (action) {
    case 1: mySort(DB, compareByNumber); break;
    case 2: mySort(DB, compareBySurname); break;
    case 3: mySort(DB, compareByMarks); break;
    }
    std::cout << "Database sorted" << std::endl;
}