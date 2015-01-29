# uuid-nginx-module
Create a new unique UUID value

Table of Contents
=================

* [Version](#version)
* [Synopsis](#synopsis)
* [Description](#description)
* [Directives](#directives)
    * [uuid](#uuid)
    * [uuid_random](#uuid_random)
    * [uuid_time](#uuid_time)
    * [uuid_time_safe](#uuid_time_safe)
* [Installation](#installation)

Version
=======
0.01

Synopsis
========

```nginx

 location /uuid/ {
     uuid           $uuid;
     uuid_random    $uuid_random;
     uuid_time      $uuid_time;
     uuid_time_safe $uuid_time_safe;
     
     set  $not_empty_var  "not empty";
     uuid           $not_empty_var;
     uuid_random    $not_empty_var;
     uuid_time      $not_empty_var;
     uuid_time_safe $not_empty_var;
     
     echo "uuid=$uuid";
     echo "uuid_random=$uuid_random";
     echo "uuid_time=$uuid_time";
     echo "uuid_time_safe=$uuid_time_safe";
     echo "not_empty_var=$not_empty_var";

     # Then request GET /uuid/ will yield the following output
     # uuid=129dc372-bd6b-495d-b919-491ab974bcd4
     # uuid_random=18d29ca3-f1f8-4480-a94c-b5d392af69db
     # uuid_time=f8eb0672-a77e-11e4-bfca-d79ae6b6e75a
     # uuid_time_safe=f8eb074e-a77e-11e4-bfca-d79ae6b6e75a
     # not_empty_var=not empty
 }

```

Description
===========

Assign a new unique UUID value if and only if given variable is empty. See [OSSP uuid](http://www.ossp.org/pkg/lib/uuid/).

Directives
==========

uuid
------------
**syntax:** *uuid $dst*

**default:** *no*

**context:** *http, server, server if, location, location if*

**phase:** *rewrite*

uuid_random
------------
**syntax:** *uuid $dst*

**default:** *no*

**context:** *http, server, server if, location, location if*

**phase:** *rewrite*

uuid_time
------------
**syntax:** *uuid $dst*

**default:** *no*

**context:** *http, server, server if, location, location if*

**phase:** *rewrite*

uuid_time_safe
------------
**syntax:** *uuid $dst*

**default:** *no*

**context:** *http, server, server if, location, location if*

**phase:** *rewrite*

Installation
============

Download the latest tarball for [ngx_devel_kit](https://github.com/simpl/ngx_devel_kit) from its [file list](https://github.com/simpl/ngx_devel_kit/tags).

```bash

 wget 'http://nginx.org/download/nginx-1.7.7.tar.gz'
 tar -xzvf nginx-1.7.7.tar.gz
 cd nginx-1.7.7/

 # Here we assume you would install you nginx under /opt/nginx/.
 ./configure --prefix=/opt/nginx \
     --add-module=/path/to/ngx_devel_kit \
     --add-module=/path/to/uuid-nginx-module

 make
 make install
```
