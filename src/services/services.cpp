#include "services.hpp"

Services::Services (string filepath) {
    doc = document::load_from_file (filepath);
};



int Services::page_count_file () {
    return doc->pages();
};



void Services::get_image_data () {
    for (int i = 0; i < page_count_file(); i++)
    {
        page_of_pdf_file = doc->create_page (i);

        img = render.render_page (page_of_pdf_file , 72,72);

        image_data.push_back (img.data());

        delete page_of_pdf_file;
    }
    
};



Services::~Services () {
    delete doc;
};