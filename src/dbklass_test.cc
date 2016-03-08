/*  =========================================================================
    dbklass_test - DB API test using embeded MariaDB

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
    dbklass_test - DB API test using embeded MariaDB
@discuss
@end
*/

#include "dbtest_classes.h"

//  Structure of our class

struct _dbklass_test_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new dbklass_test

dbklass_test_t *
dbklass_test_new (void)
{
    dbklass_test_t *self = (dbklass_test_t *) zmalloc (sizeof (dbklass_test_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the dbklass_test

void
dbklass_test_destroy (dbklass_test_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        dbklass_test_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Self test of this class

void
dbklass_test_test (bool verbose)
{
    printf (" * dbklass_test: ");

    //  @selftest
    //  Simple create/destroy test
    dbklass_test_t *self = dbklass_test_new ();
    assert (self);
    dbklass_test_destroy (&self);
    //  @end
    printf ("OK\n");
}
