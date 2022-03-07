add_library(libDZSSDL2 DZSWindow.cpp DZSWindow.h DZSRenderer.cpp DZSRenderer.h DZSSDL2.cpp DZSSDL2.h)
target_link_libraries(libDZSSDL2 ${SDL2_LINK_LIBRARIES})
