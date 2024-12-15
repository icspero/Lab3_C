#include <boost/test/included/unit_test.hpp>
#include "../HashTable.h"
#include "../header.h"

string A = "a";
string B = "b";
string C = "c";

BOOST_AUTO_TEST_SUITE(TestHashTable)

BOOST_AUTO_TEST_CASE(TestHashTable_HPUSH) {
    HashTable hashtable;
    hashtable.HPUSH(A, elem1);
    hashtable.HPUSH(B, elem2);
    hashtable.HPUSH(C, elem3);

    string temp1 = hashtable.HGET(A);
    string temp2 = hashtable.HGET(B);
    string temp3 = hashtable.HGET(C);

    BOOST_CHECK_EQUAL(temp1, elem1);
    BOOST_CHECK_EQUAL(temp2, elem2);
    BOOST_CHECK_EQUAL(temp3, elem3);
}

BOOST_AUTO_TEST_CASE(TestHashTable_HDEL) {
    HashTable hashtable;
    hashtable.HPUSH(A, elem1);
    hashtable.HPUSH(B, elem2);
    hashtable.HPUSH(C, elem3);

    hashtable.HDEL(A);
    hashtable.HDEL(B);
    hashtable.HDEL(C);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);       
}

BOOST_AUTO_TEST_CASE(TestHashTable_HGET) {
    HashTable hashtable;

    hashtable.HPUSH(A, elem1);
    hashtable.HPUSH(B, elem2);
    hashtable.HPUSH(C, elem3);

    string temp1 = hashtable.HGET(A);
    string temp2 = hashtable.HGET(B);
    string temp3 = hashtable.HGET(C);
    
    BOOST_CHECK_EQUAL(temp1, elem1);
    BOOST_CHECK_EQUAL(temp2, elem2);
    BOOST_CHECK_EQUAL(temp3, elem3);      

    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.HGET(A), "Ключ не был найден!");
}

BOOST_AUTO_TEST_CASE(TestHashTable_SIZE) {
    HashTable hashtable;

    hashtable.HPUSH(A, elem1);
    hashtable.HPUSH(B, elem2);
    hashtable.HPUSH(C, elem3);
    BOOST_CHECK_EQUAL(hashtable.Size(), 3);

    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.Size(), 2);
    
    hashtable.HDEL(B);
    hashtable.HDEL(C);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);
}

BOOST_AUTO_TEST_CASE(TestHashTable_HASHFUNC) {
    HashTable hashtable;

    int index = hashtable.HashFunc(elem1);

    BOOST_CHECK(index >= 0);
    BOOST_CHECK(index < 1000);
}

BOOST_AUTO_TEST_CASE(TestHashTable_COLLISION) {
    HashTable hashtable;

    hashtable.HPUSH(elem1, elem2);
    hashtable.HPUSH(elem1, elem3);
    hashtable.HPUSH(elem3, elem1);

    string temp1 = hashtable.HGET(elem1);
    string temp2 = hashtable.HGET(elem3);

    BOOST_CHECK_EQUAL(temp1, elem3);
    BOOST_CHECK_EQUAL(temp2, elem1);
}

BOOST_AUTO_TEST_CASE(TestHashTable_EMPTY) {
    HashTable hashtable;

    BOOST_CHECK_EQUAL(hashtable.Size(), 0); 
    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()