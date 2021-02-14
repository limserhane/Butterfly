#include <Butterfly/Details/PackageFormatter.hpp>

#include <Butterfly/Common.hpp>

namespace Butterfly
{

std::string PackageFormatter::Format(Package pPackage) const
{
	char vBuffer[512];

	snprintf(
		vBuffer, 512,
		"[%s] [%s] %s\n",
		ToString(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return vBuffer;
}


} 