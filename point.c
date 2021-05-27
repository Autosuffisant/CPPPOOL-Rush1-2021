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
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        raise("This must be initialized");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this == NULL)
        raise("This must be initialized");
}

static const char *Point_str(PointClass *this)
{
    char *buf = NULL;

    if (this == NULL)
        raise("This must be initialized");
    asprintf(&buf, "<%s (%d, %d)>",
            ((Class *)this)->__name__, this->x, this->y);
    return (buf);
}

static Object *Point_add(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Point, ((PointClass *)this)->x, ((PointClass *)this)->y);
    ((PointClass *)res)->x += ((PointClass *)other)->x;
    ((PointClass *)res)->y += ((PointClass *)other)->y;
    return ((Object *)res);
}

static Object *Point_sub(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Point, ((PointClass *)this)->x, ((PointClass *)this)->y);
    ((PointClass *)res)->x -= ((PointClass *)other)->x;
    ((PointClass *)res)->y -= ((PointClass *)other)->y;
    return ((Object *)res);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
