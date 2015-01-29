#ifndef DDEBUG
#define DDEBUG 0
#endif

#include <ndk.h>
#include <uuid/uuid.h>
#include "ngx_http_uuid_module.h"

#define NGX_UUID_FUNC_EXPAND(__CMD_FUNC__, __FILTER_FUNC__, __UUID_FUNC__)	\
	ngx_int_t __FILTER_FUNC__(ngx_http_request_t *r, ngx_str_t *res, ngx_http_variable_value_t *v) {	\
		ngx_http_variable_value_t   *cur_v, *default_v;														\
																											\
		cur_v = &v[0];																						\
		default_v = &v[1];																					\
																											\
		if (cur_v->not_found || cur_v->len == 0) {															\
			res->len = 36;																					\
			res->data = ngx_palloc(r->pool, res->len);														\
			if (NULL == res->data) {																		\
				return NGX_ERROR;																			\
			}																								\
																											\
			uuid_t uuid;																					\
			__UUID_FUNC__(uuid);																			\
			uuid_unparse(uuid, (char *) res->data);															\
																											\
			return NGX_OK;																					\
		}																									\
																											\
		res->data = cur_v->data;																			\
		res->len = cur_v->len;																				\
																											\
		return NGX_OK;																						\
	}																										\
																											\
	char * __CMD_FUNC__(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {									\
		ngx_str_t               *value;																		\
		ndk_set_var_t            filter;																	\
																											\
		value = cf->args->elts;																				\
																											\
		filter.type = NDK_SET_VAR_MULTI_VALUE;																\
		filter.func = (void *) __FILTER_FUNC__;																\
		filter.size = 2;																					\
		filter.data = NULL;																					\
																											\
		return  ndk_set_var_multi_value_core(cf, &value[1], &value[1], &filter);							\
	}

static ngx_command_t  ngx_http_uuid_commands[] = {
    {
        ngx_string ("uuid"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF
            |NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1,
		ngx_http_uuid,
        0,
        0,
        NULL
    },
    {
        ngx_string ("uuid_random"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF
            |NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1,
		ngx_http_uuid_random,
        0,
        0,
        NULL
    },
    {
        ngx_string ("uuid_time"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF
            |NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1,
		ngx_http_uuid_time,
        0,
        0,
        NULL
    },
    {
        ngx_string ("uuid_time_safe"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF
            |NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1,
		ngx_http_uuid_time_safe,
        0,
        0,
        NULL
    },

    ngx_null_command
};

static ngx_http_module_t ngx_http_uuid_module_ctx = {
    NULL,                               	/* preconfiguration */
    NULL,                                 	/* postconfiguration */

    NULL,                                  	/* create main configuration */
    NULL,                                  	/* init main configuration */

    NULL,                                  	/* create server configuration */
    NULL,                                  	/* merge server configuration */

	NULL,     								/* create location configuration */
	NULL       								/*  merge location configuration */
};

ngx_module_t ngx_http_uuid_module = {
    NGX_MODULE_V1,
    &ngx_http_uuid_module_ctx,          	/* module context */
    ngx_http_uuid_commands,             	/* module directives */
    NGX_HTTP_MODULE,                        /* module type */
    NULL,                                   /* init master */
    NULL,                                   /* init module */
    NULL,                                   /* init process */
    NULL,                                   /* init thread */
    NULL,                                   /* exit thread */
    NULL,                                   /* exit process */
    NULL,                                   /* exit master */
    NGX_MODULE_V1_PADDING
};

NGX_UUID_FUNC_EXPAND(ngx_http_uuid, 			ngx_http_uuid_set_uuid, 			uuid_generate);
NGX_UUID_FUNC_EXPAND(ngx_http_uuid_random, 		ngx_http_uuid_set_uuid_random, 		uuid_generate_random);
NGX_UUID_FUNC_EXPAND(ngx_http_uuid_time, 		ngx_http_uuid_set_uuid_time, 		uuid_generate_time);
NGX_UUID_FUNC_EXPAND(ngx_http_uuid_time_safe,	ngx_http_uuid_set_uuid_time_safe, 	uuid_generate_time_safe);
