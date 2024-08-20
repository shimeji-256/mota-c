cmake_minimum_required(VERSION 3.5.0)
project(summerProj VERSION 0.1.0 LANGUAGES C CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SOURCE_DIR}/bin)
set(EGE_DIR ${PROJECT_SOURCE_DIR}/ege)

include_directories(${EGE_DIR}/include ./include)
aux_source_directory(./src SRC_LIST)
link_directories(${EGE_DIR}/lib/)

add_executable(summerProj  ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} graphics gdi32 gdiplus)
target_sources(summerProj PRIVATE ${PROJECT_SOURCE_DIR}/resources/resources.rc)

include(CTest)
enable_testing()


include(CPack)
