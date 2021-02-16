#include <Butterfly/Details/PackageFormatters/ColoredPackageFormatter.hpp>


namespace Butterfly
{

ColoredPackageFormatter::ColoredPackageFormatter(const char* pPattern):
	PackageFormatter(pPattern)
{}

ColoredPackageFormatter::ColoredPackageFormatter(const ColoredPackageFormatter& pOther):
	PackageFormatter(pOther)
{}

ColoredPackageFormatter::~ColoredPackageFormatter()
{}

std::string ColoredPackageFormatter::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 256;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,

		(StartColorFlag(pPackage.Level) + mFormat + EndColorFlag()).c_str(), 

		FormatTime(pPackage.Time).c_str(),
		FormatLevel(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

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