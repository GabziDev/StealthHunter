cmake_minimum_required(VERSION 3.10)
project(StealthHunter C)

set(CMAKE_C_STANDARD 11)

find_package(CURL REQUIRED)

add_executable(StealthHunter src/main.c
        src/include/utils.h
        src/include/colors.h
        src/check_xss.c
        src/include/check_xss.h
        src/check_sql_injection.c
        src/include/check_sql_injection.h
        src/check_nosql_injection.c
        src/include/check_nosql_injection.h
        src/utils.c
        src/dirbusting.c
        src/include/dirbusting.h
        src/include/version.h
        src/colors.c
)

install(TARGETS StealthHunter DESTINATION /usr/local/bin)

include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(StealthHunter ${CURL_LIBRARIES})