#include <boost/test/included/unit_test.hpp>
#include "../SinLinList.h"
#include "benchmark_header.h"
#include <boost/timer/timer.hpp>

string one = "element";

BOOST_AUTO_TEST_SUITE(BenchmarkSinglyLinkedList)

BOOST_AUTO_TEST_CASE(BenchmarkSinglyLinkedList_LONEPUSH_head) {
    SinglyLinkedList SinglyLinkedList;
    boost::timer::cpu_timer timer;
    timer.start();
    SinglyLinkedList.LONEPUSH_head(one);
    timer.stop();
    string name = "BenchmarkSinglyLinkedList_LONEPUSH_head";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkSinglyLinkedList_LONEPUSH_tail) {
    SinglyLinkedList SinglyLinkedList;
    boost::timer::cpu_timer timer;
    timer.start();
    SinglyLinkedList.LONEPUSH_tail(one);
    timer.stop();
    string name = "BenchmarkSinglyLinkedList_LONEPUSH_tail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkSinglyLinkedList_LONEDEL_head) {
    SinglyLinkedList SinglyLinkedList;
    boost::timer::cpu_timer timer;
    SinglyLinkedList.LONEPUSH_tail(one);
    timer.start();
    SinglyLinkedList.LONEDEL_head();
    timer.stop();
    string name = "BenchmarkSinglyLinkedList_LONEDEL_head";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}
BOOST_AUTO_TEST_CASE(BenchmarkSinglyLinkedList_LONEDEL_tail) {
    SinglyLinkedList SinglyLinkedList;
    boost::timer::cpu_timer timer;
    SinglyLinkedList.LONEPUSH_tail(one);
    timer.start();
    SinglyLinkedList.LONEDEL_tail();
    timer.stop();
    string name = "BenchmarkSinglyLinkedList_LONEDEL_tail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkSinglyLinkedList_LONEDEL_value) {
    SinglyLinkedList SinglyLinkedList;
    boost::timer::cpu_timer timer;
    SinglyLinkedList.LONEPUSH_tail(one);
    timer.start();
    SinglyLinkedList.LONEDEL_value(one);
    timer.stop();
    string name = "BenchmarkSinglyLinkedList_LONEDEL_value";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}


BOOST_AUTO_TEST_SUITE_END()