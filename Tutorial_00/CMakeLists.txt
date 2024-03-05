cmake_minimum_required (VERSION 3.10)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name and version
project (Tutorial_00 VERSION 1.0)

set (VULKAN_SDK "/Users/marknuar/VulkanSDK/1.3.275.0/macOS")
set (ENV{VK_ICD_FILENAMES} "${VULKAN_SDK}/share/vulkan/icd-d/MoltenVK_icd.json")
set (ENV{VK_LAYER_PATH} "${VULKAN_SDK}/share/vulkan/explicit_layer.d")

# add the executable
add_executable (Tutorial_00 main.cpp) 
target_include_directories(Tutorial_00 PUBLIC "/opt/homebrew/include" "${VULKAN_SDK}/include")
target_link_directories (Tutorial_00 PUBLIC "/opt/homebrew/lib" "${VULKAN_SDK}/lib")

find_library(GLFW_LIB libglfw.3.4.dylib "/opt/homebrew/lib")
target_link_libraries (Tutorial_00 PUBLIC "${GLFW_LIB}" "${VULKAN_SDK}/lib/libvulkan.1.dylib" "${VULKAN_SDK}/lib/libvulkan.1.3.275.dylib")

cmake_minimum_required (VERSION 3.10)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name and version
project (Tutorial_01 VERSION 1.0)

set (VULKAN_SDK "/Users/marknuar/VulkanSDK/1.3.275.0/macOS")
set (ENV{VK_ICD_FILENAMES} "${VULKAN_SDK}/share/vulkan/icd-d/MoltenVK_icd.json")
set (ENV{VK_LAYER_PATH} "${VULKAN_SDK}/share/vulkan/explicit_layer.d")

# add the executable
add_executable (Tutorial_01 main.cpp) 
target_include_directories(Tutorial_01 PUBLIC "/opt/homebrew/include" "${VULKAN_SDK}/include")
target_link_directories (Tutorial_01 PUBLIC "/opt/homebrew/lib" "${VULKAN_SDK}/lib")

find_library(GLFW_LIB libglfw.3.4.dylib "/opt/homebrew/lib")
target_link_libraries (Tutorial_01 PUBLIC "${GLFW_LIB}" "${VULKAN_SDK}/lib/libvulkan.1.dylib" "${VULKAN_SDK}/lib/libvulkan.1.3.275.dylib")