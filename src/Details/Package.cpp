#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(time_t pTime, Level::Value pLevel, std::string_view pTag, std::string_view pMessage):
	Time(pTime),
	Level(pLevel),
	Tag(pTag),
	Message(pMessage)
{}

} 