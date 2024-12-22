#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Array {
private:  

    string* data;
    int size;
    int capacity;

public:

    Array() : size(0), capacity(100) {
        data = new string[capacity];
    }

    ~Array() {
        delete[] data;  
    }

    void MPUSH_end(string& value) {
        data[size++] = value;
    }

    void MPUSH_index(const int& index, string& value) {
        if (index < 0 || index > size) {
            //cout << endl << "Неверный ввод!" << endl;
            return;
        }
        for (int i = size; i > index; i--) { 
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++; 
    }

    string MGET(const int& index) {
        if (index < 0 || index >= size ) {
            //cout << endl << "Неверный ввод!" << endl;
            return "ERROR";
        }
        return data[index]; 
    }

    void MDEL(const int& index) {
        if (index < 0 || index >= size ) {
            //cout << endl << "Неверный ввод!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) { 
            data[i] = data[i + 1];
        }
        size--; 
    }

    void MREP(const int& index, string& value) {
        if (index < 0 || index >= size ) {
            //cout << endl << "Неверный ввод!" << endl;
            return;
        }
        data[index] = value; 
    }

    int MSIZE() {
        return size;  
    }

    void MREAD() {
        cout << endl;
        for (int i = 0; i < size; i++) {  
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void WritingFromFileToArray(Array& array, const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            //cerr << "Ошибка открытия файла " << filename << endl;
            return;
        }

        string value;
        while (getline(inFile, value)) {
            array.MPUSH_end(value);
        }

        inFile.close();
    }

    void WritingFromArrayToFile(Array& array, const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            //cerr << "Ошибка открытия файла  " << filename << endl;
            return;
        }

        for (int i = 0; i < array.size; ++i) {
            outFile << array.MGET(i) << endl;
        }

        outFile.close();
    }

    void BinarySerialization(string& fileName) {
        ofstream File(fileName, ios::binary);
        for (int i = 0; i < size; i++) {
            string value = MGET(i);
            int valueLen = value.size();
            File.write(reinterpret_cast<char*>(&valueLen), sizeof(valueLen));
            File.write(value.c_str(), valueLen);
        }
        File.close();
    }

    void BinaryDeserialization(string& fileName) {
        ifstream File(fileName, ios::binary);
        while (File) {
            int len;
            File.read(reinterpret_cast<char*>(&len), sizeof(len)); 

            if (File.eof())
                break;

            char* buffer = new char[len + 1];
            File.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            data[size++] = text;
            delete buffer;
        }
        File.close();
    }
};