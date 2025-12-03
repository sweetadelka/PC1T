# CMakeList.txt: Projekt CMake pro 2d, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (2d "2d.cpp" "2d.h" "Body2d.cpp" "Body2d.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2d PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
