#pragma once 
#ifndef _VIEWERWINDOW_HPP_
#define _VIEWERWINDOW_HPP_
#include <QMainWindow>
#include <engine/GameData.hpp>
#include <engine/GameWorld.hpp>
#include <core/Logger.hpp>
#include <QStackedWidget>
#include <QVBoxLayout>

class ObjectViewer;
class ModelViewer;
class ViewerWidget;
class GameRenderer;
class QGLContext;

class ViewerWindow : public QMainWindow
{
	Q_OBJECT

	Logger engineLog;
	WorkContext work;

	GameData* gameData;
	GameWorld* gameWorld;
	GameRenderer* renderer;

	/** Contains the OGL context */
	ViewerWidget* viewerWidget;

	ObjectViewer* objectViewer;
	ModelViewer* modelViewer;

	QStackedWidget* viewSwitcher;

	QGLContext* context;
public:

	ViewerWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);

	/**
	 * @brief openGame Loads a game's dat file.
	 * @param datFile
	 */
	void openGame(const QString& datFile);

	virtual void showEvent(QShowEvent*);
	
	virtual void closeEvent(QCloseEvent*);

public slots:

	void openAnimations();

	void loadGame();

	void loadGame( const QString& path );

signals:

	void loadedData(GameWorld* world);

private slots:

	void openRecent();

	void switchWidget();

	void showObjectModel(uint16_t object);

private:
	
	QList<QAction*> recentGames;
	QAction* recentSep;
	void updateRecentGames();
};

#endif 
