#ifndef _ST_DATABASE_2023_
#define _ST_DATABASE_2023_
#include "student.h"


struct Node {
    student data;
    Node* next;
};


struct DataBase {
    int count;
    Node* begin;
    Node* end;
};


void printDB(const DataBase& DB);
int addRecord(DataBase& DB);
void saveDB(const DataBase& DB, const char filename[]);
int openDB(DataBase& DB, const char filename[]);
void exportDB(const DataBase& DB, const char filename[]);
Node* findRecord(const DataBase& DB);
void setMarks(const DataBase& DB);
void deleteRecord(DataBase& DB);
void sort(DataBase& DB);
void deleteDB(DataBase& DB);
void mySort(DataBase& DB, bool (*comparator)(const student&, const student&));

/*template <typename T>
void mySort(T* M, int size, bool (*comparator)(const T&, const T&)) {
    for (int i = 0; i < size; ++i) {
        int k = i;
        for (int j = i + 1; j < size; ++j) {
            if (comparator(M[j], M[k])) {
                k = j;
            }
        }
        if (i < k) {
            std::swap(M[i], M[k]);
        }
    }
}*/


#endif