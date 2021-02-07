#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

ConsoleWing::ConsoleWing(Level::Value pLevel):
	Wing{pLevel}
{}

ConsoleWing::ConsoleWing(std::string pName, Level::Value pLevel):
	Wing{pName, pLevel}
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string record) const
{
	std::cout << record;
}

} // namespace Butterfly