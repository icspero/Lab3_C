#include <boost/test/included/unit_test.hpp>
#include "../Array.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestArray)

BOOST_AUTO_TEST_CASE(TestArray_MPUSH_end) {
    Array array;
    array.MPUSH_end(elem1);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MPUSH_end(elem2);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MPUSH_end(elem3);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGET(0);
    string B = array.MGET(1);
    string C = array.MGET(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elem1);
    BOOST_CHECK_EQUAL(B, elem2);
    BOOST_CHECK_EQUAL(C, elem3);
}

BOOST_AUTO_TEST_CASE(TestArray_MPUSH_index) {
    Array array;
    array.MPUSH_index(0, elem1);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MPUSH_index(1, elem2);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MPUSH_index(2, elem3);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGET(0);
    string B = array.MGET(1);
    string C = array.MGET(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elem1);
    BOOST_CHECK_EQUAL(B, elem2);
    BOOST_CHECK_EQUAL(C, elem3);
    string temp = "siiiiuuuu";
    array.MPUSH_index(1, temp);
    string temp1 = array.MGET(1);
    string temp2 = array.MGET(2);
    string temp3 = array.MGET(3);
    temp1.erase(remove(temp1.begin(), temp1.end(), ' '), temp1.end());
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    temp3.erase(remove(temp3.begin(), temp3.end(), ' '), temp3.end());
    BOOST_CHECK_EQUAL(temp1, temp);
    BOOST_CHECK_EQUAL(temp2, elem2);
    BOOST_CHECK_EQUAL(temp3, elem3);
}

BOOST_AUTO_TEST_CASE(TestArray_MDEL) {
    Array array;
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem2);
    array.MPUSH_end(elem3);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    
    string temp = array.MGET(0);
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    BOOST_CHECK_EQUAL(temp, elem3);
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem2);
    array.MPUSH_end(elem3);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MDEL(0);
    int size = array.MSIZE();
    BOOST_CHECK_EQUAL(size, 0);
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem2);
    array.MPUSH_end(elem3);
    array.MDEL(-1); 
    array.MDEL(1001); 
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
}

BOOST_AUTO_TEST_CASE(TestArray_MREP) {
    Array array;
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem2);
    array.MPUSH_end(elem3);
    string temp = "messi";
    array.MREP(0, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MREP(1, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MREP(2, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGET(0);
    string B = array.MGET(1);
    string C = array.MGET(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, temp);
    BOOST_CHECK_EQUAL(B, temp);
    BOOST_CHECK_EQUAL(C, temp);

    string temp1 = "lionel";
    array.MREP(-1, temp1); 
    array.MREP(1001, temp1); 

    A = array.MGET(0);
    B = array.MGET(1);
    C = array.MGET(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, temp); 
    BOOST_CHECK_EQUAL(B, temp);
    BOOST_CHECK_EQUAL(C, temp); 

}

BOOST_AUTO_TEST_CASE(TestArray_MGET) {
    Array array;
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem2);
    array.MPUSH_end(elem3);
    string A = array.MGET(0);
    string B = array.MGET(1);
    string C = array.MGET(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elem1);
    BOOST_CHECK_EQUAL(B, elem2);
    BOOST_CHECK_EQUAL(C, elem3);

    BOOST_CHECK_EQUAL(array.MGET(-1), "ERROR"); 
    BOOST_CHECK_EQUAL(array.MGET(1001), "ERROR"); 
}

BOOST_AUTO_TEST_CASE(TestArray_MSIZE) {
    Array array;
    BOOST_CHECK_EQUAL(array.MSIZE(), 0);

    array.MPUSH_end(elem1);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);

    array.MPUSH_end(elem2);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);

    array.MDEL(1);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
}

BOOST_AUTO_TEST_CASE(TestArray_DUPLICATES) {
    Array array;
    array.MPUSH_end(elem1);
    array.MPUSH_end(elem1);
    string temp1 = array.MGET(0);
    string temp2 = array.MGET(1);
    temp1.erase(remove(temp1.begin(), temp1.end(), ' '), temp1.end());
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    BOOST_CHECK_EQUAL(temp1, elem1); 
    BOOST_CHECK_EQUAL(temp2, elem1); 
}

BOOST_AUTO_TEST_CASE(TestArray_EMPTY) {
    Array array;
    string temp1 = "";
    array.MPUSH_end(temp1);
    string temp2 = array.MGET(0);
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    BOOST_CHECK_EQUAL(temp2, temp1); 
}


BOOST_AUTO_TEST_SUITE_END()