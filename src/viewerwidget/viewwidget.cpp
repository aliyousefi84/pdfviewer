#include "viewwidget.hpp"

ViewerWidget::ViewerWidget (QMainWindow* parent , string filepath) : QMainWindow(parent) {
    this->filepath = filepath;
    setWindowTitle ("pdf viewer");
    resize (1000,800);

    create_menubar ();
    init_view_widget ();
    init_list_widget ();
    setup_centralwidget_layout ();
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
    
    for (int i = 0;i < doc->pages();i++) {
        item = new QListWidgetItem;
        item->setText ("page");
        item->setIcon (QIcon("/home/ali-pc/my_own_project/pdfviewer/src/png/folder.png"));
        
        list_widget->setViewMode (QListView::IconMode);
        list_widget->setGridSize (QSize(100,120));
        list_widget->setIconSize (QSize(64,64));
        list_widget->setSpacing (10);
        list_widget->setDragEnabled (false);
        list_widget->setAcceptDrops (false);
        list_widget->addItem (item);
        
    }

};





void ViewerWidget::setup_pdf_reader () {
    doc = document::load_from_file (filepath);
};





void ViewerWidget::init_view_widget () {
    view_widget = new QWidget (this);
    setup_pdf_reader ();

    for (int i = 0; i < doc->pages(); i++)
    {
        page_of_pdf = doc->create_page (i);
        img = render.render_page (page_of_pdf , 72,72);

        const char* data = img.data();

        image = new QImage ((unsigned char*)data,img.height(),img.width(),QImage::Format_RGB888);

        pixmap = QPixmap::fromImage (*image);

        label = new QLabel (view_widget);
        label->setPixmap (pixmap.scaled (view_widget->size() , Qt::KeepAspectRatio));
        
    }
    
};





void ViewerWidget::setup_centralwidget_layout () {
    main_splitter = new QSplitter (this);
    this->setCentralWidget (main_splitter);

    main_splitter->addWidget (view_widget);
    main_splitter->addWidget (list_widget);

};