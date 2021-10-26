set(HEADER_FILES ../include/c3xx/Exchanger.hpp
        ../include/c3xx/Semaphore.h
        ../include/c3xx/CountDownLatch.h)

set(SOURCE_FILES Semaphore.cpp
        CountDownLatch.cpp)

add_library(c3xx STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(c3xx PUBLIC ../include)