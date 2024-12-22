#include <boost/test/included/unit_test.hpp>
#include "../FullBinTree.h"
#include "benchmark_header.h"
#include <boost/timer/timer.hpp>

string fbt = "element";

BOOST_AUTO_TEST_SUITE(BenchmarkFBT)

BOOST_AUTO_TEST_CASE(BenchmarkFBT_TPUSH) {
    FBT FBT;
    boost::timer::cpu_timer timer;
    timer.start();
    FBT.TPUSH(fbt);
    timer.stop();
    string name = "BenchmarkFBT_TPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkFBT_TFULL) {
    FBT FBT;
    boost::timer::cpu_timer timer;
    FBT.TPUSH(fbt);
    FBT.TPUSH(fbt);
    FBT.TPUSH(fbt);
    timer.start();
    FBT.TFULL();
    timer.stop();
    string name = "BenchmarkFBT_TPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkFBT_TSEARCH) {
    FBT FBT;
    boost::timer::cpu_timer timer;
    FBT.TPUSH(fbt);
    timer.start();
    FBT.TSEARCH(fbt);
    timer.stop();
    string name = "BenchmarkFBT_TSEARCH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_SUITE_END()