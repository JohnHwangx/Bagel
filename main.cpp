#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main()
{
    std::cout<< "Hello Bagel\n";

    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("HAZEL");
    logger->set_level(spdlog::level::trace);
    logger->trace("Hello spdlog");

}