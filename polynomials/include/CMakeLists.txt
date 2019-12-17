set(target ${MP2_CUSTOM})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp*")

add_custom_target(${target} SOURCES ${hdrs})