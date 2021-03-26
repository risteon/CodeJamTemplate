add_executable (TARGET_NAME "TARGET_FILE")
target_link_libraries(TARGET_NAME Threads::Threads)
set_property (TARGET TARGET_NAME PROPERTY CXX_STANDARD 17)

