cmake_minimum_required(VERSION 3.5.1)

#project(libSV)

add_subdirectory(src)
#set_target_properties(libSV PROPERTIES COMPILE_FLAGS "-fpic -Wall -Wextra -Werror -x c++ -O2") 
set_target_properties(SV PROPERTIES COMPILE_FLAGS "-fpic -x c++ -O2") 


# if DEBUG
# -g3 -O0 -ggdb
# else
# -O2
# endif

# -w -Wunused-parameter -static")
