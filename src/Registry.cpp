#include <butterfly/registry.hpp>

#include <butterfly/wings/console_wing.hpp>

#include <utility>

namespace butterfly
{

registry::registry():
	m_default_logger(std::make_shared<console_wing>(pattern::minimal))
{
	get_default_logger()->trace("butterfly", "Butterflies all havin' fun !");
}

registry::~registry()
{}

void registry::set_default_logger(std::shared_ptr<logger> p_logger)
{
	if(!p_logger)
	{
		print_exception(BFLY_SOURCE, "p_logger is nullptr");
		return ;
	}

	m_default_logger = p_logger;
}

void registry::add(std::string p_identifier, std::shared_ptr<logger> p_logger)
{
	if(p_identifier.empty())
	{
		return ;
	}

	if(!p_logger)
	{
		print_exception(BFLY_SOURCE, "invalid argument, p_logger is nullptr");
		return ;
	}

	auto result = m_loggers.insert(std::make_pair(p_identifier, p_logger));

	if(!result.second)
	{
		print_exception(BFLY_SOURCE, "failed");
		return ;
	}
}

void registry::remove(std::string p_identifier)
{
	if(p_identifier.empty())
	{
		return ;
	}

	auto result = m_loggers.erase(p_identifier);

	if(!result)
	{
		print_exception(BFLY_SOURCE, "invalid argument, p_identifier not found");
		return ;
	}
}

std::shared_ptr<logger> registry::get(std::string p_identifier) const
{
	return m_loggers.at(p_identifier); // throws out_of_range
}

}