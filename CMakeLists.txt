cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "Statslabs.Stats")
set(PROJECT_FULL_NAME "Statslabs.Stats -- The C++ Basic Statistics Library")
set(PROJECT_VERSION "0.1.0")

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(STATUS "CMAKE_BUILD_TYPE is unset, defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Download and unpack rmath at configure time
configure_file(${CMAKE_SOURCE_DIR}/cmake/Rmath-CMakeLists.txt.in ${CMAKE_BINARY_DIR}/rmath-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/rmath-download )
if(result)
    message(FATAL_ERROR "CMake step for rmath failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/rmath-download )
if(result)
    message(FATAL_ERROR "Build step for rmath failed: ${result}")
endif()

# Add rmath directly to our build. This defines Rmath::Rmath
add_subdirectory(${CMAKE_BINARY_DIR}/rmath-src
        ${CMAKE_BINARY_DIR}/rmath-build
        EXCLUDE_FROM_ALL)

find_package(Matrix 0.3.0 REQUIRED)

# Doxygen Build
option(BUILD_DOC "Build Documentation" ON)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR ${CMAKE_SOURCE_DIR}/build/doc)
    if(NOT EXISTS ${BUILD_DOC_DIR})
        file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
    endif()

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

##################################################
# Create target and set properties
##################################################

add_executable(main
        src/main.cc)

# Set target properties
target_include_directories(main
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(main
        PUBLIC
        Statslabs::Matrix
        PRIVATE
        rmath
        )


add_library(stats
        src/library.cc)

# Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(Statslabs::stats ALIAS stats)

# Set target properties
target_include_directories(stats
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(stats PUBLIC ${MKL_LINKER_LIBS})
target_link_libraries(stats
        PUBLIC
        Statslabs::Matrix
        rmath
        )

##################################################
# Installation instructions
##################################################

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Stats)

install(TARGETS stats
        EXPORT stats-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

#This is required so that the exported target has the name Stats and not stats
set_target_properties(stats PROPERTIES EXPORT_NAME Stats)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export the targets to a script
install(EXPORT stats-targets
        FILE
        StatsTargets.cmake
        NAMESPACE
        Statslabs::
        DESTINATION
        ${INSTALL_CONFIGDIR}
        )

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/StatsConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/StatsConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/StatsConfig.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
        )

#Install the config, configversion and custom find modules
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/StatsConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/StatsConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
        )

export(EXPORT stats-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/StatsTargets.cmake NAMESPACE Statslabs::)

# Register package in user's package registry
export(PACKAGE Stats)

add_subdirectory(examples)
