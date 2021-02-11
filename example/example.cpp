
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/Wing.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

    std::shared_ptr<Net> a = CreateNet("a");
    std::shared_ptr<Net> b = CreateNet("b");
    std::shared_ptr<Logger> c = CreateWing("c");
    std::shared_ptr<Logger> d = CreateWing<Wing>("");
    std::shared_ptr<Logger> e = CreateWing<Wing>("e");
    
    b->Add(c);
    b->Add(d);

    a->Add(b);
    a->Add(e);

    Trace("Hello default logger !");

    SetDefaultLogger(a);

    a->Error("Network stopped working.");

    Error("Error Butterfly stopped working.");

    return 0;
}