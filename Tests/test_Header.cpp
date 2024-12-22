#include <boost/test/included/unit_test.hpp>
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestHeader)

BOOST_AUTO_TEST_CASE(TestHeader_ARGUMENTS) {
    string filename;
    string query;
    const char* args[] = {"./program", "--file", "file.txt", "--query", "PUSH element cristiano"};
    int argc = 5;

    inputArguments(argc, const_cast<char**>(args), filename, query); //const_cast убирает const

    BOOST_CHECK_EQUAL(filename, "file.txt");
    BOOST_CHECK_EQUAL(query, "PUSH element cristiano");
}

BOOST_AUTO_TEST_CASE(TestHeader_EMPTY) {
    string filename1;
    string query1;
    string filename2;
    string query2;
    int argc = 1;  // Нет аргументов

    // Пустые аргументы
    const char* args1[] = {"./program"};
    inputArguments(argc, const_cast<char**>(args1), filename1, query1);

    BOOST_CHECK(filename1.empty());
    BOOST_CHECK(query1.empty());
}

BOOST_AUTO_TEST_CASE(TestHeader_MISSINGS) {
    string filename1;
    string query1;
    string filename2;
    string query2;
    int argc = 4;

    // Проверка для --file
    const char* args1[] = {"./program", "--file", "--query", "PUSH element cristiano"};
    BOOST_CHECK_THROW(inputArguments(argc, const_cast<char**>(args1), filename1, query1), invalid_argument);

    // Проверка для --query
    const char* args2[] = {"./program", "--file", "file.txt", "--query"};
    BOOST_CHECK_THROW(inputArguments(argc, const_cast<char**>(args2), filename2, query2), invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()