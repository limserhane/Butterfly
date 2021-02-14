#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>

#include <mutex>

namespace Butterfly
{

class SafeLogger : public Logger
{
public :
	SafeLogger(std::shared_ptr<Logger> pWing);

	~SafeLogger();

	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource = Source()) override;

private :
	std::shared_ptr<Logger> mLogger;
	std::mutex mMutex;

};

} 