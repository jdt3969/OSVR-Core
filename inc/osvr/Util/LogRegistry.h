/** @file
    @brief Regstry to maintain instantiated loggers and global settings.

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

#ifndef INCLUDED_LogRegistry_h_GUID_09DDD840_389E_430C_8CBD_9AC4EE3F93FE
#define INCLUDED_LogRegistry_h_GUID_09DDD840_389E_430C_8CBD_9AC4EE3F93FE

// Internal Includes
#include <osvr/Util/LogLevel.h>

// Library/third-party includes
// - none

// Standard includes
#include <memory>           // for std::shared_ptr
#include <string>           // for std::string
#include <vector>           // for std::vector

// Forward declarations
namespace spdlog {

    namespace sinks {
        class sink;
    } // namespace sinks

    using sink_ptr = std::shared_ptr<spdlog::sinks::sink>;

} // namespace spdlog

namespace osvr {
namespace util {
namespace log {

    class Logger;
    using LoggerPtr = std::shared_ptr<Logger>;

    class LogRegistry {
      public:
        LogRegistry(LogRegistry const &) = delete;            // copy construct
        LogRegistry(LogRegistry &&) = delete;                 // move construct
        LogRegistry &operator=(LogRegistry const &) = delete; // copy assign
        LogRegistry &operator=(LogRegistry &&) = delete;      // move assign

        static LogRegistry &instance();

        LoggerPtr getOrCreateLogger(const std::string &logger_name);

        void setPattern(const std::string &pattern);
        void setLevel(LogLevel severity);

      protected:
        LogRegistry();
        ~LogRegistry();

        std::vector<spdlog::sink_ptr> sinks_;
    };

} // namespace log
} // namespace util
} // namespace osvr

#endif // INCLUDED_LogRegistry_h_GUID_09DDD840_389E_430C_8CBD_9AC4EE3F93FE

