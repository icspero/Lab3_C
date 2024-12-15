#include <boost/test/included/unit_test.hpp>
#include "../SinLinList.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestSinglyLinkedList)

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONEPUSH_head) {
    SinglyLinkedList SinglyLinkedList;
    SinglyLinkedList.LONEPUSH_head(elem1);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    SinglyLinkedList.LONEPUSH_head(elem2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
    SinglyLinkedList.LONEPUSH_head(elem3);

    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 3);
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONEPUSH_tail) {
    SinglyLinkedList SinglyLinkedList;
    SinglyLinkedList.LONEPUSH_tail(elem1);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
    SinglyLinkedList.LONEPUSH_tail(elem3);

    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 3);       
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONEDEL_head) {
    SinglyLinkedList SinglyLinkedList;
    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0);
    SinglyLinkedList.LONEPUSH_head(elem1);
    SinglyLinkedList.LONEPUSH_head(elem2);
    SinglyLinkedList.LONEPUSH_head(elem3);

    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0); 
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONEDEL_tail) {
    SinglyLinkedList SinglyLinkedList;
    SinglyLinkedList.LONEDEL_tail();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0);
    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEDEL_tail();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0);
    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    SinglyLinkedList.LONEPUSH_tail(elem3);

    SinglyLinkedList.LONEDEL_tail();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);       
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONEDEL_value) {
    SinglyLinkedList SinglyLinkedList;

    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    SinglyLinkedList.LONEPUSH_tail(elem3);

    SinglyLinkedList.LONEDEL_value(elem1);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.LONESearchTest(elem1),-1);
    SinglyLinkedList.LONEDEL_value(elem2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    BOOST_CHECK_EQUAL(SinglyLinkedList.LONESearchTest(elem2),-1);
    SinglyLinkedList.LONEDEL_value(elem3);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0);    
    BOOST_CHECK_EQUAL(SinglyLinkedList.LONESearchTest(elem3),-2);   
    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    SinglyLinkedList.LONEPUSH_tail(elem3);
    SinglyLinkedList.LONEDEL_value(elem2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_LONESEARCH) {
    SinglyLinkedList SinglyLinkedList;

    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    SinglyLinkedList.LONEPUSH_tail(elem3);

    string notExist = "notExist";
    int temp1 = SinglyLinkedList.LONESearchTest(elem1);
    int temp2 = SinglyLinkedList.LONESearchTest(elem2);
    int temp3 = SinglyLinkedList.LONESearchTest(elem3);

    int test = SinglyLinkedList.LONESearchTest(notExist);

    BOOST_CHECK_EQUAL(temp1, 0);
    BOOST_CHECK_EQUAL(temp2, 1);  
    BOOST_CHECK_EQUAL(temp3, 2);
    BOOST_CHECK_EQUAL(test, -1);          
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_SIZE) {
    SinglyLinkedList SinglyLinkedList;

    SinglyLinkedList.LONEPUSH_tail(elem1);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    SinglyLinkedList.LONEPUSH_tail(elem2);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);
    SinglyLinkedList.LONEPUSH_tail(elem3);
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 3);

    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2); 

    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
    SinglyLinkedList.LONEDEL_head();
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 0);
}

BOOST_AUTO_TEST_CASE(TestSinglyLinkedList_DUPLICATES) {
    SinglyLinkedList SinglyLinkedList;
    SinglyLinkedList.LONEPUSH_tail(elem1);
    SinglyLinkedList.LONEPUSH_tail(elem1); 

    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 2);

    SinglyLinkedList.LONEDEL_value(elem1); 
    BOOST_CHECK_EQUAL(SinglyLinkedList.Size(), 1);
}

BOOST_AUTO_TEST_SUITE_END()