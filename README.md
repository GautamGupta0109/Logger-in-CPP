# Logger-in-CPP


Logging is a process of generating and storing logs or records of events that have occured in a system. Log management is the process of collecting, storing, analyzing and monitoring log data. Logging information can be used to troubleshoot issues, monitor programs and track activity.
Logs can be generated either by OS itself or by application running in the program.

It is a logging system that uses multithreading in the process.

In this we have created a .h file where we have logger class with its member function that used to present logs in the console and also stores them in the .txt file, In the class we have created different function that have given the priority of the logs based on the logs which log it is. There are 6 priority - Trace, Debug, Info, Warning, Error, Critical. Based on the logs we call different class functions with the respective msg we want to store with the time of log and it will store the log in its file. 
