#include <Butterfly/Logger.hpp>


namespace Butterfly
{

Logger::Logger()
{}

Logger::~Logger()
{}

void Logger::Trace(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::trace, pTag, pMessage, pSource);
}
void Logger::Error(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::error, pTag, pMessage, pSource);
}

} 