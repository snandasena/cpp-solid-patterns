//
// Created by sajith on 4/19/21.
//

#include <iostream>
#include <stdexcept>

// Interfaces
class Printer
{

public:
    virtual ~Printer() = default;
    virtual void print() = 0;
};

class Scanner
{
public:
    virtual ~Scanner() = default;
    virtual void scan() = 0;
};

class Fax
{
public:
    virtual ~Fax() = default;
    virtual void fax() = 0;
};


class AdvancedPrinter : public Printer, public Scanner, public Fax
{
public:
    void print()
    {
        std::cout << "Printing...\n";
    }

    void scan()
    {
        std::cout << "Scanning...\n";
    }

    void fax()
    {
        std::cout << "Faxing...\n";
    }
};

class SimplePrinter : public Printer
{
public:
    void print()
    {
        std::cout << "Printing...\n";
    }
};

// clients
void printUsers(Printer &printer)
{
    printer.print();
}

void scanUsers(Scanner &scanner)
{
    scanner.scan();
}

void faxUsers(Fax &fax)
{
    fax.fax();
}

int main()
{
    AdvancedPrinter advancedPrinter;
    SimplePrinter simplePrinter;

    printUsers(advancedPrinter);
    scanUsers(advancedPrinter);
    faxUsers(advancedPrinter);
//    scanUsers(simplePrinter); // won't compile

    return 0;
}