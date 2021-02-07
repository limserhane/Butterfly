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

Exception::Exception(Source pSource, std::string pDetails)
{
	mDescription = Format(pSource, pDetails);
}

const char* Exception::what() const throw()
{
	return mDescription.c_str();
}

std::string Exception::Format(Source pSource, std::string pDetails)
{
	constexpr size_t bufferSize = 128;
	char buffer[bufferSize];
	snprintf(
		buffer, bufferSize,
		"(%s) : %s",
		pSource.PrettyFunction.c_str(),
		pDetails.c_str()
	);
	return buffer;
}

void ThrowException(Source pSource, std::string pDetails)
{
	throw Exception(pSource, pDetails);
}

} // namespace Butterfly