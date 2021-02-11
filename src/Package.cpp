#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(Level::Value pLevel, std::string pMessage):
	Level{pLevel},
	Message{pMessage}
{}

} 