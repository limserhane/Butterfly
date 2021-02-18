#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{


ConsoleWing::ConsoleWing(Level::Value pLevel, std::unique_ptr<PackageFormatter> pFormatter):
	Wing(pLevel, std::move(pFormatter))
{}

ConsoleWing::ConsoleWing(Level::Value pLevel, Pattern pPattern):
	ConsoleWing(pLevel, CompilePackageFormatter(pPattern))
{}

ConsoleWing::ConsoleWing(Pattern pPattern):
	ConsoleWing(Level::minimal, pPattern)
{}

ConsoleWing::~ConsoleWing()
{}

}