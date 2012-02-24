/*
 * Copyright (c) 2012 Ben Johnson, http://skylandlabs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>

#include "dbg.h"
#include "bstring.h"
#include "database.h"

//==============================================================================
//
// Database Management
//
//==============================================================================

/*
 * Creates a reference to a database.
 *
 * path - The file path where the data resides on disk.
 */
Database *Database_create(bstring path)
{
    Database *database;

    check(path != NULL, "Cannot create database without a path");
    
    database = malloc(sizeof(Database));
    database->path = bstrcpy(path); check_mem(database->path);

    return database;
    
error:
    Database_destroy(database);
    return NULL;
}

/*
 * Removes a database reference from memory.
 */
void Database_destroy(Database *database)
{
    if(database) {
        bdestroy(database->path); database->path = NULL;
        free(database);
    }
}
