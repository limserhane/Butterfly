
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/Wing.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Net.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

    std::shared_ptr<Net> a = CreateNet("engine");
    std::shared_ptr<Logger> b = CreateWing("", "engine");
    std::shared_ptr<Logger> c = CreateWing<FileWing>("", "engine", "bin/log-engine.txt");
    
    a->Add(b);
    a->Add(c);

    Trace("Butterflies all havin' fun !");

    SetDefaultLogger(a);

    Error("Engine stopped working due to work overlaod");

    return 0;
}