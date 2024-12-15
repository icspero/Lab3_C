#include <boost/test/included/unit_test.hpp>
#include "../FullBinTree.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestFBT)

BOOST_AUTO_TEST_CASE(TestFBT_TPUSH) {
    FBT tree;

    string A = elem1;
    string B = elem2;
    string C = elem3;

    tree.TPUSH(elem1);
    BOOST_CHECK_EQUAL(tree.Size(), 1);
    tree.TPUSH(elem2);
    BOOST_CHECK_EQUAL(tree.Size(), 2);
    tree.TPUSH(elem3);
    BOOST_CHECK_EQUAL(tree.Size(), 3);
}

BOOST_AUTO_TEST_CASE(TestFBT_TSEARCH) {
    FBT tree;

    string A = elem1;
    string B = elem2;
    string C = elem3;
    string D = "test";

    tree.TPUSH(A);
    tree.TPUSH(B);
    tree.TPUSH(C);

    BOOST_CHECK(tree.TSEARCH(A)); // Элемент должен быть найден
    BOOST_CHECK(tree.TSEARCH(B)); // Элемент должен быть найден
    BOOST_CHECK(tree.TSEARCH(C)); // Элемент должен быть найден
    BOOST_CHECK(!tree.TSEARCH(D)); // Элемент не должен быть найден
}

BOOST_AUTO_TEST_CASE(TestFBT_TFULL) {
    FBT tree;

    BOOST_CHECK(tree.TFULL());

    string A = elem1;
    string B = elem2;
    string C = elem3;

    tree.TPUSH(A);
    tree.TPUSH(B);
    tree.TPUSH(C);

    BOOST_CHECK(tree.TFULL());
}

BOOST_AUTO_TEST_SUITE_END()