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

#ifndef DBKLASS_H_INCLUDED
#define DBKLASS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new dbklass
DBTEST_EXPORT dbklass_t *
    dbklass_new (void);

//  Destroy the dbklass
DBTEST_EXPORT void
    dbklass_destroy (dbklass_t **self_p);

// Connect to DB
DBTEST_EXPORT int
    dbklass_connect (dbklass_t *self, const char* url);

// Number of metrics
DBTEST_EXPORT size_t
    dbklass_metrics (dbklass_t *self);

//  Self test of this class
DBTEST_EXPORT void
    dbklass_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
