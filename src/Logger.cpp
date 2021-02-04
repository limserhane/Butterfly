#include <Butterfly/Logger.hpp>


namespace Butterfly {

Logger::Logger(std::string pName):
	mName{pName}
{}

Logger::~Logger()
{}

void Logger::Trace(std::string pMessage)
{
	Log(Level::trace, pMessage);
}

} // namespace Butterfly