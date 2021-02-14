#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

ConsoleWing::ConsoleWing(Level::Value pLevel, std::string pPattern):
	Wing(pLevel, pPattern)
{}

ConsoleWing::ConsoleWing(std::string pPattern):
	ConsoleWing(Level::minimal, pPattern)
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string record)
{
	std::cout << record;
}

}