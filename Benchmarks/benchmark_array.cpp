#include <boost/test/included/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include "../Array.h"
#include "benchmark_header.h"

string Arr = "elem";

BOOST_AUTO_TEST_SUITE(BenchmarkArray)

BOOST_AUTO_TEST_CASE(BenchmarkArray_MPUSH_end) {
    Array array;
    boost::timer::cpu_timer timer;
    timer.start();
    array.MPUSH_end(Arr);
    timer.stop();
    string name = "BenchmarkArray_MPUSH_end";
    string result = "time: " + timer.format(9);
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MPUSH_index) {
    Array array;
    boost::timer::cpu_timer timer;
    timer.start();
    array.MPUSH_index(0,Arr); 
    timer.stop();
    string name = "BenchmarkArray_MPUSH_index";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MDEL) {
    Array array;
    boost::timer::cpu_timer timer;
    array.MPUSH_end(Arr); 
    timer.start();
    array.MDEL(0); 
    timer.stop();
    string name = "BenchmarkArray_MDEL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkArray_MREP) {
    Array array;
    boost::timer::cpu_timer timer;
    string temp = "value";
    array.MPUSH_end(Arr); 
    timer.start();
    array.MREP(0,temp); 
    timer.stop();
    string name = "BenchmarkArray_MREP";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MGETL) {
    Array array;
    boost::timer::cpu_timer timer;
    string temp = "value";
    array.MPUSH_end(Arr); 
    timer.start();
    array.MREP(0,temp); 
    timer.stop();
    string name = "BenchmarkArray_MGETL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_SUITE_END()