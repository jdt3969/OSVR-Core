/** @file
    @brief Header

    @date 2016

    @author
    Sensics, Inc.
    <http://sensics.com>

*/

// Copyright 2016 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_Logger_h_GUID_D8ADC0E7_A358_4FF2_960F_10F098A22F4E
#define INCLUDED_Logger_h_GUID_D8ADC0E7_A358_4FF2_960F_10F098A22F4E

// Internal Includes
#include <osvr/Util/LogLevel.h>
#include <osvr/Util/LineLogger.h>
#include <osvr/Util/Export.h>

// Library/third-party includes
// - none

// Standard includes
#include <string>           // for std::string
#include <memory>           // for std::shared_ptr
#include <vector>           // for std::vector

// Forward declarations

namespace spdlog {
class logger;
} // end namespace spdlog

namespace osvr {
namespace util {
namespace log {

/**
 * @brief A wrapper around the spdlog::logger class.
 */
class OSVR_UTIL_EXPORT Logger {
public:
    Logger(const std::string& logger_name);
    Logger(spdlog::logger* logger);
    Logger(std::shared_ptr<spdlog::logger> logger);

    virtual ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    LogLevel getLogLevel() const;
    void setLogLevel(LogLevel);

    // logger.info(cppformat_string, arg1, arg2, arg3, ...) call style
    template <typename... Args> detail::LineLogger trace(const char* fmt,    Args&&... args);
    template <typename... Args> detail::LineLogger debug(const char* fmt,    Args&&... args);
    template <typename... Args> detail::LineLogger info(const char* fmt,     Args&&... args);
    template <typename... Args> detail::LineLogger notice(const char* fmt,   Args&&... args);
    template <typename... Args> detail::LineLogger warn(const char* fmt,     Args&&... args);
    template <typename... Args> detail::LineLogger error(const char* fmt,    Args&&... args);
    template <typename... Args> detail::LineLogger critical(const char* fmt, Args&&... args);
    template <typename... Args> detail::LineLogger alert(const char* fmt,    Args&&... args);
    template <typename... Args> detail::LineLogger emerg(const char* fmt,    Args&&... args);

    detail::LineLogger trace(const char* fmt);
    detail::LineLogger debug(const char* fmt);
    detail::LineLogger info(const char* fmt);
    detail::LineLogger notice(const char* fmt);
    detail::LineLogger warn(const char* fmt);
    detail::LineLogger error(const char* fmt);
    detail::LineLogger critical(const char* fmt);
    detail::LineLogger alert(const char* fmt);
    detail::LineLogger emerg(const char* fmt);

    // logger.info(msg) << ".." call style
    template <typename T> detail::LineLogger trace(T&& msg);
    template <typename T> detail::LineLogger debug(T&& msg);
    template <typename T> detail::LineLogger info(T&& msg);
    template <typename T> detail::LineLogger notice(T&& msg);
    template <typename T> detail::LineLogger warn(T&& msg);
    template <typename T> detail::LineLogger error(T&& msg);
    template <typename T> detail::LineLogger critical(T&& msg);
    template <typename T> detail::LineLogger alert(T&& msg);
    template <typename T> detail::LineLogger emerg(T&& msg);


    // logger.info() << ".." call  style
    detail::LineLogger trace();
    detail::LineLogger debug();
    detail::LineLogger info();
    detail::LineLogger notice();
    detail::LineLogger warn();
    detail::LineLogger error();
    detail::LineLogger critical();
    detail::LineLogger alert();
    detail::LineLogger emerg();

    // Logger.log(log_level, cppformat_string, arg1, arg2, arg3, ...) call style
    template <typename... Args>
    detail::LineLogger log(LogLevel level, const char* fmt, Args&&... args);

    // logger.log(log_level, msg) << ".." call style
    detail::LineLogger log(LogLevel level, const char* msg);

    // logger.log(log_level, msg) << ".." call style
    template <typename T>
    detail::LineLogger log(LogLevel level, T&& msg);

    // logger.log(log_level) << ".." call  style
    detail::LineLogger log(LogLevel level);

    // Create log message with the given level, no matter what is the actual logger's level
    template <typename... Args>
    detail::LineLogger force_log(LogLevel level, const char* fmt, Args&&... args);

    virtual void flush();

protected:
    std::shared_ptr<spdlog::logger> logger_;
};

typedef std::shared_ptr<Logger> LoggerPtr;

} // end namespace log
} // end namespace util
} // end namespace osvr

#endif // INCLUDED_Logger_h_GUID_D8ADC0E7_A358_4FF2_960F_10F098A22F4E

