#include <Butterfly/Wings/ColoredConsoleWing.hpp>

#include <Butterfly/Details/PackageFormatters/ColoredPackageFormatter.hpp>

namespace Butterfly
{

ColoredConsoleWing::ColoredConsoleWing(Level::Value pLevel, const char* pPattern):
	ConsoleWing(pLevel, std::make_unique<ColoredPackageFormatter>(pPattern))
{}

ColoredConsoleWing::ColoredConsoleWing(const char* pPattern):
	ColoredConsoleWing(Level::minimal, pPattern)
{}

ColoredConsoleWing::~ColoredConsoleWing()
{}

}