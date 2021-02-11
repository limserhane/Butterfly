#include <Butterfly/Common.hpp>


namespace Butterfly
{

namespace Level
{

static const char* Names[] = { "trace", "info", "warning", "error", "fatal", "debug" };

std::string GetName(Level::Value pLevel)
{
	if(0 <= pLevel && pLevel < Level::n)
		return Names[pLevel];
	return "";
}

}

Source::Source(std::string pFile, int pLine, std::string pFunction, std::string pPrettyFunction):
	File{pFile},
	Line{pLine},
	Function{pFunction},
	PrettyFunction{pPrettyFunction}
{} 

Source::Source(const Source& other):
	Source{other.File, other.Line, other.Function, other.PrettyFunction}
{} 

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
	constexpr size_t bufferSize = 256;
	char buffer[bufferSize];
	snprintf(
		buffer, bufferSize,
		"Butterfly : (%s) : %s",
		pSource.PrettyFunction.c_str(),
		pDetails.c_str()
	);
	return buffer;
} 

void ThrowException(Source pSource, std::string pDetails)
{
	throw Exception(pSource, pDetails);
}

void PrintException(Source pSource, std::string pDetails)
{
	std::cerr << Exception(pSource, pDetails).what() << std::endl;
} 

} 