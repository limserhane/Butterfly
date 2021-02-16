#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{


ConsoleWing::ConsoleWing(Level::Value pLevel, std::unique_ptr<PackageFormatter> pFormatter):
	Wing(pLevel, std::move(pFormatter))
{}

ConsoleWing::ConsoleWing(Level::Value pLevel, const char* pPattern):
	ConsoleWing(pLevel, std::make_unique<PackageFormatter>(pPattern))
{}

ConsoleWing::ConsoleWing(const char* pPattern):
	ConsoleWing(Level::minimal, pPattern)
{}

ConsoleWing::~ConsoleWing()
{}

void ConsoleWing::Write(std::string pRecord)
{
	std::cout << pRecord;
}

}