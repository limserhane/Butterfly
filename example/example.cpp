
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

    auto a = CreateNet("a");
    auto b = CreateNet("b");
    auto c = CreateWing<ConsoleWing>("c", Level::trace);
    auto d = CreateWing<ConsoleWing>("d", Level::warning);
    auto e = CreateWing<ConsoleWing>("e");

    b->Add(c);
    b->Add(d);

    a->Add(b);
    a->Add(e);

    a->Add(nullptr);

    a->Trace("Hello world !");
    a->Error("Error Butterfly stopped working.");

    return 0;
}