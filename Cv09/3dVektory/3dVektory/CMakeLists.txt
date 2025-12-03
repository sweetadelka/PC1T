# CMakeList.txt: Projekt CMake pro 3dVektory, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (3dVektory "3dVektory.cpp" "3dVektory.h" "VectorMath.h" "VectorMath.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3dVektory PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
