cmake_minimum_required(VERSION 3.14)
project(Push_Swap)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)
include_directories(inc/*)
include_directories(libft/libft.h)

set(SOURCE_FILES src/commands.c
        src/helper.c
		src/push_swap.c
		src/clear.c
		src/sort.c
		src/quicksort.c
		src/print_command.c
		src/small_sort_reverse_b.c
		src/merge_operation.c
		src/stack.c)

add_executable(Push_Swap ${SOURCE_FILES})
target_link_libraries(Push_Swap ${LIBFT})

project(Checker)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)
include_directories(inc)
include_directories(libft/)

set(SOURCE_FILES src/checker.c
        src/commands.c
		src/clear.c
		src/combine_commands.c
        src/helper.c
		src/stack.c)

add_executable(Checker ${SOURCE_FILES})
target_link_libraries(Checker ${LIBFT})
