cmake_minimum_required(VERSION 3.27)
project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 20)

file(GLOB PROJECT_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC "/opt/homebrew/include" "${VULKAN_SDK}/include")
target_link_directories(${PROJECT_NAME} PUBLIC "/opt/homebrew/lib" "${VULKAN_SDK}/lib")

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)