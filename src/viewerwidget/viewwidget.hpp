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

class ViewerWidget : public QMainWindow {
    Q_OBJECT
    public:
        ViewerWidget (QMainWindow* parent = nullptr);
    
    private:

        void create_menubar ();

        void init_list_widget ();

        void init_view_widget ();

        void setup_centralwidget_layout ();

        QMenuBar* menu_bar;

        QMenu* file_menu;

        QMenu* help_menu;
        
        QAction* file_menu_new;

        QAction* file_menu_save_as;

        QSplitter* main_splitter;

        QWidget* view_widget;

        QListWidget* list_widget;
        
};

#endif