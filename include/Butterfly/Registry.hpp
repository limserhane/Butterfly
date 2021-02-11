#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>

#include <iostream>

namespace Butterfly
{

class Registry
{
public :
	Registry(const Registry& other) = delete;
	Registry& operator=(const Registry& other) = delete;

	~Registry();

	std::shared_ptr<Logger> GetDefaultLogger() const;
	void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

	static Registry& Instance();

private :
	Registry();

	std::shared_ptr<Logger> mDefaultLogger;
};

}