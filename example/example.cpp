
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {
    
    Print();

    auto a = CreateNet("a");
    auto b = CreateNet("b");
    auto c = CreateWing<Wing>("c", Level::error);
    auto d = CreateWing<Wing>();
    auto e = CreateWing<Wing>("e", Level::fatal);
    auto f = CreateWing<Wing>(Level::trace);
    auto g = CreateWing<Wing>("g");

    b->Add(c);
    b->Add(d);

    a->Add(b);
    a->Add(e);
    a->Add(f);
    a->Add(g);

    a->Trace("Hello world !");

    return 0;
}