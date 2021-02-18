#include <butterfly/butterfly.hpp>

#include <iostream>

namespace butterfly
{

std::shared_ptr<net> create_net(std::string p_identifier, std::initializer_list<std::shared_ptr<logger>> p_loggers)
{
	std::shared_ptr<net> new_net = std::make_shared<net>(p_loggers);

	registry::instance().add(p_identifier, new_net);

	return new_net;
}

std::shared_ptr<safe_logger> create_safe_logger(std::string p_identifier, std::shared_ptr<logger> p_logger)
{
	if(!p_logger)
	{
		throw_exception(BFLY_SOURCE, "invalid argument, p_logger is nullptr");
		return nullptr;
	}

	std::shared_ptr<safe_logger> new_safe_logger = std::make_shared<safe_logger>(p_logger);

	registry::instance().add(p_identifier, new_safe_logger);

	return new_safe_logger;
}

}