#include <Butterfly/Loggers/Logger.hpp>


namespace Butterfly {

namespace Loggers
{

Logger::Logger(std::string pName):
	mName{pName}
{}

Logger::~Logger()
{}

void Logger::Trace(std::string pMessage)
{
	Log(Level::trace, pMessage);
}

} // namespace Loggers

} // namespace Butterfly