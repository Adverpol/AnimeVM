
# ui files (created by designer-qt4)
#set( UI_FILES
#  ../designer/MainWindow.ui
#  ../designer/SeriesSettings.ui
#  )

# Need to add headerse to sources to check them for moc-ing
set( HEADERS
  ../inc/MainWindow.hpp
  ../inc/Application.hpp
  ../inc/Series.hpp
  ../inc/DirectoryList.hpp
  ../inc/SeriesSettings.hpp
  )

# Note: as qt4_wrap_ui does not call uic (called when making the
# executable/library we cannot put it in the inc directory.

# Create ui_*.h files (uses uic)
# qt5_wrap_ui( UI_HEADERS ${UI_FILES} )

# Run moc
#qt5_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )

set( SOURCES
  Database.cpp
  MainWindow.cpp
  Data.cpp
  SeriesSettings.cpp
  Series.cpp
  DirectoryList.cpp
  Application.cpp
  
  CheckBoxDelegate.cpp
  )

# Compile and link everything
add_executable( ViewManager
  main
#  ${UI_HEADERS} 
  ${SOURCES} 
  ${HEADERS}
  "../qml.qrc"
)

target_link_libraries( ViewManager
  ${LIBS}
  Qt5::Widgets
  Qt5::Sql
  Qt5::Qml
) 
