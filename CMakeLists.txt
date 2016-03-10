project(OSGDemo)
cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_COLOR_MAKEFILE ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

mark_as_advanced(CMAKE_VERBOSE_MAKEFILE)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules ${CMAKE_MODULE_PATH})
set(CMAKE_DEBUG_POSTFIX "d")

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_CAPITALIZED)
add_definitions(-DUNICODE)

macro( config_project PROJNAME LIBNAME )
include_directories( ${${LIBNAME}_INCLUDE_DIR} )
target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

# OpenMP
find_package(OpenMP)
if(OPENMP_FOUND)
	option(WITH_OPENMP "Whether to use parallel processing capabilities of OPENMP. ON/OFF" ON)
endif(OPENMP_FOUND)

if(OPENMP_FOUND AND WITH_OPENMP)
	message(STATUS "With OpenMP ")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMAX_OPENMP_NUM_THREADS=${PROCESSOR_COUNT} -DOPENMP_NUM_THREADS=${PROCESSOR_COUNT} ${OpenMP_CXX_FLAGS} -DOPENMP")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMAX_OPENMP_NUM_THREADS=${PROCESSOR_COUNT} -DOPENMP_NUM_THREADS=${PROCESSOR_COUNT} ${OpenMP_CXX_FLAGS} ${OpenMP_C_FLAGS} -DOPENMP")
else(OPENMP_FOUND AND WITH_OPENMP)
	message(STATUS "Without OpenMP")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMAX_OPENMP_NUM_THREADS=1 -DOPENMP_NUM_THREADS=1")
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMAX_OPENMP_NUM_THREADS=1 -DOPENMP_NUM_THREADS=1")
endif(OPENMP_FOUND AND WITH_OPENMP)

# GLUT
find_package( glut )

# OSG
find_package( OpenSceneGraph REQUIRED osgDB osgUtil osgViewer osgGA osgText osgFX osgQt osgAnimation osgParticle)
include_directories(${OSG_INCLUDE_DIR})

set( OSG_LIBRARIES
    debug ${OPENTHREADS_LIBRARY_DEBUG}
    debug ${OSGANIMATION_LIBRARY_DEBUG}
    debug ${OSGDB_LIBRARY_DEBUG}
    debug ${OSGFX_LIBRARY_DEBUG}
    debug ${OSGGA_LIBRARY_DEBUG}
    debug ${OSGPARTICLE_LIBRARY_DEBUG}
    debug ${OSGQT_LIBRARY_DEBUG}
    debug ${OSGTEXT_LIBRARY_DEBUG}
    debug ${OSGUTIL_LIBRARY_DEBUG}
    debug ${OSGVIEWER_LIBRARY_DEBUG}
    debug ${OSG_LIBRARY_DEBUG}
    optimized ${OPENTHREADS_LIBRARY}
    optimized ${OSGANIMATION_LIBRARY}
    optimized ${OSGDB_LIBRARY}
    optimized ${OSGFX_LIBRARY}
    optimized ${OSGGA_LIBRARY}
    optimized ${OSGPARTICLE_LIBRARY}
    optimized ${OSGQT_LIBRARY}
    optimized ${OSGTEXT_LIBRARY}
    optimized ${OSGUTIL_LIBRARY}
    optimized ${OSGVIEWER_LIBRARY}
    optimized ${OSG_LIBRARY}
    ${OSG_LIBRARIES}
)

include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_BINARY_DIR})

file(GLOB_RECURSE HDRS_FILES *.h *.hpp)
file(GLOB_RECURSE SRCS_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SRCS_FILES} ${HDRS_FILES})
target_link_libraries(${PROJECT_NAME} ${OSG_LIBRARIES} )
