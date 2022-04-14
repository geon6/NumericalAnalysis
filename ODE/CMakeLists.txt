aux_source_directory(. ALL_SOURCE)

foreach(SOURCE ${ALL_SOURCE})
    set(TARGET_NAME ${SOURCE})    
    string(REPLACE "./" "" TARGET_NAME ${TARGET_NAME})
    string(REPLACE ".cpp" "" TARGET_NAME ${TARGET_NAME})
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach(SOURCE ${ALL_SOURCE})
