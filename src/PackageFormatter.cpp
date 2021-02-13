#include <Butterfly/Details/PackageFormatter.hpp>

namespace Butterfly
{

std::string PackageFormatter::Format(Package pPackage) const
{
	char vBuffer[512];

	snprintf(
		vBuffer, 512,
		"[%s] [%s] %s\n",
		Level::GetName(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return vBuffer;
}


} 