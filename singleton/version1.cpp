#include <iostream>
using namespace std;

class Logger
{
private:
    Logger()
    {
        cout << "Logger created" << endl;
    }

    static Logger instance;

public:
    static Logger& getInstance()
    {
        return instance;
    }

    void log()
    {
        cout << "Done" << endl;
    }
};

Logger Logger::instance;

int main()
{
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();

    logger1.log();

    cout << (&logger1 == &logger2) << endl;

    return 0;
}
