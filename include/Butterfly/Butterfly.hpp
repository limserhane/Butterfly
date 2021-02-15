#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Net.hpp>
#include <Butterfly/Wing.hpp>
#include <Butterfly/Registry.hpp>
#include <Butterfly/SafeLogger.hpp>

namespace Butterfly
{

/**
 * @brief Creates a Net and add it to the global registry.
 * @param pIdentifier If not empty, the Net will be added to the global registry with this identifier;
 * @param pLoggers The loggers will be added to the Net during its initialization;
 * @return The created Net
 */
std::shared_ptr<Net> CreateNet(std::string pIdentifier, std::initializer_list<std::shared_ptr<Logger>> pLoggers = {});

/**
 * @brief Creates a Wing and add it to the global registry;
 * @param W Optionnal, the type of the Wing to create, must be derived from Wing;
 * @param pIdentifier If not empty, the Net will be added to the global registry with this identifier;
 * @param pWingArgs The arguments that will be used to initialize the Wing
 * @return The created Wing
 */
template<typename W = Wing, typename... WingArgs>
std::shared_ptr<Wing> CreateWing(std::string pIdentifier, WingArgs... pWingArgs)
{
static_assert(std::is_base_of<Wing, W>::value, "W must be derived from Wing");
	
	std::shared_ptr<Wing> lWing = std::make_shared<W>(pWingArgs...);

	Registry::Instance().Add(pIdentifier, lWing);

	return lWing;
}

/**
 * @brief Creates a SafeWing and add it to the global registry.
 * @param pIdentifier If not empty, the SafeWing will be added to the global registry with this identifier;
 * @param pLogger The logger to be used to initialize the SafeWing;
 * @return The created SafeWing
 */
std::shared_ptr<SafeLogger> CreateSafeLogger(std::string pIdentifier, std::shared_ptr<Logger> pLogger);

/**
 * @brief Gets the actual default logger.
 * @return The default logger
 */
std::shared_ptr<Logger> GetDefaultLogger();

/**
 * @brief Sets the default logger.
 * @param pLogger The logger to be set as the default logger;
 */
void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

/**
 * @brief Gets the logger from the global registry.
 * @param pIdentifier The identifier of the requested logger;
 * @return The logger identified by \p pIdentifier
 */
std::shared_ptr<Logger> Get(std::string pIdentifier);

/**
 * @brief Logs a trace using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Trace(std::string pTag, std::string pMessage, Source pSource = Source());

/**
 * @brief Logs an information using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Info(std::string pTag, std::string pMessage, Source pSource = Source());

/**
 * @brief Logs a warning using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Warning(std::string pTag, std::string pMessage, Source pSource = Source());

/**
 * @brief Logs an error using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Error(std::string pTag, std::string pMessage, Source pSource = Source());

/**
 * @brief Logs a fatal error using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Fatal(std::string pTag, std::string pMessage, Source pSource = Source());

/**
 * @brief Logs a debug information using the actual default logger
 * @param pTag The tag of the record to log;
 * @param pMessage The message of the record to log;
 * @param pSource The source of the call to the log function;
 */
void Debug(std::string pTag, std::string pMessage, Source pSource = Source());
	
} 