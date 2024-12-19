cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

project(studentai VERSION 2.0)

add_executable(studentai "src/studentai.cpp")
target_include_directories(
    studentai 
    PRIVATE
        headers/
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "bin")

include(GNUInstallDirs)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_NAME "studentai")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_VERSION "3.0")
set(CPACK_DEBIAN_DEBUGINFO_PACKAGE ON)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lukasjanusauskaslj@gmail.com")
include(CPack)