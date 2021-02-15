#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

ConsoleWing::ConsoleWing(Level::Value pLevel, PackageFormatter pFormatter):
	Wing(pLevel, pFormatter)
{}

ConsoleWing::ConsoleWing(PackageFormatter pFormatter):
	ConsoleWing(Level::minimal, pFormatter)
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string pRecord)
{
	std::cout << pRecord;
}

}