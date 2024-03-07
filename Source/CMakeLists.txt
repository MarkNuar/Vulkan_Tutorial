cmake_minimum_required(VERSION 3.27)
project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 20)

# set (VULKAN_SDK "/Users/marknuar/VulkanSDK/1.3.275.0/macOS")
# set (ENV{VK_ICD_FILENAMES} "${VULKAN_SDK}/share/vulkan/icd-d/MoltenVK_icd.json")
# set (ENV{VK_LAYER_PATH} "${VULKAN_SDK}/share/vulkan/explicit_layer.d")

file(GLOB PROJECT_SRC
     "*.h"
     "*.cpp"
)
add_executable(${PROJECT_NAME} ${PROJECT_SRC})

include_directories(${PROJECT_NAME} PUBLIC "/opt/homebrew/include" "${VULKAN_SDK}/include")
link_directories(${PROJECT_NAME} PUBLIC "/opt/homebrew/lib" "${VULKAN_SDK}/lib")

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)