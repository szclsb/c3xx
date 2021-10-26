set(HEADER_FILES ../include/c3xx/Exchanger.hpp)

set(SOURCE_FILES placeholder.cpp)

add_library(c3xx STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(c3xx PUBLIC ../include)