
#include "benchmark_header.h"
#include <boost/timer/timer.hpp>
#include <boost/test/included/unit_test.hpp>
#include "../Queue.h"

string que = "element";

BOOST_AUTO_TEST_SUITE(BenchmarkQueue)

BOOST_AUTO_TEST_CASE(BenchmarkQueue_QPUSH) {
    Queue queue;
    boost::timer::cpu_timer timer;
    timer.start();
    queue.QPUSH(que);
    timer.stop();
    string name = "BenchmarkQueue_QPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkQueue_QPOP) {
    Queue queue;
    boost::timer::cpu_timer timer;
    queue.QPUSH(que);
    timer.start();
    queue.QPOP();
    timer.stop();
    string name = "BenchmarkQueue_QPOP";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result); 
}

BOOST_AUTO_TEST_SUITE_END()