# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PixelEditor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PixelEditor_autogen.dir/ParseCache.txt"
  "PixelEditor_autogen"
  )
endif()
