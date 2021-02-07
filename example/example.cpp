
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {
    
    Print();

    auto a = CreateNet("a");
    auto b = CreateNet("b");
    auto c = CreateWing<ConsoleWing>("c");
    auto d = CreateWing<ConsoleWing>("d", Level::trace);
    auto e = CreateWing<ConsoleWing>("e", Level::fatal);
    auto f = CreateWing<ConsoleWing>("f");

    b->Add(c);
    b->Add(d);
    b->Add(e);

    a->Add(b);
    a->Add(f);

    a->Add(nullptr);

    a->Trace("Hello world !");
    a->Error("Error Butterfly stopped working.");

    return 0;
}