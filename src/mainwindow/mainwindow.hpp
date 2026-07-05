#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include "../viewerwidget/viewwidget.hpp"



class MainWindow : public QWidget {
    Q_OBJECT
    public:
        MainWindow (QWidget* parent = nullptr);
    
    private slots:
        void init_viewer_widget ();
    
    private:
        
        void handle_open_button_click ();

        void init_window_button ();

        QPushButton* open_button;

        QLineEdit* path_of_pdf_file;

        QGridLayout* Glayout;

        ViewerWidget* viewer_widget;
};

#endif