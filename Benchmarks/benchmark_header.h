#pragma once
#include <fstream>          
#include <iostream>        
#include <string>    
#include <boost/timer/timer.hpp> 
#include <boost/regex.hpp> 
using namespace std;

void SaveBenchmarkReport(string& name, string& result) {
    ofstream benchmark_report("Benchmarks.html", ios::app);
    if (benchmark_report.is_open()) {
        benchmark_report << "<html><head><title>Benchmark Report</title></head><body>";
        benchmark_report << "<h3>" << name << "</h3>";
        benchmark_report << "<p>" << result << "</p>";
        benchmark_report.close();
    }
    else {
        cout << endl<< "error" << endl;
    }
}