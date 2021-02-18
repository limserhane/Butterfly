#pragma once

#include <butterfly/common.hpp>
#include <butterfly/logger.hpp>

#include <mutex>

namespace butterfly
{

/**
 * @brief A decorator for a logger used to ensure the thread-safety log operations on the decorated logger.
 */
class safe_logger : public logger
{
public :
	safe_logger(std::shared_ptr<logger> pWing);

	~safe_logger();

	/**
	 * @brief Safely (from concurrent accesses) logs a record using the decorated logger
	 * @param p_level The level to be logged;
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 * @param p_source The source of the call to the log function;
	 */
	inline virtual void log(level::value p_level, std::string_view p_tag, std::string_view p_message) override
	{
		std::unique_lock<std::mutex> lock(m_mutex);

		m_logger->log(p_level, p_tag, p_message);	
	}

private :
	std::shared_ptr<logger> m_logger;
	std::mutex m_mutex;

};

} 