/*  =========================================================================
    dbklass - DB API

    Copyright (C) 2014 - 2015 Eaton                                        
                                                                           
    This program is free software; you can redistribute it and/or modify   
    it under the terms of the GNU General Public License as published by   
    the Free Software Foundation; either version 2 of the License, or      
    (at your option) any later version.                                    
                                                                           
    This program is distributed in the hope that it will be useful,        
    but WITHOUT ANY WARRANTY; without even the implied warranty of         
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          
    GNU General Public License for more details.                           
                                                                           
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.            
    =========================================================================
*/

/*
@header
    dbklass - DB API
@discuss
@end
*/

#include "dbtest_classes.h"
#include <tntdb.h>

#ifdef MARIADB_EMBEDED
#include <mysql/mysql.h>
#endif

//  Structure of our class

struct _dbklass_t {
    tntdb::Connection connection;
    char* url;
};


//  --------------------------------------------------------------------------
//  Create a new dbklass

dbklass_t *
dbklass_new (void)
{
    dbklass_t *self = (dbklass_t *) zmalloc (sizeof (dbklass_t));
    assert (self);
    //  Initialize class properties here
    return self;
}

int
dbklass_connect (dbklass_t *self, const char* url)
{
    assert (self);
    try {
        self->url = strdup (url);
        self->connection = tntdb::connect (self->url);
    }
    catch (std::exception &e)
    {
        zsys_error ("Can't connect to database: %s", e.what ());
        return -1;
    }
    return 0;
}


size_t
dbklass_metrics (dbklass_t *self)
{
    assert (self);
    tntdb::Row row = self->connection.selectRow ("SELECT COUNT(*) FROM t_bios_measurement");
    size_t ret = 0;
    row[0].get (ret);
    return ret;
}

//  --------------------------------------------------------------------------
//  Destroy the dbklass

void
dbklass_destroy (dbklass_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        dbklass_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        zstr_free (&self->url);
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Self test of this class

void
dbklass_test (bool verbose)
{
#ifdef MARIADB_EMBEDED
    static char const *server_args[] = {
      "this_program",       /* this string is not used */
      "--datadir=./__db__",
      "--key_buffer_size=32M"
    };
    static char const *server_groups[] = {
      "embedded",
      "server",
      "this_program_SERVER",
      (char *)NULL
    };
    system ("rm -rf ./__db__");
    system ("mkdir -p ./__db__");

    if (mysql_library_init(
            sizeof (server_args) / sizeof (char*),
            (char **) server_args,
            (char **) server_groups)) {
        zsys_error ("could not initialize MySQL library");
        exit(1);
    }
#endif

    printf (" * dbklass_test: ");
#ifndef MARIADB_EMBEDED
    zsys_error ("Build with -DMARIADB_EMBEDED to run the make check");
    exit (1);
#endif
    //  @selftest

    static const char* url = "mysql:db=box_utf8;user=root";

    dbklass_t *klass = dbklass_new ();
    int r = dbklass_connect (klass, url);
    assert (r != -1);

    size_t metrics = dbklass_metrics (klass);
    zsys_info ("metrics: %zu", metrics);
    //TODO: there should be an assert ;-)
    dbklass_destroy (&klass);
    //  @end
    printf ("OK\n");

#ifdef MARIADB_EMBEDED
    mysql_library_end();
#endif

}
