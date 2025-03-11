set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(fun_header ${header_path}/fun.h)
set(fun_src fun.cpp)
set(common_header ${header_path}/common.h)
set(common_src common.cpp)


add_library(${PROJECT_NAME} SHARED
  ${common_header} ${fun_header}
  ${common_src} ${fun_src})
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)

  
add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")
