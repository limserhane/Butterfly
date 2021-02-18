#pragma once

#include <butterfly/logger.hpp>
#include <butterfly/common.hpp>

#include <string>
#include <vector>

namespace butterfly
{

/**
 * @brief A logger used as a parent for p_other loggers.
 */
class net : public logger
{
public :
	net();
	net(std::initializer_list<std::shared_ptr<logger>> p_loggers);

	virtual ~net();

	/**
	 * @brief Logs a record using each one of its children.
	 * @param p_level The level to be logged;
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void log(level::value p_level, std::string_view p_tag, std::string_view p_message) override
	{
		for (auto& logger : m_loggers)
		{
			logger->log(p_level, p_tag, p_message);
		}
	}

	/**
	 * @brief Adds a logger as its child.
	 * @param p_logger If not nullptr, the child to be added;
	 */
	void add(std::shared_ptr<logger> p_logger);

	/**
	 * @brief Adds a list of loggers as its children.
	 * @param p_loggers The list of loggers to be added;
	 */
	void add(std::initializer_list<std::shared_ptr<logger>> p_loggers);


	/**
	 * @brief Removes a logger from its children.
	 * @param p_logger The logger to be removed;
	 */
	void remove(std::shared_ptr<logger> p_logger);

private :
	std::vector<std::shared_ptr<logger>> m_loggers;

}; 

} 