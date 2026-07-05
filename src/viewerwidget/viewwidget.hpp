#ifndef VIEWERWIDGET_HPP
#define VIEWERWIDGET_HPP
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSplitter>
#include <QImage>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <poppler/qt6/poppler-qt6.h>
#include <iostream>

using namespace std;
using namespace Poppler;

class ViewerWidget : public QMainWindow {
    Q_OBJECT
    public:
        ViewerWidget (QMainWindow* parent, QString filepath);
    
    private:

        void create_menubar ();

        void init_list_widget ();

        void init_view_widget ();

        void setup_centralwidget_layout ();

        void set_graphic_view ();
        

        
        QMenuBar* menu_bar;

        QMenu* file_menu;

        QMenu* help_menu;
        
        QAction* file_menu_new;

        QAction* file_menu_save_as;

        QSplitter* main_splitter;

        QWidget* view_widget;

        QListWidget* list_widget;

        QPixmap pixmap;

        QImage image;

        QLabel* label;

        QListWidgetItem* item;

        QGraphicsScene* scene;

        QGraphicsView* view;

        std::unique_ptr<Document> doc;
        
        std::unique_ptr<Poppler::Page> page_of_pdf;
        
        QString filepath;
};

#endif