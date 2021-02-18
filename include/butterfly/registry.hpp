#pragma once

#include <butterfly/common.hpp>
#include <butterfly/logger.hpp>

#include <iostream>
#include <unordered_map>

namespace butterfly
{

/**
 * @brief A class used to store loggers as a global registry in the program.
 */
class registry
{
public :
	registry(const registry& p_other) = delete;
	registry& operator=(const registry& p_other) = delete;

	~registry();

	/**
	 * @brief Getter for the actual default logger.
	 * @return The actual default logger
	 */
	inline std::shared_ptr<logger> get_default_logger() const
	{
		return m_default_logger;
	}

	/**
	 * @brief Sets the default logger.
	 * @param p_logger The logger to be set as the default logger;
	 */
	void set_default_logger(std::shared_ptr<logger> p_logger);

	/**
	 * @brief If the identifier is not empty and the logger is not nullptr, adds a pair of identifier and logger to the global registry.
	 * @param p_identifier The identifier of the logger to add;
	 * @param p_logger The logger to add;
	 */
	void add(std::string p_identifier, std::shared_ptr<logger> p_logger);

	/**
	 * @brief Removes the logger from the global registry if it exists.
	 * @param p_identifier The identifier of the logger to be removed;
	 */
	void remove(std::string p_identifier);

	/**
	 * @brief Gets the logger from the global registry.
	 * @param p_identifier The identifier of the requested logger;
	 * @return The logger identified by \p p_identifier
	 */
	std::shared_ptr<logger> get(std::string p_identifier) const;

	/**
	 * @brief Getter for the global registry.
	 * @return The global registry
	 */
	inline static registry& instance()
	{
		static registry s_registry;
		return s_registry;
	}

private :
	registry();

	std::shared_ptr<logger> m_default_logger;
	std::unordered_map<std::string, std::shared_ptr<logger>> m_loggers;
};

}