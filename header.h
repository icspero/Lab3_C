#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdexcept>  // invalid_argument

using namespace std;

string elem1 = "nstu";
string elem2 = "avtf";
string elem3 = "security";

struct SingleNode {
    string cell;
    SingleNode* next = nullptr;
};

struct DoubleNode {
    string cell;
    DoubleNode* next = nullptr;
    DoubleNode* prev = nullptr;
};

void inputArguments(int argc, char* argv[], string& filename, string& query) {
    bool fileFound = false;
    bool queryFound = false;

    for (int i = 1; i < argc; i++) {
        string part = argv[i];

        if (strcmp(argv[i], "--file") == 0) {
            if (i + 1 < argc && strcmp(argv[i + 1], "--query") != 0) {
                filename = argv[i + 1];
                fileFound = true;
                i++;  // Пропускаем следующий аргумент, так как это значение для --file
            } else {
                // Если --file без аргумента, выбрасываем исключение
                throw std::invalid_argument("Missing file after --file");
            }
        } else if (strcmp(argv[i], "--query") == 0) {
            if (i + 1 < argc) {
                query = argv[i + 1];
                queryFound = true;
                i++;  // Пропускаем следующий аргумент, так как это значение для --query
            } else {
                // Если --query без аргумента, выбрасываем исключение
                throw std::invalid_argument("Missing query after --query");
            }
        }
    }

    // Если --file не найден, но нет ошибки
    if (!fileFound) {
        filename = "";  // Не выбрасываем исключение
    }

    // Если --query не найден, но нет ошибки
    if (!queryFound) {
        query = "";  // Не выбрасываем исключение
    }
}