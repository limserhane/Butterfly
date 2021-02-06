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
	Net(std::string pName);

	virtual ~Net();

	virtual void Log(Level::Value pLevel, std::string pMessage) const override;

	void Add(LoggerPointer pLogger);
	void Remove(size_t pPosition);

private :

	std::vector<LoggerPointer> mLoggers;

}; // class Net

} // namespace Butterfly