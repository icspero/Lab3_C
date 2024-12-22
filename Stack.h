#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Stack {
private:
    string cell;
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
public:

    ~Stack() {
        Clear();
    }

    void Clear() {
        while (head != nullptr) {
            SingleNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    int Size() const {
        int count = 0;
        SingleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void SPUSH(string& cell) {
        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }

    void SPOP() {
        if (head == tail) {  
            delete head;      
            head = tail = nullptr; 
            return;
        }
        SingleNode* current = head;
        head = head->next;
        delete current;
    }

    void SREAD() {
        SingleNode* current = head;
        cout << endl;
        while (current != nullptr) {
            cout << current->cell << " ";
            current = current->next;
        }
        cout << endl;
    }

    void WritingFromFileToStack(Stack& stack, const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            //cerr << "Ошибка открытия файла  " << filename << endl;
            return;
        }

        string value;
        while (getline(inFile, value)) {
            stack.SPUSH(value);
        }

        inFile.close();
    }

    void WritingFromStackToFile(Stack& stack, const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            //cerr << "Ошибка открытия файла " << filename << endl;
            return;
        }

        SingleNode* current = stack.head;
        while (current != nullptr) {
            outFile << current->cell << endl;
            current = current->next;
        }

        outFile.close();
    }

    void BinarySerialization(string& filename) {
        ofstream FileWrite(filename, ios::binary);

        SingleNode* current = head;

        while (current != nullptr) {
            int len = current->cell.size();
            FileWrite.write(reinterpret_cast<char*>(&len), sizeof(len)); 
            FileWrite.write(current->cell.c_str(), len); 

            current = current->next;
        }
        FileWrite.close();
    }

    void BinaryDeserialization(string& filename) {
        ifstream fileRead(filename, ios::binary);

        while (fileRead) {
            int len;
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); 

            if (fileRead.eof())
                break;

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            SingleNode* node = new SingleNode;
            node->cell = text;
            node->next = nullptr;

            if (head == nullptr) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
            delete buffer;
        }
        fileRead.close();
    }
};