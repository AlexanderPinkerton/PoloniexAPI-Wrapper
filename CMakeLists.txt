cmake_minimum_required(VERSION 3.6)
project(PoloniexAPI)
set(CMAKE_CXX_STANDARD 11)


#----------------Prepare and Load Dependencies--------------------------------
Set(CPPREST_CMAKE_DIR "/usr/local/lib/cpprest")
Set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CPPREST_CMAKE_DIR})

find_package(cpprest)

# Tell Cmake what user files to include in the build process.
file(GLOB SOURCE_FILES "*.cpp" "*.hpp")



#------------------Create executable target with source files----------------
add_executable(PoloniexAPI ${SOURCE_FILES})

#------------------Attach Dependencies to Executable-----------------------

# Specify which libraries to add to the executable.
target_link_libraries(PoloniexAPI cpprest)

