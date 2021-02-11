#include <Butterfly/Details/PackageFormatter.hpp>

namespace Butterfly
{

std::string PackageFormatter::Format(Package pPackage) const
{
	char buffer[512];

	snprintf(
		buffer, 512,
		"[%s][%s]-%s\n",
		pPackage.Name.c_str(),
		Level::GetName(pPackage.Level).c_str(),
		pPackage.Message.c_str()
	);

	return buffer;
}

} 