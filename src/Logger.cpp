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
void Logger::Info(std::string pTag, std::string pMessage)
{
	Log(Level::info, pTag, pMessage);
}
void Logger::Warning(std::string pTag, std::string pMessage)
{
	Log(Level::warning, pTag, pMessage);
}
void Logger::Error(std::string pTag, std::string pMessage)
{
	Log(Level::error, pTag, pMessage);
}
void Logger::Fatal(std::string pTag, std::string pMessage)
{
	Log(Level::fatal, pTag, pMessage);
}
void Logger::Debug(std::string pTag, std::string pMessage)
{
	Log(Level::debug, pTag, pMessage);
}

} 