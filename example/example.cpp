
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

    auto console = CreateWing<ConsoleWing>("", Level::warning);
    auto logfile = CreateWing<FileWing>("", "bin/log.txt");

    auto enginelogger = CreateNet("engine");
    enginelogger->Add(console);
    enginelogger->Add(logfile);

    auto networklogger = CreateNet("network");
    networklogger->Add(console);
    networklogger->Add(logfile);

    Trace("Butterfly", "Butterflies all havin' fun !");

    SetDefaultLogger(enginelogger);

    Get("engine")->Error("engine", "work overload due to low processing frequency");

    Get("network")->Trace("network", "[192.168.1.18:80] sent https requst");

    return 0;
}