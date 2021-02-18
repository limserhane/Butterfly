#pragma once

#include <butterfly/common.hpp>
#include <butterfly/wings/console_wing.hpp>


namespace butterfly
{

/**
 * @brief A concrete wing used to log colored records into the standard output, depending on the level. This wing gives poor performance due to the treatment the console needs to process for the colors.
 */
class colored_console_wing : public console_wing
{
public :
	colored_console_wing(level::value p_level = level::minimal, pattern p_pattern = pattern::simple);
	colored_console_wing(pattern p_pattern);
	
	virtual ~colored_console_wing();
};


}