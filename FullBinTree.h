#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FBT {
private:

    struct FBTnode {

        string key;
        FBTnode* left;
        FBTnode* right;
        int height;

        FBTnode(string key) : key(key), left(nullptr), right(nullptr), height(1) {}

    };
    FBTnode* root;
    
    string key;
    unsigned char height;
    SingleNode* left;
    SingleNode* right;

public:

    FBT() : root(nullptr) {};
    ~FBT() {
        TDestroyFBT(root);
    }

    void TDestroyFBT(FBTnode* node) {
        if (node == nullptr) {
            return;
        }
        TDestroyFBT(node->left);
        TDestroyFBT(node->right);
        delete node;
    }

    int FindSize(FBTnode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + FindSize(node->left) + FindSize(node->right);
    }

    int Size() {
        return FindSize(root);
    }

    FBTnode* TInsert(FBTnode* node, string& key) {
        // Если текущий узел пустой, создаем новый узел и возвращаем его
        if (node == nullptr) {
            return new FBTnode(key);
        }

        // Если у узла есть только один потомок, добавляем в недостающий
        if (node->left == nullptr) {
            node->left = TInsert(node->left, key);
        } else if (node->right == nullptr) {
            node->right = TInsert(node->right, key);
        } 
        // Если оба потомка существуют, рекурсивно переходим в левое поддерево,
        // затем в правое поддерево
        else {
            // Определяем, куда двигаться: в левое или правое поддерево
            // Для FBT идем влево, пока все уровни слева не заполнены
            if (IsFullBinaryTree(node->left)) {
                node->right = TInsert(node->right, key);
            } else {
                node->left = TInsert(node->left, key);
            }
        }

        // Возвращаем текущий узел
        return node;
    }

    bool IsFullBinaryTree(FBTnode* node) {
        // Базовый случай: пустое дерево
        if (node == nullptr) {
            return true;
        }

        // Если узел — лист (нет потомков)
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }

        // Если оба потомка существуют, проверяем их рекурсивно
        if (node->left != nullptr && node->right != nullptr) {
            return IsFullBinaryTree(node->left) && IsFullBinaryTree(node->right);
        }

        // Если один из потомков отсутствует, дерево не является полным бинарным
        return false;
    }

    FBTnode* TSearch(FBTnode* node, string & key) {
        if (node == nullptr || node->key == key) {// если узел пустой или ключ найден, возвращаем узел
            return node;
        }

        if (key < node->key)
            return TSearch(node->left, key); 
        else
            return TSearch(node->right, key);
    }

    void TDisplay(FBTnode* node) {
        if (node != nullptr) {
            cout << node->key << " "; // выводим ключ текущего узла
            TDisplay(node->left); // рекурсивно обходим левое поддерево
            TDisplay(node->right); // рекурсивно обходим правое поддерево
        }
    }

    void TSaveToFile(FBTnode* node, ofstream& FileWrite) {
        if (node == nullptr) {
            return;
        }

        FileWrite << node->key << " "; // записываем ключ текущего узла

        // рекурсивно записываем левое и правое поддеревья
        TSaveToFile(node->left, FileWrite);
        TSaveToFile(node->right, FileWrite);
    }

    void TPUSH(string &key) {
        root = TInsert(root, key);
    }

    bool TFULL() {
        return IsFullBinaryTree(root);
    }

    bool TSEARCH(string&key) {
        return TSearch(root, key) != nullptr;
    }

    void TREAD() {
        TDisplay(root);
        cout << endl;
    }

    void TLoadFromFile(const string& filename) {
        ifstream FileRead(filename);
        if (!FileRead.is_open()) {
            //cerr << "Ошибка открытия файла для чтения: " << filename << endl;
            return;
        }

        string key;
        while (FileRead >> key) { // считываем ключи из файла
            TPUSH(key);          // добавляем их в дерево
        }

        FileRead.close();
    }

    void TSaveToFileHelper(const string& filename) {
        ofstream FileWrite(filename); // открытие файла для записи
        if (!FileWrite.is_open()) {
            //cerr << "Ошибка открытия файла для записи: " << filename << endl;
            return;
        }

        TSaveToFile(root, FileWrite); // рекурсивно сохраняем дерево
        FileWrite.close();
    } 

    void SavingProcess(FBTnode* node, ofstream& FileWrite) {
        if (node == nullptr) {
            return;
        }

        FileWrite << node->key << " ";

        SavingProcess(node->left, FileWrite);
        SavingProcess(node->right, FileWrite);
    }

    void BinarySerialization(string& filename) {
        ofstream File(filename, ios::binary);
        SavingProcessBionary(root, File);
        File.close();
    }
    void SavingProcessBionary(FBTnode* node, ofstream& File) {
        if (node == nullptr) {
            int markerZero = 0;
            File.write(reinterpret_cast<char*>(&markerZero), sizeof(markerZero));
        }
        else {
            int markerOne = 1;
            File.write(reinterpret_cast<char*>(&markerOne), sizeof(markerOne));

            int keyLen = node->key.length();
            File.write(reinterpret_cast<char*>(&keyLen), sizeof(keyLen));
            File.write(node->key.c_str(), keyLen);

            SavingProcessBionary(node->left, File);
            SavingProcessBionary(node->right, File);
        }
    }

    void BinaryDeserialization(string& filename) {
        ifstream File(filename, ios::binary);
        if (File.peek() == ifstream::traits_type::eof()) {
            return;
        }
        LoadFromBinaryFileRecursive(root, File);
        File.close();
    }

    void LoadFromBinaryFileRecursive(FBTnode*& node, ifstream& File) {
        int marker;
        File.read(reinterpret_cast<char*>(&marker), sizeof(marker));

        if (marker == 0) {
            node = nullptr;
        }
        else {
            int keyLen;
            File.read(reinterpret_cast<char*>(&keyLen), sizeof(keyLen));
            char* buffer = new char[keyLen + 1];
            File.read(buffer, keyLen);
            buffer[keyLen] = '\0'; 

            node = new FBTnode(buffer);
            delete[] buffer;

            LoadFromBinaryFileRecursive(node->left, File);
            LoadFromBinaryFileRecursive(node->right, File);
        }
    }
};