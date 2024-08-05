// Fifth Principle of SOLID
// D : Dependency Inversion Principle
// Example of Data Access 

#include <iostream>
#include <string>

using namespace std;

class ILogger {
public:
    virtual void log(const string &message) = 0; 
    virtual ~ILogger() {} 
};

class FileLogger : public ILogger {
public:
    void log(const string &message) override {
        std::cout << "File Log: " << message << std::endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void log(const string &message) override {
        std::cout << "Database Log: " << message << std::endl;
    }
};

class DataAccessLayer {
private:
    ILogger &logger; 

public:
    DataAccessLayer(ILogger &logger) : logger(logger) {}

    void addCustomer(const string &name) {
        logger.log("Customer added: " + name);
    }
};

int main() {
    FileLogger fileLogger;
    DataAccessLayer dal(fileLogger);
    dal.addCustomer("Arsalan Ahmed");
    
    //  DatabaseLogger databaseLogger;
    // DataAccessLayer dal(databaseLogger);
    // dal.addCustomer("Ahmed Siddiqui");

    std::cout << "Hello World" << std::endl;
    return 0;
}
