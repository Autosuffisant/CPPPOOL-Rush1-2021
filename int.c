/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "new.h"
#include "int.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        raise("This must be initialized");
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (this == NULL)
        raise("This must be initialized");
}

static char *Int_str(IntClass *this)
{
    char *buf = NULL;

    if (this == NULL)
        raise("This must be initialized");
    asprintf(&buf, "<%s (%d)>", ((Class *)this)->__name__, this->x);
    return (buf);
}

static Object *Int_add(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Int, ((IntClass *)this)->x);
    ((IntClass *)res)->x += ((IntClass *)other)->x;
    return ((Object *)res);
}

static Object *Int_sub(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Int, ((IntClass *)this)->x, ((IntClass *)this)->x);
    ((IntClass *)res)->x -= ((IntClass *)other)->x;
    return ((Object *)res);
}

static Object *Int_mul(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Int, ((IntClass *)this)->x);
    ((IntClass *)res)->x *= ((IntClass *)other)->x;
    return ((Object *)res);
}

static Object *Int_div(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Int, ((IntClass *)this)->x, ((IntClass *)this)->x);
    ((IntClass *)res)->x /= ((IntClass *)other)->x;
    return ((Object *)res);
}

static bool Int_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((IntClass *)this)->x == ((IntClass *)other)->x);
}

static bool Int_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((IntClass *)this)->x > ((IntClass *)other)->x);
}

static bool Int_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((IntClass *)this)->x < ((IntClass *)other)->x);
}

static const IntClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
