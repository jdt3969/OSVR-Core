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

#ifndef INCLUDED_LineLogger_h_GUID_743865A8_E989_4A87_82D9_9BBF3E4C199D
#define INCLUDED_LineLogger_h_GUID_743865A8_E989_4A87_82D9_9BBF3E4C199D

// Internal Includes
#include <osvr/Util/LogLevel.h>

// Library/third-party includes
// - none

// Standard includes
#include <memory>

// Forward declaration
namespace spdlog {
namespace details {
class log_msg;
class line_logger;
} // end namespace details
} // end namespace spdlog

namespace osvr {
namespace util {
namespace log {

// Forward declaration
class Logger;

namespace detail {

/**
 * @brief A wrapper class for spdlog::details::line_logger.
 */
class LineLogger {
public:
    LineLogger(spdlog::details::line_logger&& line_logger);

    /**
     * @brief Move-only.
     */
    //@{
    LineLogger(const LineLogger& other) = delete;
    LineLogger& operator=(const LineLogger&) = delete;
    LineLogger& operator=(LineLogger&&) = delete;
    LineLogger(LineLogger&& other);
    //@}

    /**
     * @brief Log the message using the callback logger.
     */
    ~LineLogger();

    /**
     * @brief Support for format string with variadic args.
     */
    void write(const char* what);

    template <typename... Args>
    void write(const char* fmt, Args&&... args);

    /**
     * @brief Support for operator<<
     *
     * \name Stream operators
     */
    //@{
    LineLogger& operator<<(const char* what);
    LineLogger& operator<<(const std::string& what);
    LineLogger& operator<<(int what);
    LineLogger& operator<<(unsigned int what);
    LineLogger& operator<<(long what);
    LineLogger& operator<<(unsigned long what);
    LineLogger& operator<<(long long what);
    LineLogger& operator<<(unsigned long long what);
    LineLogger& operator<<(double what);
    LineLogger& operator<<(long double what);
    LineLogger& operator<<(float what);
    LineLogger& operator<<(char what);

    template<typename T>
    LineLogger& operator<<(T&& what);
    //@}

    void disable();
    bool is_enabled() const;

private:
    //Logger* logger_;
    //std::unique_ptr<spdlog::details::line_logger> lineLogger_;
    spdlog::details::line_logger&& lineLogger_;
};

} // end namespace detail
} // end namespace log
} // end namespace util
} // end namespace osvr

#endif // INCLUDED_LineLogger_h_GUID_743865A8_E989_4A87_82D9_9BBF3E4C199D

