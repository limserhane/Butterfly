#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(Source pSource, time_t pTime, Level::Value pLevel, std::string pTag, std::string pMessage):
	Location(pSource),
	Time(pTime),
	Level(pLevel),
	Tag(pTag),
	Message(pMessage)
{}

} 