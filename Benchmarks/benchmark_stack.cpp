#include "benchmark_header.h"
#include <boost/timer/timer.hpp>
#include <boost/test/included/unit_test.hpp>
#include "../Stack.h"

string st = "element";

BOOST_AUTO_TEST_SUITE(BenchmarkStack)

BOOST_AUTO_TEST_CASE(BenchmarkStack_SPUSH) {
    Stack stack;
    boost::timer::cpu_timer timer;
    timer.start();
    stack.SPUSH(st);
    timer.stop();
    string name = "BenchmarkStack_SPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkStack_SPOP) {
    Stack stack;
    boost::timer::cpu_timer timer;
    stack.SPUSH(st);
    timer.start();
    stack.SPOP();
    timer.stop();
    string name = "BenchmarkStack_SPOP";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result); 
}

BOOST_AUTO_TEST_SUITE_END()