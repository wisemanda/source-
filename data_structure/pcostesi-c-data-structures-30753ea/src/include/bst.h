/*
 *      bstADT.h
 *
 *      Copyright 2010:
 *          Pablo Alejandro Costesich <pcostesi@alu.itba.edu.ar>
 *
 *      Redistribution and use in source and binary forms, with or without
 *      modification, are permitted provided that the following conditions are
 *      met:
 *
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following disclaimer
 *        in the documentation and/or other materials provided with the
 *        distribution.
 *      * Neither the name of the Owner nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 *      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *      "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *      LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *      A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *      OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *      SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *      LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *      DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *      THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *      OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef __BSTH
#define __BSTH 1

#include <stddef.h>

typedef struct bstnode bstnode;

bstnode *  bst_set(bstnode *root, char * key, void * val, size_t size);
bstnode *  bst_add(bstnode *root, char * key, void * val, size_t size);
bstnode *  bst_search(bstnode *root, char * key);
bstnode *  bst_update(bstnode *root, char * key, void * val, size_t size);
bstnode *  bst_pop(bstnode *root, char * key);
bstnode *  bst_delete(bstnode *root, char * key);
size_t  bst_get(bstnode *r, char * key, void * d, size_t s);
bstnode *  bst_minimum(bstnode *root);
bstnode *  bst_maximum(bstnode *root);
void    bst_dispose(bstnode * n);
void    bst_free(bstnode * n);
size_t  bst_node_size(bstnode *n);
size_t  bst_node_content(bstnode *n, void * d, size_t s);
size_t  bst_nearest(bstnode * root, char * key, void * d, size_t s);

#endif
