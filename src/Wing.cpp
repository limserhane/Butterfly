#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

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

void Wing::Log(Level::Value pLevel, std::string pMessage) const
{
	if(pLevel < mLevel)
	{
		return ;
	}

	Write(mFormatter.Format(Package(mName, pLevel, pMessage)));
}

} 