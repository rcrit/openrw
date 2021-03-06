set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)

add_executable(rwviewer
	main.cpp
	ViewerWindow.cpp

	models/ObjectListModel.cpp
	models/DFFFramesTreeModel.cpp


	views/ObjectViewer.cpp
	views/ModelViewer.cpp

	ViewerWidget.cpp
	ItemListModel.cpp
	ItemListWidget.cpp
	IMGArchiveModel.cpp
	widgets/ModelFramesWidget.cpp
	AnimationListModel.cpp
	AnimationListWidget.cpp)

include_directories("${CMAKE_SOURCE_DIR}/rwengine/include" ${BULLET_INCLUDE_DIR})

target_link_libraries(rwviewer
	rwengine
	sfml-graphics
	sfml-system
	${OPENGL_LIBRARIES}
	${BULLET_LIBRARIES})
qt5_use_modules(rwviewer Widgets OpenGL)

install(TARGETS rwviewer RUNTIME DESTINATION bin)
