#pragma once

#include <Butterfly/Common.hpp>

#include <exception>
#include <stdexcept>

namespace Butterfly
{

namespace Exceptions
{

std::string ExceptionFormat(std::string pName, Utils::Source pSource, std::string pDetails);

} // namespace Exceptions

} // namespace Butterfly