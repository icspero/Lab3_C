#include <boost/test/included/unit_test.hpp>
#include "../DoubLinList.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestDoublyLinkedList)

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWOPUSH_head) {
    DoublyLinkedList DoublyLinkedList;
    DoublyLinkedList.LTWOPUSH_head(elem1);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    DoublyLinkedList.LTWOPUSH_head(elem2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
    DoublyLinkedList.LTWOPUSH_head(elem3);

    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 3);
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWOPUSH_tail) {
    DoublyLinkedList DoublyLinkedList;
    DoublyLinkedList.LTWOPUSH_tail(elem1);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);

    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 3);       
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWODEL_head) {
    DoublyLinkedList DoublyLinkedList;
    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0);
    DoublyLinkedList.LTWOPUSH_head(elem1);
    DoublyLinkedList.LTWOPUSH_head(elem2);
    DoublyLinkedList.LTWOPUSH_head(elem3);

    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0); 
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWODEL_tail) {
    DoublyLinkedList DoublyLinkedList;
    DoublyLinkedList.LTWODEL_tail();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0);
    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWODEL_tail();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0);
    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);

    DoublyLinkedList.LTWODEL_tail();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);       
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWODEL_value) {
    DoublyLinkedList DoublyLinkedList;

    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);

    DoublyLinkedList.LTWODEL_value(elem1);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.LTWOSearchTest(elem1),-1);
    DoublyLinkedList.LTWODEL_value(elem2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    BOOST_CHECK_EQUAL(DoublyLinkedList.LTWOSearchTest(elem2),-1);
    DoublyLinkedList.LTWODEL_value(elem3);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0);    
    BOOST_CHECK_EQUAL(DoublyLinkedList.LTWOSearchTest(elem3),-2);   
    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);
    DoublyLinkedList.LTWODEL_value(elem2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_LTWOSEARCH) {
    DoublyLinkedList DoublyLinkedList;

    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);

    string notExist = "notExist";
    int temp1 = DoublyLinkedList.LTWOSearchTest(elem1);
    int temp2 = DoublyLinkedList.LTWOSearchTest(elem2);
    int temp3 = DoublyLinkedList.LTWOSearchTest(elem3);

    int test = DoublyLinkedList.LTWOSearchTest(notExist);

    BOOST_CHECK_EQUAL(temp1, 0);
    BOOST_CHECK_EQUAL(temp2, 1);  
    BOOST_CHECK_EQUAL(temp3, 2);
    BOOST_CHECK_EQUAL(test, -1);          
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_SIZE) {
    DoublyLinkedList DoublyLinkedList;

    DoublyLinkedList.LTWOPUSH_tail(elem1);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    DoublyLinkedList.LTWOPUSH_tail(elem2);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);
    DoublyLinkedList.LTWOPUSH_tail(elem3);
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 3);

    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2); 

    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
    DoublyLinkedList.LTWODEL_head();
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 0);
}

BOOST_AUTO_TEST_CASE(TestDoublyLinkedList_DUPLICATES) {
    DoublyLinkedList DoublyLinkedList;
    DoublyLinkedList.LTWOPUSH_tail(elem1);
    DoublyLinkedList.LTWOPUSH_tail(elem1); 

    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 2);

    DoublyLinkedList.LTWODEL_value(elem1); 
    BOOST_CHECK_EQUAL(DoublyLinkedList.Size(), 1);
}

BOOST_AUTO_TEST_SUITE_END()