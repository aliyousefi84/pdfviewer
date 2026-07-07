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
#include <stdlib.h>
#include <stdio.h>


using namespace std;
using namespace Poppler;

class ViewerWidget : public QMainWindow {
    Q_OBJECT
    public:
        ViewerWidget (QMainWindow* parent, QString filepath);
        ~ViewerWidget ();
    
    private:

        

        void init_list_widget ();

        void init_view_widget ();

        void setup_centralwidget_layout ();

        void set_graphic_view (int i);
        
        void handle_listwidget_item_signal ();

        
        

        QSplitter* main_splitter;


        QWidget* view_widget;


        QListWidget* list_widget;


        QPixmap pixmap;


        QImage image;


        QLabel* label;


        QListWidgetItem* item;


        QGraphicsScene* scene;


        QGraphicsView* view;


        // using unique_ptr so we don't need delete in the end of work , when scope is end , memory is clean !
        std::unique_ptr<Document> doc;
        

        std::unique_ptr<Poppler::Page> page_of_pdf;
        

        QString filepath;


        QStackedWidget* stack_widget;


        QList<QGraphicsView*> views;


        QList<QPixmap> pixmaps;
};

#endif