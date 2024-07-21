#include <iostream>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main()
{
    std::cout<< "Hello Bagel\n";

    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("HAZEL");
    logger->set_level(spdlog::level::trace);
    logger->trace("Hello spdlog");

    glm::vec3 m_Position = { 0.0f,0.0f,0.0f };

    std::cout << m_Position.x << "," << m_Position.y << "," << m_Position.z << std::endl;
}