/*******************************************************
** class name: GisDev
**
** description: 主窗口
**
** last change: 2020-01-04
*******************************************************/

#pragma once

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QtWidgets/QMainWindow>

#include <map>

#include "dialog/postgresqlconnect.h"
#include "dialog/postgresqltableselect.h"
#include "dialog/viewlog.h"
#include "geo/map/geomap.h"
#include "widget/globalsearchwidget.h"
#include "widget/layerstreewidget.h"
#include "widget/openglwidget.h"
#include "widget/statusbar.h"
#include "widget/toolboxtreewidget.h"

class ICGis : public QMainWindow {
    Q_OBJECT

public:
    ICGis(QWidget* parent = Q_NULLPTR);
    ~ICGis();

public:
    /* Initialize */
    void createWidgets();
    void createActions();
    void createMenus();
    void createToolBar();
    void createStatusBar();
    void setupLayout();

    void test_geo_math();

public slots:
    void onUpdateOpenGLWidget();
    void onOpenGeoJsonUsingGDAL();
    void onOpenGeoJsonMine();
    void onOpenGeoShapefile();
    void onOpenTiff();
    void onConnectPostgresql();
    void onShowLogDialog();  // 显示日志窗口

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    /* Dialog */
    PostgresqlConnect* postgresqlConnectDialog;
    PostgresqlTableSelect* postgresqlTableSelectDialog;
    ViewLog* viewLogDialog;

    /* Widget */
    LayersTreeWidget* layersTreeWidget;
    ToolBoxTreeWidget* toolboxTreeWidget;
    OpenGLWidget* openGLWidget;
    GlobalSearchWidget* searchWidget;  // 搜索框

    /* Status bar */
    StatusBar* statusbar;

    /* MenuBar */
    QMenu* fileMenu;      // 一级
    QMenu* openFileMenu;  // 二级
    QMenu* newFileMenu;   // 二级
    QMenu* connectMenu;   // 二级
    QMenu* windowMenu;    // 一级

    /* Right clicked menu */
    QMenu* popMenu;

    /* Action */
    QAction* openGeoJsonUsingGDALAction;
    QAction* openGeoJsonMineAction;
    QAction* openShapfileAction;
    QAction* openTiffAction;
    QAction* connectPostgresqlAction;
    QAction* newMapAction;
    QAction* newLayerAction;
    QAction* showLogDialog;

private:
    GeoMap* map;
};
