cmake_minimum_required(VERSION 3.18.4)
project(TestWxWidgets)

# You may have to modifie the flags depending on which OS you are using.
# Use "wx-config --cppflags" to know what you have to put here.
set(CFLAGS
    -I/usr/local/include/wx-3.1
    -I/usr/local/lib/wx/include/gtk3-unicode-3.1/
    -D_FILE_OFFSET_BITS=64
    -DWXUSINGDLL
    -D__WXGTK__
)

# You may have to modifie the path to your libraries.
# Use "wx-config --libs" to know what you have to put here.
set(LIBS
    -L/usr/local/lib
    -pthread
    -lwx_gtk3u_xrc-3.1
    -lwx_gtk3u_html-3.1
    -lwx_gtk3u_qa-3.1
    -lwx_gtk3u_core-3.1
    -lwx_baseu_xml-3.1
    -lwx_baseu_net-3.1
    -lwx_baseu-3.1
)

set(SOURCES_PATHS 
    src/
)

foreach(PATH IN LISTS SOURCES_PATHS)
    AUX_SOURCE_DIRECTORY(${PATH} SOURCES)
endforeach()

add_compile_options(${CFLAGS})
add_executable(TestWxWidgets ${SOURCES})
target_link_libraries(TestWxWidgets ${LIBS})