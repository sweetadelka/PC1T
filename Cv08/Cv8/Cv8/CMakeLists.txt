# CMakeList.txt: Projekt CMake pro Cv8, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (Cv8 "Cv8.cpp" "Cv8.h" "Svobodova.h" "Svobodova.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cv8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
