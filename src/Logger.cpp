#include <Butterfly/Logger.hpp>


namespace Butterfly
{

Logger::Logger()
{}

Logger::~Logger()
{}

void Logger::Trace(std::string pTag, std::string pMessage)
{
	Log(Level::trace, pTag, pMessage);
}
void Logger::Error(std::string pTag, std::string pMessage)
{
	Log(Level::error, pTag, pMessage);
}

} 