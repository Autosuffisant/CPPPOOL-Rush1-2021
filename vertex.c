/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL)
        raise("This must be initialized");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this == NULL)
        raise("This must be initialized");
}

static const char *Vertex_str(VertexClass *this)
{
    char *buf = NULL;

    if (this == NULL)
        raise("This must be initialized");
    asprintf(&buf, "<%s (%d, %d, %d)>",
            ((Class *)this)->__name__, this->x, this->y, this->z);
    return (buf);
}

static Object *Vertex_add(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Vertex, ((VertexClass *)this)->x, ((VertexClass *)this)->y,
    ((VertexClass *)this)->z);
    ((VertexClass *)res)-> x += ((VertexClass *)other)->x;
    ((VertexClass *)res)-> y += ((VertexClass *)other)->y;
    ((VertexClass *)res)-> z += ((VertexClass *)other)->z;
    return ((Object *)res);
}

static Object *Vertex_sub(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Vertex, ((VertexClass *)this)->x, ((VertexClass *)this)->y,
    ((VertexClass *)this)->z);
    ((VertexClass *)res)-> x -= ((VertexClass *)other)->x;
    ((VertexClass *)res)-> y -= ((VertexClass *)other)->y;
    ((VertexClass *)res)-> z -= ((VertexClass *)other)->z;
    return ((Object *)res);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
