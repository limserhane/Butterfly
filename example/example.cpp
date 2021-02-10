
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

    std::shared_ptr<Net> a = CreateNet("a");
    std::shared_ptr<Net> b = CreateNet("b");
    std::shared_ptr<Logger> c = CreateWing<ConsoleWing>("c", Level::trace);
    std::shared_ptr<Logger> d = CreateWing<ConsoleWing>("d", Level::warning);
    std::shared_ptr<Logger> e = CreateWing<ConsoleWing>("e");

    std::shared_ptr<Logger> d = CreateWing<FileWing>("d", Level::warning);
    std::shared_ptr<Logger> e = CreateWing<FileWing>("log.txt");
    std::shared_ptr<Logger> e = CreateWing<FileWing>(Level::trace);
    

    b->Add(c);
    b->Add(d);

    a->Add(b);
    a->Add(e);

    try
    {
        Trace("Hello world !");
    }
    catch(const Butterfly::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    SetDefaultLogger(a);
    
    Trace("Hello world !");
    Error("Error Butterfly stopped working.");

    return 0;
}