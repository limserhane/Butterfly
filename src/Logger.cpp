#include <Butterfly/Logger.hpp>


namespace Butterfly
{

Logger::Logger(std::string pName):
	mName{pName}
{}

Logger::~Logger()
{}

void Logger::Trace(std::string pMessage) const
{
	Log(Level::trace, pMessage);
}
void Logger::Error(std::string pMessage) const
{
	Log(Level::error, pMessage);
}

} 