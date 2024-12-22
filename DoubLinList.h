#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DoublyLinkedList {
private:

    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;

public:

    ~DoublyLinkedList() {
        Clear();
    }

    void Clear() {
        while (head != nullptr) {
            DoubleNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    int LTWOSearchTest(string& value) {
        DoubleNode* node = head;
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
        DoubleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void  LTWOPUSH_head(string& element) {
        DoubleNode* node = new DoubleNode;
        node->cell = element;
        node->next = nullptr;
        node->prev = nullptr;

        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void LTWOPUSH_tail(string& element) {
        DoubleNode* node = new DoubleNode;
        node->cell = element;
        node->next = nullptr;
        node->prev = nullptr;
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void LTWODEL_head() {
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        DoubleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void LTWODEL_tail() {
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        DoubleNode* current = tail->prev; 
        current->next = tail->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
        tail->prev = current->prev;
    }

    void LTWODEL_value(string& value) {
        DoubleNode* node = head;
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        if (head->cell == value) {
            LTWODEL_head();
            return;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
        }
        if (node == nullptr) {
            //cout << "\nЗначение не найдено!" << endl;
            return;
        }
        if(node->prev) {
            node->prev->next = node->next;
        }
        else {
            head = node->prev;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        else {
            tail = node->next;
        }

        delete node;

    }

    void LTWO_search(string& value) {
        DoubleNode* node = head;
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        int index = 0;
        if (head->cell == value) {
            //cout << "\nЭлемент найден! Индекс: " << index << endl;
            return;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
            index++;
        }
        if (node == nullptr) {
            //cout << "\nЗначение не найдено!" << endl;
            return;
        }
        //cout << "\nЭлемент найден! Индекс: " << index << endl;

    }

    void LTWO_read() {
        DoubleNode* node = head;
        if (head == nullptr) {
            //cout << "\nСписок пуст!" << endl;
            return;
        }
        cout << endl;
        while (node != nullptr) {
            cout << node->cell << " ";
            node = node->next;
        }
        cout << endl;
    }

    void WritingFromFileToDoublyLinkedList(DoublyLinkedList& list, const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            //cerr << "Ошибка открытия файла  " << filename << endl;
            return;
        }

        string value;
        while (getline(inFile, value)) {
            list.LTWOPUSH_tail(value);
        }

        inFile.close();
    }

    void WritingFromDoublyLinkedListToFile(DoublyLinkedList& list, const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            //cerr << "Ошибка открытия файла " << filename << endl;
            return;
        }

        DoubleNode* current = list.head;
        while (current != nullptr) {
            outFile << current->cell << endl;
            current = current->next;
        }

        outFile.close();
    }

    void BinarySerialization(string& filename) {
        ofstream FileWrite(filename, ios::binary);

        DoubleNode* current = head;

        while (current != nullptr) {
            int len = current->cell.size();
            FileWrite.write(reinterpret_cast<char*>(&len), sizeof(len)); //сначала записываем длины строк
            FileWrite.write(current->cell.c_str(), len); //затем записываем данные с начала туда до /0

            current = current->next;
        }
        FileWrite.close();
    }

    void BinaryDeserialization(string& filename) {
        ifstream fileRead(filename, ios::binary);

        DoubleNode* current = nullptr;
        DoubleNode* tail = nullptr;

        while (fileRead) {
            int len;
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); //чтение длины строки

            if (fileRead.eof())
                break;

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            LTWOPUSH_tail(text);
            delete buffer;
        }
        fileRead.close();
    }
};