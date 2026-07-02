#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <poppler/cpp/poppler-image.h>
#include <iostream>
#include <vector>

using namespace poppler;
using namespace std;

class Services {
    public:
        
        Services (string filepath);
        ~Services ();

        int page_count_file ();

        void get_image_data ();


        vector<char*> image_data;

        page_renderer render;

        image img;

        page* page_of_pdf_file;

        document* doc;


};