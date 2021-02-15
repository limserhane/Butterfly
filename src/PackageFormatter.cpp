#include <Butterfly/Details/PackageFormatter.hpp>

#include <Butterfly/Common.hpp>

namespace Butterfly
{

PackageFormatter::PackageFormatter(const char* pPattern):
	mFormat(Compile(pPattern))
{}

PackageFormatter::PackageFormatter(const PackageFormatter& pOther):
	mFormat(pOther.mFormat)
{}

std::string PackageFormatter::Format(Package pPackage) const
{
	char vBuffer[512];

	snprintf(
		vBuffer, 512,
		"(%s) [%s] [%s] %s\n",
		mFormat.c_str(),
		ToString(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return vBuffer;
}

std::string PackageFormatter::Compile(std::string pPattern)
{
	return pPattern;
}

} 