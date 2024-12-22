#include <boost/test/included/unit_test.hpp>
#include "../HashTable.h"
#include "benchmark_header.h"
#include <boost/timer/timer.hpp>

string hashKey = "key";
string hashValue= "value";

BOOST_AUTO_TEST_SUITE(BenchmarkHashTable)

BOOST_AUTO_TEST_CASE(BenchmarkHashTable_HPUSH) {
    HashTable hashtable;
    boost::timer::cpu_timer timer;
    timer.start();
    hashtable.HPUSH(hashKey,hashValue);
    timer.stop();
    string name = "BenchmarkHashTable_HPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkHashTable_HDEL) {
    HashTable hashtable;
    boost::timer::cpu_timer timer;
    hashtable.HPUSH(hashKey,hashValue);
    timer.start();
    hashtable.HDEL(hashKey);
    timer.stop();
    string name = "BenchmarkHashTable_HDEL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);      
}
BOOST_AUTO_TEST_CASE(BenchmarkHashTable_HGET) {
    HashTable hashtable;
    boost::timer::cpu_timer timer;
    hashtable.HPUSH(hashKey,hashValue);
    timer.start();
    hashtable.HGET(hashKey);
    timer.stop();
    string name = "BenchmarkHashTable_HGET";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}


BOOST_AUTO_TEST_SUITE_END()