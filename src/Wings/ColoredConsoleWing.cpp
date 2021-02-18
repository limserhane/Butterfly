#include <Butterfly/Wings/ColoredConsoleWing.hpp>

#include <Butterfly/Details/PackageFormatters/ColoredPackageFormatter.hpp>

namespace Butterfly
{

ColoredConsoleWing::ColoredConsoleWing(Level::Value pLevel, Pattern pPattern):
	ConsoleWing(pLevel, std::make_unique<ColoredPackageFormatter>(CompilePackageFormatter(pPattern)))
{}

ColoredConsoleWing::ColoredConsoleWing(Pattern pPattern):
	ColoredConsoleWing(Level::minimal, pPattern)
{}

ColoredConsoleWing::~ColoredConsoleWing()
{}

}