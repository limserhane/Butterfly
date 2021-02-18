#include <butterfly/net.hpp>

#include <algorithm>

namespace butterfly
{

net::net():
	logger()
{}

net::net(std::initializer_list<std::shared_ptr<logger>> p_loggers):
	net()
{
	add(p_loggers);
}

net::~net()
{}

void net::add(std::shared_ptr<logger> p_logger)
{
	if(!p_logger)
	{
		print_exception(BFLY_SOURCE, "inval argument, p_logger is nullptr");
		return ;
	}

	m_loggers.push_back(p_logger);
}

void net::add(std::initializer_list<std::shared_ptr<logger>> p_loggers)
{
	for (auto& logger : p_loggers)
	{
		add(logger);
	}
}

void net::remove(std::shared_ptr<logger> p_logger)
{
	if(!p_logger)
	{
		print_exception(BFLY_SOURCE, "invalid argument, p_logger is nullptr");
		return ;
	}

	std::vector<std::shared_ptr<logger>>::iterator logger_iterator = std::find(m_loggers.begin(), m_loggers.end(), p_logger);

	if(logger_iterator == m_loggers.end())
	{
		print_exception(BFLY_SOURCE, "invalid argument, p_logger not found");
		return ;
	}

	m_loggers.erase(logger_iterator);
}

} 