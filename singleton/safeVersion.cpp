#include <iostream>
using namespace std;

class Logger
{
private:
    Logger()
    {
        cout << "Logger created" << endl;
    }

public:
    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }

    void log()
    {
        cout << "Done" << endl;
    }
};

int main()
{
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();

    logger1.log();

    cout << (&logger1 == &logger2) << endl;

    return 0;
}

