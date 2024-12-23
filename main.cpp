#include "header.h"
#include "Array.h"
#include "FullBinTree.h"
#include "HashTable.h"
#include "SinLinList.h"
#include "Queue.h"
#include "Stack.h"
#include "DoubLinList.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");

    string filename = "";
    string queryConsole = "";

    // Получение аргументов командной строки
    inputArguments(argc, argv, filename, queryConsole);

    Array array;
    Queue queue;
    Stack stack;
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;
    HashTable hashTable;
    FBT tree;

    int index;
    string commandWord, element, indexStr;
    
    stringstream ss(queryConsole);
    ss >> commandWord;
    ss >> element;
    ss >> indexStr;

    indexStr.erase(0, indexStr.find_first_not_of(" \t"));

    try {
        if (!commandWord.empty() && commandWord.at(0) == 'M'){
            if (filename.find(".txt") != string::npos)  {
                array.WritingFromFileToArray(array, filename);
            } else if (filename.find(".bin") != string::npos) {
                array.BinaryDeserialization(filename);
            }
            if (commandWord == "MPUSH") {
                if (indexStr.empty()) {
                    array.MPUSH_end(element);
                    cout << "Элемент добавлен в конец: " << element << endl;
                } else {
                    index = stoi(indexStr);
                    array.MPUSH_index(index, element);
                    cout << "Элемент добавлен по индексу " << index << ": " << element << endl;
                }
            } else if (commandWord == "MGET") {
                cout << indexStr;
                string value = array.MGET(stoi(element));
                cout << "Элемент по индексу " << element << ": " << value << endl;
            } else if (commandWord == "MDEL") {
                index = stoi(element);
                array.MDEL(index);
                cout << "Элемент с индексом " << index << " удален." << endl;
            } else if (commandWord == "MREP") {
                index = stoi(indexStr);
                array.MREP(index, element);
                cout << "Элемент с индексом " << index << " заменен на: " << element << endl;
            } else if (commandWord == "MSIZE") {
                int size = array.MSIZE();
                cout << "Размер коллекции: " << size << endl;
            } else if (commandWord == "MREAD") {
                array.MREAD();
            }
            if(filename.find(".txt") != string::npos){
                array.WritingFromArrayToFile(array, filename);
            } 
            else if (filename.find(".bin") != string::npos){
                array.BinarySerialization(filename);
            }
        }
        else if (!commandWord.empty() && commandWord.at(0) == 'Q'){
            if (filename.find(".txt") != string::npos) {
                queue.WritingFromFileToQueue(queue, filename);
            }
            else if (filename.find(".bin") != string::npos){
                queue.BinaryDeserialization(filename);
            }
            if (commandWord == "QPUSH") {
                queue.QPUSH(element);
                cout << "Элемент добавлен!" << endl;
            }
            else if(commandWord == "QPOP"){
                queue.QPOP();
                cout << "Элемент удалён!" << endl;
            }
            else if(commandWord == "QREAD"){
                queue.QREAD();
            }
            if (filename.find(".txt") != string::npos) {
                queue.WritingFromQueueToFile(queue, filename);
            }
            else if (filename.find(".bin") != string::npos){
                queue.BinarySerialization(filename);
            }
        } else if (!commandWord.empty() && commandWord.at(0) == 'S') {
            if (filename.find(".txt") != string::npos) {
                stack.WritingFromFileToStack(stack, filename);
            }
            else {
                stack.BinaryDeserialization(filename);
            }
            if (commandWord == "SPUSH") {
                stack.SPUSH(element);
            }
            if (commandWord == "SPOP") {
                stack.SPOP();
            }
            if (commandWord == "SREAD") {
                stack.SREAD();
            }
            if (filename.find(".txt") != string::npos){
                stack.WritingFromStackToFile(stack, filename);
            }
            else if (filename.find(".bin") != string::npos){
                stack.BinarySerialization(filename);
            }
        } else if (!commandWord.empty() && commandWord.at(0) == 'L' && commandWord.at(1) == 'O'){
            if (filename.find(".txt") != string::npos) {
                singlyList.WritingFromFileToSinglyLinkedList(singlyList, filename);
            }
            else if (filename.find(".bin") != string::npos){
                singlyList.BinaryDeserialization(filename);
            }
            if (commandWord == "LONEPUSH_head") {
                singlyList.LONEPUSH_head(element);
            }
            if (commandWord == "LONEPUSH_tail") {
                singlyList.LONEPUSH_tail(element);
            }
            if (commandWord == "LONEDEL_head") {
                singlyList.LONEDEL_head();
            }
            if (commandWord == "LONEDEL_tail") {
                singlyList.LONEDEL_tail();
            }
            if (commandWord == "LONEDEL_value") {
                singlyList.LONEDEL_value(element);
            }
            if (commandWord == "LONE_search") {
                singlyList.LONE_search(element);
            }
            if (commandWord == "LONE_read") {
                singlyList.LONE_read();
            }
            if (filename.find(".txt") != string::npos) {
                singlyList.WritingFromSinglyLinkedListToFile(singlyList, filename);
            }
            else if (filename.find(".bin") != string::npos){
                singlyList.BinarySerialization(filename);
            }
        } else if (!commandWord.empty() && commandWord.at(0) == 'L' && commandWord.at(1) == 'T'){
            if (filename.find(".txt") != string::npos) {
                doublyList.WritingFromFileToDoublyLinkedList(doublyList, filename);
            }
            else if (filename.find(".bin") != string::npos){
                doublyList.BinaryDeserialization(filename);
            }
            if (commandWord == "LTWOPUSH_head") {
                doublyList.LTWOPUSH_head(element);
            }
            if (commandWord == "LTWOPUSH_tail") {
                doublyList.LTWOPUSH_tail(element);
            }
            if (commandWord == "LTWODEL_head") {
                doublyList.LTWODEL_head();
            }
            if (commandWord == "LTWODEL_tail") {
                doublyList.LTWODEL_tail();
            }
            if (commandWord == "LTWODEL_value") {
                doublyList.LTWODEL_value(element);
            }
            if (commandWord == "LTWO_search") {
                doublyList.LTWO_search(element);
            }
            if (commandWord == "LTWO_read") {
                doublyList.LTWO_read();
            }
            if (filename.find(".txt") != string::npos) {
                doublyList.WritingFromDoublyLinkedListToFile(doublyList, filename);
            }
            else if (filename.find(".bin") != string::npos){
                doublyList.BinarySerialization(filename);
            }
        } else if (!commandWord.empty() && commandWord.at(0) == 'H'){
            if (filename.find(".txt") != string::npos) {
                hashTable.WritingFromFileToHashTable(hashTable, filename);
            }
            else if (filename.find(".bin") != string::npos){
                hashTable.BinaryDeserialization(filename);
            }
            string key = indexStr;
            string value = element;
            if (commandWord == "HPUSH") {
                hashTable.HPUSH(key, value);
            }
            if (commandWord == "HDEL") {
                hashTable.HDEL(value);
            }
            if (commandWord == "HGET") {
                string val = hashTable.HGET(value);
                if (val != "Ключ не был найден!"){
                    cout << "Ключ найден! Его значение: " << val << endl; 
                } else {
                    cout << val << endl;
                }
            }
            if (commandWord == "HREAD") {
                hashTable.HREAD();
            }
            if (filename.find(".txt") != string::npos) {
                hashTable.WritingFromHashTableToFile(hashTable, filename);
            }
            else if (filename.find(".bin") != string::npos){
                hashTable.BinarySerialization(filename);
            }
        } else if (!commandWord.empty() && commandWord.at(0) == 'T'){
            if (filename.find(".txt") != string::npos) {
                tree.TLoadFromFile(filename);
            }
            else if (filename.find(".bin") != string::npos){
                tree.BinaryDeserialization(filename);
            }
            if (commandWord == "TINSERT") {
                tree.TPUSH(element);
                cout << "Элемент успешно добавлен!" << endl;
            }
            if (commandWord == "TFULL") {
                bool test = tree.TFULL();
                if (test == true){
                    cout << "Tree full!" << endl;
                } else {
                    cout << "The tree is not full!" << endl;
                }
            }
            if (commandWord == "TSEARCH") {
                bool test = tree.TSEARCH(element);
                if (test){
                    cout << "Элемент найден!" << endl;
                } else {
                    cout << "Элемент не найден!" << endl;
                }
            }
            if (commandWord == "TREAD") {
                tree.TREAD();
            }
            if (filename.find(".txt") != string::npos) {
                tree.TSaveToFileHelper(filename);
            }
            else if (filename.find(".bin") != string::npos){
                tree.BinarySerialization(filename);
            }
        } else {
            cout << "Неизвестная команда: " << commandWord << endl;
        }
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    
    return 0;
}