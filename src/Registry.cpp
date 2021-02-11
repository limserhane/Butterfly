#include <Butterfly/Registry.hpp>

#include <Butterfly/Wings/Wing.hpp>

namespace Butterfly
{

Registry::Registry():
	mDefaultLogger(std::make_shared<Wing>("default"))
{}

Registry::~Registry()
{}

std::shared_ptr<Logger> Registry::GetDefaultLogger() const
{
	return mDefaultLogger;
}

void Registry::SetDefaultLogger(std::shared_ptr<Logger> pLogger)
{
	if(!pLogger)
	{
		ThrowException(BFLY_SOURCE, "Invalid argument, pLogger is nullptr");
		return ;
	}

	mDefaultLogger = pLogger;
}

Registry& Registry::Instance()
{
	static Registry registry;
	return registry;
}

}