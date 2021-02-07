#include <Butterfly/Common.hpp>


namespace Butterfly {

namespace Level {
	
std::string GetName(Level::Value pLevel) {
	if(0 <= pLevel && pLevel < Level::n)
		return Names[pLevel];
	return "";
} // GetName()

} // namespace Level

Source::Source(std::string pFile, int pLine, std::string pFunction, std::string pPrettyFunction):
	File{pFile},
	Line{pLine},
	Function{pFunction},
	PrettyFunction{pPrettyFunction}
{} // Source::Source()

Source::Source(const Source& other):
	Source{other.File, other.Line, other.Function, other.PrettyFunction}
{} // Source::Source()

Exception::Exception(Source pSource, std::string pDetails) {
	mDescription = Format(pSource, pDetails);
} // Exception::Exception()

const char* Exception::what() const throw() {
	return mDescription.c_str();
} // Exception::what()

std::string Exception::Format(Source pSource, std::string pDetails) {
	constexpr size_t bufferSize = 128;
	char buffer[bufferSize];
	snprintf(
		buffer, bufferSize,
		"(%s) : %s",
		pSource.PrettyFunction.c_str(),
		pDetails.c_str()
	);
	return buffer;
} // Exception::Format()

void ThrowException(Source pSource, std::string pDetails) {
	throw Exception(pSource, pDetails);
} // ThrowException()

} // namespace Butterfly