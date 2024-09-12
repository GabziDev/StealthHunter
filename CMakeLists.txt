cmake_minimum_required(VERSION 3.10)
project(StealthHunter C)

set(CMAKE_C_STANDARD 11)

find_package(CURL REQUIRED)

add_executable(StealthHunter main.c
        utils.h
        check_xss.c
        check_xss.h
        check_sql_injection.c
        check_sql_injection.h
        check_nosql_injection.c
        check_nosql_injection.h
        utils.c
        dirbusting.c
        dirbusting.h
)

install(TARGETS StealthHunter DESTINATION /usr/local/bin)

include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(StealthHunter ${CURL_LIBRARIES})