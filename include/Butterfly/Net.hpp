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
	Net(std::string pName);

	virtual ~Net();

	virtual void Log(Level::Value pLevel, std::string pMessage) override;

	void Add(std::shared_ptr<Logger> pLogger);
	void Remove(size_t pPosition);

private :
	std::vector<std::shared_ptr<Logger>> mLoggers;

}; 

} 