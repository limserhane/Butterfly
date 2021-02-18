#pragma once

#include <butterfly/common.hpp>
#include <butterfly/net.hpp>
#include <butterfly/wing.hpp>
#include <butterfly/registry.hpp>
#include <butterfly/safe_logger.hpp>

namespace butterfly
{

/**
 * @brief Creates a net and add it to the global registry.
 * @param p_identifier If not empty, the net will be added to the global registry with this identifier;
 * @param p_loggers The loggers will be added to the net during its initialization;
 * @return The created net
 */
std::shared_ptr<net> create_net(std::string p_identifier, std::initializer_list<std::shared_ptr<logger>> p_loggers = {});

/**
 * @brief Creates a wing and add it to the global registry;
 * @param W Optionnal, the type of the wing to create, must be derived from wing;
 * @param p_identifier If not empty, the net will be added to the global registry with this identifier;
 * @param p_wing_args The arguments that will be used to initialize the wing
 * @return The created wing
 */
template<typename W = wing, typename... WingArgs>
std::shared_ptr<wing> create_wing(std::string p_identifier, WingArgs... p_wing_args)
{
static_assert(std::is_base_of<wing, W>::value, "W must be derived from wing");
	
	std::shared_ptr<wing> new_wing = std::make_shared<W>(p_wing_args...);

	registry::instance().add(p_identifier, new_wing);

	return new_wing;
}

/**
 * @brief Creates a safe_logger and add it to the global registry.
 * @param p_identifier If not empty, the safe_logger will be added to the global registry with this identifier;
 * @param p_logger The logger to be used to initialize the safe_logger;
 * @return The created safe_logger
 */
std::shared_ptr<safe_logger> create_safe_logger(std::string p_identifier, std::shared_ptr<logger> p_logger);

/**
 * @brief Gets the actual default logger.
 * @return The default logger
 */
inline std::shared_ptr<logger> get_default_logger()
{
	return registry::instance().get_default_logger();
}

/**
 * @brief Sets the default logger.
 * @param p_logger The logger to be set as the default logger;
 */
inline void set_default_logger(std::shared_ptr<logger> p_logger)
{
	return registry::instance().set_default_logger(p_logger);
}

/**
 * @brief Gets the logger from the global registry.
 * @param p_identifier The identifier of the requested logger;
 * @return The logger identified by \p p_identifier
 */
inline std::shared_ptr<logger> get(std::string p_identifier)
{
	return registry::instance().get(p_identifier);
}

/**
 * @brief Logs a trace using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void trace(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->trace(p_tag, p_message);
}

/**
 * @brief Logs an information using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void info(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->info(p_tag, p_message);
}

/**
 * @brief Logs a warning using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void warning(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->warning(p_tag, p_message);
}

/**
 * @brief Logs an error using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void error(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->error(p_tag, p_message);
}

/**
 * @brief Logs a fatal error using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void fatal(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->fatal(p_tag, p_message);
}

/**
 * @brief Logs a debug information using the actual default logger
 * @param p_tag The tag of the record to log;
 * @param p_message The message of the record to log;
 * @param p_source The source of the call to the log function;
 */
inline void debug(std::string_view p_tag, std::string_view p_message)
{
	registry::instance().get_default_logger()->debug(p_tag, p_message);
}
	
} 