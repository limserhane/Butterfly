#include <Butterfly/Common.hpp>


namespace Butterfly
{

namespace Level
{
	
std::string GetName(Level::Value pLevel)
{
	if(0 <= pLevel && pLevel < Level::n)
		return Names[pLevel];
	return "";
}

} // namespace Level

namespace Exceptions
{

std::string ExceptionFormat(Utils::Source pSource, std::string pDetails)
{
	char buffer[256];
	snprintf(
		buffer, 256,
		"[%s] %s",
		pSource.Function.c_str(),
		pDetails.c_str()
	);
	return buffer;
}

Exception::Exception(Utils::Source pSource, std::string pDetails):
	Exception{pSource, "Exception", pDetails}
{}

Exception::Exception(Utils::Source pSource, std::string pName, std::string pDetails)
{
	mDescription = Format(pSource, pName, pDetails);
}

const char* Exception::Format(Utils::Source pSource, std::string pName, std::string pDetails)
{
	char buffer[256];
	snprintf(
		buffer, 256,
		"[%s] %s",
		pSource.Function.c_str(),
		pDetails.c_str()
	);
	return buffer;
}

const char* Exception::what() const throw()
{
	return mDescription;
}


} // namespace Exceptions

} // namespace Butterfly