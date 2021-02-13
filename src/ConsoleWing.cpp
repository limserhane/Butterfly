#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

ConsoleWing::ConsoleWing(Level::Value pLevel):
	Wing(pLevel)
{}

ConsoleWing::ConsoleWing():
	Wing(Level::minimal)
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string record)
{
	std::cout << record;
}

}