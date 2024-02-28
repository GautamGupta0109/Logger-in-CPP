#include <iostream>
#include "logging.h"
#include <thread>
#include<vector>

using namespace std;


void log_test(int n)
{
    Logger::Info("%d" , n);
}

int main()
{
    // int a = 101;
    // const char* name = "Gautam";
    // Logger::set_priority(TracePriority);
    // Logger::Trace("Log test %d %s" , a , name);
    // Logger::Debug("Log test %d %s" , a , name);
    // Logger::Info("Log test %d %s" , a , name);
    // Logger::Warn("Log test %d %s" , a , name);
    // Logger::Error("Log test %d %s" , a , name);
    // Logger::Critical("Log test %d %s" , a , name);
    
    Logger::EnableFileOutput();
    
    thread thr[5];

    for(int i = 0 ; i<5 ; i++)
    {
        thr[i] = thread(log_test , i);
    }

    for(int i = 0 ; i<5 ; i++)
    {
        thr[i].join();
    }

    Logger::close_file_output();

   return 0;
}
