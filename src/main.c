#include <stdio.h>
#include <http.h>

void on_request(http_s *request);
FIOBJ HTTP_HEADER_X_DATA;

int main(void)
{
    HTTP_HEADER_X_DATA = fiobj_str_new("X-Data", 6);
    http_listen("3000", NULL, .on_request = on_request, .log = 1);
    fio_start(.threads = 1);
    fiobj_free(HTTP_HEADER_X_DATA);
}

void on_request(http_s *request)
{
    http_set_cookie(request, .name = "my_cookie", .name_len = 9, .value = "data",
                    .value_len = 4);
    http_set_header(request, HTTP_HEADER_CONTENT_TYPE,
                    http_mimetype_find("txt", 3));
    http_set_header(request, HTTP_HEADER_X_DATA, fiobj_str_new("my data", 7));
    http_send_body(request, "Hello World!\r\n", 14);
}