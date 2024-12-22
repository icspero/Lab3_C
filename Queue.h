#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Queue {
private:
    string cell;
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;

public:

    ~Queue() {
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

    int Size(){
        int count = 0;
        SingleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void QPUSH(string& cell) {
        SingleNode* node = new SingleNode;
        node->cell = cell; 
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    void QPOP() {
        SingleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void QREAD() {
        SingleNode* current = head;
        cout << endl;
        while (current != nullptr) {
            cout << current->cell << " ";
            current = current->next;
        }
        cout << endl;
    }

    void WritingFromFileToQueue(Queue& queue, const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            //cerr << "Ошибка открытия файла  " << filename << endl;
            return;
        }

        string value;
        while (getline(inFile, value)) {
            queue.QPUSH(value);
        }

        inFile.close();
    }

    void WritingFromQueueToFile(Queue& queue, const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            //cerr << "Ошибка открытия файла " << filename << endl;
            return;
        }

        SingleNode* current = queue.head;
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
            
            QPUSH(text);
            delete buffer;
        }
        fileRead.close();
    }
};