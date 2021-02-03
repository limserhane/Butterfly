#include <Butterfly/Common.hpp>


namespace Butterfly
{

namespace Level
{
	
std::string GetName(Level::Value pLevel)
{
	if(0 <= pLevel && pLevel < Level::n)
		return Names[pLevel];
	return "";
}

} // namespace Level

} // namespace Butterfly