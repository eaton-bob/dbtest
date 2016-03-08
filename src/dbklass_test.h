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

#ifndef DBKLASS_TEST_H_INCLUDED
#define DBKLASS_TEST_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _dbklass_test_t dbklass_test_t;

//  @interface
//  Create a new dbklass_test
DBTEST_EXPORT dbklass_test_t *
    dbklass_test_new (void);

//  Destroy the dbklass_test
DBTEST_EXPORT void
    dbklass_test_destroy (dbklass_test_t **self_p);

//  Self test of this class
DBTEST_EXPORT void
    dbklass_test_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
