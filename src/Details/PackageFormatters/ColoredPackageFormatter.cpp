#include <Butterfly/Details/PackageFormatters/ColoredPackageFormatter.hpp>


namespace Butterfly
{

ColoredPackageFormatter::ColoredPackageFormatter(std::unique_ptr<PackageFormatter> pFormatter):
	PackageFormatter(),
	mFormatter(std::move(pFormatter))
{}

std::string ColoredPackageFormatter::Format(Package pPackage) const
{
	std::string s = mFormatter->Format(pPackage);
	std::string lBuffer;
	lBuffer.reserve(12 + s.size());

	lBuffer += StartColorFlag(pPackage.Level);
	lBuffer += s;
	lBuffer += EndColorFlag();

	return lBuffer;
}

std::string ColoredPackageFormatter::StartColorFlag(Level::Value pLevel)
{
	std::string lLevelString = ToString(pLevel);

	switch(pLevel)
	{
	case Level::trace	:	return "\033[90m";
	case Level::info	:	return "\033[97m";
	case Level::warning	:	return "\033[33m";
	case Level::error	:	return "\033[31m";
	case Level::fatal	:	return "\033[91m";
	case Level::debug	:	return "\033[35m";
	default : return "";
	}
}

} 