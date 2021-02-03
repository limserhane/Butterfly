
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Loggers/Wing.hpp>

#include <iostream>

int main() {
    
    Butterfly::Print();

    Butterfly::Loggers::Wing l{"console"};

    l.Trace("Hello dragonfly :)");

    return 0;
}