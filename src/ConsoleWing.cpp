#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

ConsoleWing::ConsoleWing():
	Wing()
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string record)
{
	std::cout << record;
}

}