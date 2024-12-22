#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SinglyLinkedList {
private:

    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    SingleNode* prevTail = nullptr;

public:

    ~SinglyLinkedList() {
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

    void LONEPUSH_head(string& cell) {

        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;

        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }

    void LONEPUSH_tail(string& cell) {
        
        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;
        if (tail == nullptr) {
            head = tail = node;
            prevTail = nullptr;
        }
        else {
            tail->next = node;
            prevTail = tail; 
            tail = node;
            
        }

    }

    void LONEDEL_head() {
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        SingleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
            prevTail = nullptr;
        }

    }

    void LONEDEL_tail() {
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            prevTail = nullptr;
            return;
        }
        SingleNode* current = prevTail;
        prevTail->next = tail->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void LONEDEL_value(string&value) {
        SingleNode* node = head;
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        if (head->cell == value) {
            LONEDEL_head();
            return;
        }
        while (node != nullptr && node->next != nullptr &&  node->next->cell != value ) {
            if (node == nullptr) {
                //cout << "\nЗначение не найдено!" << endl;
                return;
            }
            node = node->next;
        }
        
        SingleNode* toDelete = node->next;  
        node->next = toDelete->next;
        if (toDelete == tail) {
            tail = toDelete;
            prevTail->next = tail->next;
        }
        delete toDelete;
        tail = prevTail;

    }

    int LONESearchTest(string& value) {
        SingleNode* node = head;
        if (head == nullptr) {
            return -2;
        }
        int index = 0;
        if (head->cell == value) {
            return index;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
            index++;
        }
        if (node == nullptr) {
            return -1;
        }
        return index;

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

    void LONE_search(string& value) {
        SingleNode* node = head;
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        int index = 0;
        while (node != nullptr) {
            if (node->cell == value) {
                //cout << "\nЗначение найдено! Индекс: " << index << endl;
                return;
            }
            node = node->next;
            index++;
        }
        
        //cout << "\nЗначение не найдено!" << endl;
    }

    void LONE_read() {
        SingleNode* node = head;
        if (head == nullptr) {
            cout << "\nСписок пуст!" << endl;
            return;
        }
        cout << endl;
        while (node != nullptr) {
            cout << node->cell << " ";
            node = node->next;
        }
        cout << endl;
    }
    
    void WritingFromFileToSinglyLinkedList(SinglyLinkedList& list, const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            //cerr << "Ошибка открытия файла  " << filename << endl;
            return;
        }

        string value;
        while (getline(inFile, value)) {
            list.LONEPUSH_tail(value);
        }

        inFile.close();
    }

    void WritingFromSinglyLinkedListToFile(SinglyLinkedList& list, const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            //cerr << "Ошибка открытия файла " << filename << endl;
            return;
        }

        SingleNode* current = list.head;
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
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); // Чтение длины строки

            if (fileRead.eof())
                break;

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            LONEPUSH_tail(text);
            delete buffer;
        }
        fileRead.close();
    }
};