project(APRILTAG_LIBRARY)

include_directories(common)

file(GLOB lib_srcs *.c common/*.c)
file(GLOB lib_hdrs *.h common/*.h common/sys/*.h)

if(UNIX)
  find_package (Threads REQUIRED)
endif()

if(CMAKE_COMPILER_IS_GNUCXX AND UNIX)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif()

add_library(APRILTAG_LIBRARY SHARED ${lib_srcs} ${lib_hdrs})
SET_TARGET_PROPERTIES(APRILTAG_LIBRARY PROPERTIES OUTPUT_NAME apriltag CLEAN_DIRECT_OUTPUT 1)

if(WIN32 AND MSVC)
  target_link_libraries (APRILTAG_LIBRARY PTHREADS_LIBRARY)
else()
  target_link_libraries( APRILTAG_LIBRARY ${CMAKE_THREAD_LIBS_INIT} )
endif()

target_include_directories (APRILTAG_LIBRARY PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
