#include <Butterfly/Details/LogPackage.hpp>



namespace Butterfly
{

LogPackage::LogPackage(std::string pName, Level::Value pLevel, std::string pMessage):
	Name{pName},
	Level{pLevel},
	Message{pMessage}
{}

} // namespace Butterfly