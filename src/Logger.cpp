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
void Logger::Info(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::info, pTag, pMessage, pSource);
}
void Logger::Warning(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::warning, pTag, pMessage, pSource);
}
void Logger::Error(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::error, pTag, pMessage, pSource);
}
void Logger::Fatal(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::fatal, pTag, pMessage, pSource);
}
void Logger::Debug(std::string pTag, std::string pMessage, Source pSource)
{
	Log(Level::debug, pTag, pMessage, pSource);
}

} 