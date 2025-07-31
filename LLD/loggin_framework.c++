#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum class LogType { DEBUG, INFO, WARN, ERROR };
enum class FilterType { NETWORKING, DATABASE };

class LogFormatter {
    public:
        LogFormatter() {};
        string format(LogType type, string message);
};

class JSONLogFormatter: public LogFormatter {
    public:
        JSONLogFormatter() {};
        void format(LogType type, string message);
};

class LogHandler {
    public:
        LogHandler();

        void handle(string formattedMessage);
};

class ConsoleLogHandler: public LogHandler {
    public:
        void handle(string formattedMessage);
};

class FileLogHandler: public LogHandler {
    public:
        void handle(string formattedMessage);
};

class ServerLogHandler: public LogHandler {
    public:
        void handle(string formattedMessage);
};

class Logger {
public:
    Logger();

    void setLogLevel(LogType level);
    LogType getLogLevel() const;

    void addHandler(LogHandler* handler);
    void log(LogType type, const std::string& message);    

    void filter(LogType type, FilterType source, string message);
};


int main() {
    Logger log();

    return 0;
}