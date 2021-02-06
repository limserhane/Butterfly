#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <sstream>

namespace Butterfly
{

class Logger;
using LoggerPointer = std::shared_ptr<Logger>;
class Net;
using NetPointer = std::shared_ptr<Net>;

namespace Level
{

enum Value
{
	trace	= 0,
	info	= 1,
	warning	= 2,
	error	= 3,
	fatal	= 4,
	debug	= 5,
	n
}; // enum Value

constexpr const char* Names[] = { "trace", "info", "warning", "error", "fatal", "debug" };

std::string GetName(Level::Value pLevel);

} // namespace Level

namespace Utils
{

struct Source
{
	Source(std::string pFile, int pLine, std::string pFunction):
		File{pFile},
		Line{pLine},
		Function{pFunction}
	{}

	Source(const Source& other):
		File{other.File},
		Line{other.Line},
		Function{other.Function}
	{}

	std::string File;
	int Line;
	std::string Function;
};

} // namespace Utils

} // namespace Butterfly