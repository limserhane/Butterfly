#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing(Level::Value pLevel, std::unique_ptr<PackageFormatter> pFormatter):
	Logger(),
	mLevel(pLevel),
	mFormatter(std::move(pFormatter))
{}

Wing::Wing(std::unique_ptr<PackageFormatter> pFormatter):
	Wing(Level::minimal, std::move(pFormatter))
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pTag, std::string pMessage)
{
	if(pLevel < mLevel)
	{
		return ;
	}

	Write(mFormatter->Format(Package(time(nullptr), pLevel, pTag, pMessage)));
}

} 