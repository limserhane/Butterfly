#pragma once

#include <string>

namespace Butterfly
{

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

} // namespace Butterfly