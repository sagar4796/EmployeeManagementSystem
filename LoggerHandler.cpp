#include <memory>    // unique_ptr

#include "LoggerHandler.hpp"
#include "SimpleLogger.hpp"
#include "PersistenceHandler.hpp"


std::unique_ptr<LoggerHandler> LoggerHandler::create(std::ostream& loggingStream)
{
    auto& persistantData = PersistenceHandler::instance();
    auto   requestedLogger = persistantData["Component.Logger"];

    if (requestedLogger == "Simple Logger") return std::make_unique<SimpleLogger>(loggingStream);

    throw BadLoggerRequest("Unknown Logger object requested: \"" + requestedLogger + "\"\n  detected in function " + __func__);
}

