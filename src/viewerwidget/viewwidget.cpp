#include "viewwidget.hpp"

ViewerWidget::ViewerWidget (QMainWindow* parent , QString filepath) : QMainWindow(parent) {
    this->filepath = filepath;
    setWindowTitle ("pdf viewer");
    resize (1000,1200);
    stack_widget = new QStackedWidget(this);


    
    init_view_widget ();
    init_list_widget ();
    setup_centralwidget_layout ();
    handle_listwidget_item_signal ();
};





void ViewerWidget::init_list_widget () {
    list_widget = new QListWidget (this);
    list_widget->setMaximumWidth (200);
    list_widget->setViewMode (QListView::ListMode);
    
    for (int i = 0;i < doc->numPages();i++) {
        item = new QListWidgetItem;
        QString str;
        item->setText (str.fromStdString(std::to_string(i)));
        // system path : you should change the username
        item->setIcon (QIcon("/home/ali-pc/my_own_project/pdfviewer/src/png/page.png"));
        
        list_widget->setDragEnabled (false);
        list_widget->setAcceptDrops (false);
        list_widget->addItem (item);
        
    }

};



void ViewerWidget::set_graphic_view (int i) {
    scene = new QGraphicsScene;
    scene->addPixmap (pixmaps[i]);
        
    view = new QGraphicsView;
    view->setScene (scene);
    view->setRenderHint (QPainter::Antialiasing);
    view->setRenderHint (QPainter::SmoothPixmapTransform);
    view->setDragMode (QGraphicsView::ScrollHandDrag);    
    views.append (view);
};


void ViewerWidget::init_view_widget () {
    
    doc = Document::load(filepath);
    if (doc == NULL)
    {
        cout << "document is NULL !" << endl;
        exit(1);
    }
    for (int i = 0; i < doc->numPages(); i++) {
    
        page_of_pdf = doc->page(i);
    
        image = page_of_pdf->renderToImage(100,100,-1,-1,-1,-1);

        pixmap = QPixmap::fromImage (image);
        pixmaps.append (pixmap);

        set_graphic_view (i);
        stack_widget->addWidget (views[i]);
    }
    stack_widget->setCurrentIndex (0);
};





void ViewerWidget::setup_centralwidget_layout () {
    main_splitter = new QSplitter (this);
    this->setCentralWidget (main_splitter);

    
    main_splitter->addWidget (list_widget);
    main_splitter->addWidget (stack_widget);
};




void ViewerWidget::handle_listwidget_item_signal () {
    connect (list_widget , SIGNAL (currentRowChanged(int)) , stack_widget , SLOT (setCurrentIndex(int)));
};


ViewerWidget::~ViewerWidget () {};