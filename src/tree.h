/* vim: set ts=2 expandtab: */
/**
 *       @file  tree.c
 *      @brief  String-indexed search tree for Commotion object system.
 *
 *     @author  Josh King (jheretic), jking@chambana.net
 *
 *   @internal
 *      Created  11/14/2013 10:43:57 PM
 *     Compiler  gcc/g++
 * Organization  The Open Technology Institute
 *    Copyright  Copyright (c) 2013, Josh King
 *
 * This file is part of Commotion, Copyright (c) 2013, Josh King 
 * 
 * Commotion is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 * 
 * Commotion is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Commotion.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */
#ifndef _TREE_H
#define _TREE_H
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include "debug.h"
#include "extern/halloc.h"

typedef struct _treenode_t _treenode_t;

/* Type "tree" declaration macros */
#define _DECLARE_TREE(L) typedef struct { co_obj_t _header; uint##L##_t _len; \
  _treenode_t *root;} co_tree##L##_t; int co_tree##L##_alloc(\
  co_obj_t *output); co_obj_t *co_tree##L##_create(void);

_DECLARE_TREE(16);
_DECLARE_TREE(32);

co_obj_t *co_node_value(_treenode_t *node);
int co_node_set_str(_treenode_t *n, const char *value, const size_t vlen);
int co_node_set_int(_treenode_t *n, const signed long value);
int co_node_set_uint(_treenode_t *n, const unsigned long value);
int co_node_set_float(_treenode_t *n, const double value);

_treenode_t *co_tree_find_node(_treenode_t *root, const char *key, const size_t klen);
_treenode_t *co_tree_root(const co_obj_t *tree);

co_obj_t *co_tree_find(const co_obj_t *root, const char *key, const size_t klen);
co_obj_t *co_tree_delete(co_obj_t *root, const char *key, const size_t klen);
int co_tree_insert(co_obj_t *root, const char *key, const size_t klen, co_obj_t *value);
int co_tree_set_str(co_obj_t *root, const char *key, const size_t klen, const char *value, const size_t vlen);
int co_tree_set_int(co_obj_t *root, const char *key, const size_t klen, const signed long value);
int co_tree_set_uint(co_obj_t *root, const char *key, const size_t klen, const unsigned long value);
int co_tree_set_float(co_obj_t *root, const char *key, const size_t klen, const double value);
int co_tree_process(co_obj_t *tree, const co_iter_t iter, void *context);
void co_tree_destroy(co_obj_t *root);


#endif
