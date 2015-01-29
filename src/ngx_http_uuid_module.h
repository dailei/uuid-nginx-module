#ifndef NGX_HTTP_UUID_MODULE_H
#define NGX_HTTP_UUID_H

#include <ngx_core.h>
#include <ngx_config.h>
#include <ngx_http.h>

char * ngx_http_uuid(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
char * ngx_http_uuid_random(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
char * ngx_http_uuid_time(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
char * ngx_http_uuid_time_safe(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

ngx_int_t ngx_http_uuid_set_uuid(ngx_http_request_t *r, ngx_str_t *res, ngx_http_variable_value_t *v);
ngx_int_t ngx_http_uuid_set_uuid_random(ngx_http_request_t *r, ngx_str_t *res, ngx_http_variable_value_t *v);
ngx_int_t ngx_http_uuid_set_uuid_time(ngx_http_request_t *r, ngx_str_t *res, ngx_http_variable_value_t *v);
ngx_int_t ngx_http_uuid_set_uuid_time_safe(ngx_http_request_t *r, ngx_str_t *res, ngx_http_variable_value_t *v);

#endif
