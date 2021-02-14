#pragma once

#include <Butterfly/Logger.hpp>
#include <Butterfly/Common.hpp>

#include <string>
#include <vector>

namespace Butterfly
{

class Net : public Logger
{
public :
	Net();

	virtual ~Net();

	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource = Source()) override;

	void Add(std::shared_ptr<Logger> pLogger);
	void Remove(std::shared_ptr<Logger> pLogger);

private :
	std::vector<std::shared_ptr<Logger>> mLoggers;

}; 

} 