#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly {

Wing::Wing(Level::Value pLevel):
	Logger{},
	mLevel{pLevel},
	mFormatter{}
{}

Wing::Wing(std::string pName, Level::Value pLevel):
	Logger{pName},
	mLevel{pLevel},
	mFormatter{}
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pMessage)
{
	if(pLevel < mLevel)
	{
		return ;
	}

	Write(mFormatter.Format(LogPackage(mName, pLevel, pMessage)));
}

void Wing::Write(std::string record)
{
	std::cout << record;
}

} // namespace Butterfly