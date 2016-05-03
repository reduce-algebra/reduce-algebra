include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_BINARY_DIR}")
include(GenerateExportHeader)
add_library(edit_static STATIC editline.c fn_complete.c history.c)
add_library(edit SHARED editline.c fn_complete.c history.c libedit.def)
set_target_properties(edit PROPERTIES PREFIX "")
GENERATE_EXPORT_HEADER(edit
  BASE_NAME edit
  EXPORT_MACRO_NAME edit_EXPORT
  EXPORT_FILE_NAME edit_Export.h
  STATIC_DEFINE edit_BUILT_AS_STATIC
)
add_executable(edit_test libedit_test.c)
target_link_libraries(edit_test edit)
add_executable(edit_test_dll libedit_test_dll.c)
install (TARGETS edit edit_test edit_test_dll
  DESTINATION "${CMAKE_SOURCE_DIR}/bin${LIB_SUFFIX}")
install (TARGETS edit_static
  DESTINATION "${CMAKE_SOURCE_DIR}/lib${LIB_SUFFIX}")
install (FILES editline/readline.h
  DESTINATION "${CMAKE_SOURCE_DIR}/include/editline")
