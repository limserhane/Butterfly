#include <Butterfly/Registry.hpp>

#include <Butterfly/Wings/Wing.hpp>

#include <utility>

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
		PrintException(BFLY_SOURCE, "pLogger is nullptr");
		return ;
	}

	mDefaultLogger = pLogger;
}

void Registry::Add(std::string pIdentifier, std::shared_ptr<Logger> pLogger)
{
	if(pIdentifier.empty())
	{
		PrintException(BFLY_SOURCE, "invalid argument, pIdentifier is empty string");
		return ;
	}

	if(!pLogger)
	{
		PrintException(BFLY_SOURCE, "invalid argument, pLogger is nullptr");
		return ;
	}

	auto vInsertResult = mLoggers.insert(std::make_pair(pIdentifier, pLogger));

	if(!vInsertResult.second)
	{
		PrintException(BFLY_SOURCE, "failed");
		return ;
	}
}

void Registry::Remove(std::string pIdentifier)
{
	if(pIdentifier.empty())
	{
		PrintException(BFLY_SOURCE, "invalid argument, pIdentifier is empty string");
		return ;
	}

	auto vEraseResult = mLoggers.erase(pIdentifier);

	if(!vEraseResult)
	{
		PrintException(BFLY_SOURCE, "failed, pIdentifier not found");
		return ;
	}
}

std::shared_ptr<Logger> Registry::Get(std::string pIdentifier) const
{
	return mLoggers.at(pIdentifier); // throws out_of_range
}

Registry& Registry::Instance()
{
	static Registry registry;
	return registry;
}

}