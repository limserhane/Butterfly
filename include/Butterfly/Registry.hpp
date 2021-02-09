#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>

#include <iostream>
#include <unordered_map>

namespace Butterfly
{

class Registry
{
public :
	Registry(const Registry& other) = delete;
	Registry& operator=(const Registry& other) = delete;

	~Registry();

	void Print() const;

	std::shared_ptr<Logger> GetDefaultLogger() const;
	void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

	static Registry& Instance();

private :
	Registry();

	std::shared_ptr<Logger> mDefaultLogger;
	// std::unordered_map<std::string, std::shared_ptr<Logger>> mLoggers;
};

}