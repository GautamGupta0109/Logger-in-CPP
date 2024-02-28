#include<stdio.h>
#include<mutex>
#include<thread>
#include<ctime>

using namespace std;

enum LogPriority
{
    TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
    private:
        static LogPriority priority;
        //static bool file_output;
        static const char* filepath;
        static FILE* file;

    public:

        static void set_priority(LogPriority newPriority)
        {
            priority = newPriority;
        }

        static void EnableFileOutput()
        {
            filepath = "log.txt";
            enable_file_output();
        }

        static void EnableFileOutput(const char* newFilePath)
        {
            filepath = newFilePath;
            enable_file_output();
        }

        static void close_file_output()
        {
            free_file();
        }

        template<typename... Args>
        static void Trace(const char* message , Args... args)
        {
            log("[TRACE]\t" , TracePriority , message , args...);
        }
        template<typename... Args>
        static void Debug(const char* message , Args... args)
        {
            log("[DEBUG]\t" , DebugPriority , message , args...);
        }
        template<typename... Args>
        static void Info(const char* message , Args... args)
        {
           log("[INFO]\t" , InfoPriority , message , args...);
        }
        template<typename... Args>
        static void Warn(const char* message , Args... args)
        {
           log("[WARN]\t" , WarnPriority , message , args...);
        }
        template<typename... Args>
        static void Error(const char* message , Args... args)
        {
           log("[ERROR]\t" , ErrorPriority , message , args...);
        }
        template<typename... Args>
        static void Critical(const char* message , Args... args)
        {
            log("[CRITICAL]\t" , CriticalPriority , message , args...);
        }

    private:
        template<typename... Args>
        static void log(const char* message_priority_str , LogPriority message_priority , const char* message , Args... args)
        {
            if(priority <= message_priority)
            {
                time_t current_time = time(0);
                tm* timestamp = localtime(&current_time);
                char buffer[80];
                strftime(buffer , 80 , "%c" , timestamp);
                
                printf("%s\t",buffer);
                printf(message_priority_str);
                printf(message , args...);
                printf("\n");

                if(file)
                {
                    fprintf(file , "%s\t",buffer);
                    fprintf(file , message_priority_str);
                    fprintf(file , message , args...);
                    fprintf(file , "\n");

                }
            }

        }

        static void enable_file_output()
        {
            
            if(file != 0)
            {
                fclose(file);
            }

            file = fopen(filepath , "a");

            if(file == 0)
            {
                printf("Logger :: Failed to open file at %s", filepath);
            }
        }

        static void free_file()
        {   
            fclose(file);
            file = 0;

        }
        
};

LogPriority Logger::priority = InfoPriority;
//mutex Logger::log_mutex;
///bool Logger::file_output = false;
const char* Logger::filepath = 0;
FILE* Logger::file = 0;



