#include <Butterfly/Details/Exceptions.hpp>

namespace Butterfly
{

namespace Exceptions
{

std::string ExceptionFormat(std::string pName, Utils::Source pSource, std::string pDetails)
{
	char buffer[256];
	snprintf(
		buffer, 256,
		"(%s:line%d:%s)Butterfly::%s::%s",
		pSource.File.c_str(),
		pSource.Line,
		pSource.Function.c_str(),
		pName.c_str(),
		pDetails.c_str()
	);
	return buffer;
}

} // namespace Exceptions

} // namespace Butterfly