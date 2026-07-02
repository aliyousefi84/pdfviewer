#include "viewwidget.hpp"

ViewerWidget::ViewerWidget (QMainWindow* parent) : QMainWindow(parent) {
    setWindowTitle ("pdf viewer");
    resize (1000,800);

    create_menubar ();

};



void ViewerWidget::create_menubar () {
    menu_bar = this->menuBar();

    file_menu = new QMenu (this);
    help_menu = new QMenu (this);

    file_menu_new = new QAction (this);
    file_menu_save_as = new QAction (this);

    file_menu->addAction (file_menu_new);
    file_menu->addSeparator ();
    file_menu->addAction (file_menu_save_as);
};



void ViewerWidget::init_list_widget () {
    list_widget = new QListWidget (this);

    list_widget->setViewMode (QListView::IconMode);


};




void ViewerWidget::init_view_widget () {
    view_widget = new QWidget ();

    

};