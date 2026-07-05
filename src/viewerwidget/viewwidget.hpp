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
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <poppler/cpp/poppler-image.h>
#include <iostream>

using namespace std;
using namespace poppler;

class ViewerWidget : public QMainWindow {
    Q_OBJECT
    public:
        ViewerWidget (QMainWindow* parent = nullptr , string filepath);
    
    private:

        void create_menubar ();

        void init_list_widget ();

        void init_view_widget ();

        void setup_centralwidget_layout ();

        void setup_pdf_reader ();
        
        QMenuBar* menu_bar;

        QMenu* file_menu;

        QMenu* help_menu;
        
        QAction* file_menu_new;

        QAction* file_menu_save_as;

        QSplitter* main_splitter;

        QWidget* view_widget;

        QListWidget* list_widget;

        QPixmap pixmap;

        QImage* image;

        QLabel* label;

        QListWidgetItem* item;

        document* doc;
        
        page* page_of_pdf;

        poppler::image img;

        page_renderer render;
        
        string filepath;
};

#endif