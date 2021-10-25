set(HEADER_FILES ../include/c3xx/mylib.h)

set(SOURCE_FILES mylib.cpp)

add_library(c3xx STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(c3xx PUBLIC ../include)