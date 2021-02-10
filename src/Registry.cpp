#include <Butterfly/Registry.hpp>


namespace Butterfly
{

Registry::Registry()
{}

Registry::~Registry()
{
	std::cout << "Registry Destructor\n";
}

void Registry::Print() const
{
	std::cout << "Registry !\n";
}

std::shared_ptr<Logger> Registry::GetDefaultLogger() const
{
	if(!mDefaultLogger)
	{
		ThrowException(BFLY_SOURCE, "Logic error, default logger must be set");
	}
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