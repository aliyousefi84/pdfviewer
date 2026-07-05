#include "mainwindow.hpp"

MainWindow::MainWindow (QWidget* parent) : QWidget (parent) {
    this->setWindowTitle ("pdf viewer");
    init_window_button ();
    handle_open_button_click();
};



void MainWindow::init_window_button () {
    open_button = new QPushButton ("Open",this);

    path_of_pdf_file = new QLineEdit (this);

    Glayout = new QGridLayout (this);

    Glayout->addWidget (open_button , 0 ,0 );

    Glayout->addWidget (path_of_pdf_file , 0 , 1);


};



void MainWindow::init_viewer_widget () {
    viewer_widget = new ViewerWidget (NULL , path_of_pdf_file->text());
    viewer_widget->show();    
};


void MainWindow::handle_open_button_click () {
    connect (open_button , SIGNAL (clicked()) , this , SLOT (init_viewer_widget()));
};