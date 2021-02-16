#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(time_t pTime, Level::Value pLevel, std::string pTag, std::string pMessage):
	Time(pTime),
	Level(pLevel),
	Tag(pTag),
	Message(pMessage)
{}

} 