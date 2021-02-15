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
	Net(std::initializer_list<std::shared_ptr<Logger>> pLoggers);

	virtual ~Net();

	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource = Source()) override;

	void Add(std::shared_ptr<Logger> pLogger);
	void Add(std::initializer_list<std::shared_ptr<Logger>> pLoggers);
	void Remove(std::shared_ptr<Logger> pLogger);

private :
	std::vector<std::shared_ptr<Logger>> mLoggers;

}; 

} 