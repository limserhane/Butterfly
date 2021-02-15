#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>

#include <iostream>
#include <unordered_map>

namespace Butterfly
{

/**
 * @brief A class used to store loggers as a global registry in the program.
 */
class Registry
{
public :
	Registry(const Registry& other) = delete;
	Registry& operator=(const Registry& other) = delete;

	~Registry();

	/**
	 * @brief Getter for the actual default logger.
	 * @return The actual default logger
	 */
	std::shared_ptr<Logger> GetDefaultLogger() const;

	/**
	 * @brief Sets the default logger.
	 * @param pLogger The logger to be set as the default logger;
	 */
	void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

	/**
	 * @brief If the identifier is not empty and the logger is not nullptr, adds a pair of identifier and logger to the global registry.
	 * @param pIdentifier The identifier of the logger to add;
	 * @param pLogger The logger to add;
	 */
	void Add(std::string pIdentifier, std::shared_ptr<Logger> pLogger);

	/**
	 * @brief Removes the logger from the global registry if it exists.
	 * @param pIdentifier The identifier of the logger to be removed;
	 */
	void Remove(std::string pIdentifier);

	/**
	 * @brief Gets the logger from the global registry.
	 * @param pIdentifier The identifier of the requested logger;
	 * @return The logger identified by \p pIdentifier
	 */
	std::shared_ptr<Logger> Get(std::string pIdentifier) const;

	/**
	 * @brief Getter for the global registry.
	 * @return The global registry
	 */
	static Registry& Instance();

private :
	Registry();

	std::shared_ptr<Logger> mDefaultLogger;
	std::unordered_map<std::string, std::shared_ptr<Logger>> mLoggers;
};

}