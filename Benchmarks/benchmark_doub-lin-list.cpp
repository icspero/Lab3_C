#include <boost/test/included/unit_test.hpp>
#include "../DoubLinList.h"
#include "benchmark_header.h"
#include <boost/timer/timer.hpp>

string two = "element";
BOOST_AUTO_TEST_SUITE(BenchmarkDoublyLinkedList)

BOOST_AUTO_TEST_CASE(BenchmarkDoublyLinkedList_LTWOPUSH_head) {
    DoublyLinkedList DoublyLinkedList;
    boost::timer::cpu_timer timer;
    timer.start();
    DoublyLinkedList.LTWOPUSH_head(two);
    timer.stop();
    string name = "BenchmarkDoublyLinkedList_LTWOPUSH_head";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkDoublyLinkedList_LTWOPUSH_tail) {
    DoublyLinkedList DoublyLinkedList;
    boost::timer::cpu_timer timer;
    timer.start();
    DoublyLinkedList.LTWOPUSH_tail(two);
    timer.stop();
    string name = "BenchmarkDoublyLinkedList_LTWOPUSH_tail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkDoublyLinkedList_LTWODEL_head) {
    DoublyLinkedList DoublyLinkedList;
    boost::timer::cpu_timer timer;
    DoublyLinkedList.LTWOPUSH_tail(two);
    timer.start();
    DoublyLinkedList.LTWODEL_head();
    timer.stop();
    string name = "BenchmarkDoublyLinkedList_LTWODEL_head";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}

BOOST_AUTO_TEST_CASE(BenchmarkDoublyLinkedList_LTWODEL_tail) {
    DoublyLinkedList DoublyLinkedList;
    boost::timer::cpu_timer timer;
    DoublyLinkedList.LTWOPUSH_tail(two);
    timer.start();
    DoublyLinkedList.LTWODEL_tail();
    timer.stop();
    string name = "BenchmarkDoublyLinkedList_LTWODEL_tail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkDoublyLinkedList_LTWODEL_value) {
    DoublyLinkedList DoublyLinkedList;
    boost::timer::cpu_timer timer;
    DoublyLinkedList.LTWOPUSH_tail(two);
    timer.start();
    DoublyLinkedList.LTWODEL_value(two);
    timer.stop();
    string name = "BenchmarkDoublyLinkedList_LTWODEL_value";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}

BOOST_AUTO_TEST_SUITE_END()