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
#include "float.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        raise("This must be initialized");
    this->x = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (this == NULL)
        raise("This must be initialized");
}

static char *Float_str(FloatClass *this)
{
    char *buf = NULL;

    if (this == NULL)
        raise("This must be initialized");
    asprintf(&buf, "<%s (%f)>", ((Class *)this)->__name__, this->x);
    return (buf);
}

static Object *Float_add(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Float, ((FloatClass *)this)->x);
    ((FloatClass *)res)->x += ((FloatClass *)other)->x;
    return ((Object *)res);
}

static Object *Float_sub(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Float, ((FloatClass *)this)->x, ((FloatClass *)this)->x);
    ((FloatClass *)res)->x -= ((FloatClass *)other)->x;
    return ((Object *)res);
}

static Object *Float_mul(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Float, ((FloatClass *)this)->x);
    ((FloatClass *)res)->x *= ((FloatClass *)other)->x;
    return ((Object *)res);
}

static Object *Float_div(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Float, ((FloatClass *)this)->x, ((FloatClass *)this)->x);
    ((FloatClass *)res)->x /= ((FloatClass *)other)->x;
    return ((Object *)res);
}

static bool Float_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((FloatClass *)this)->x == ((FloatClass *)other)->x);
}

static bool Float_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((FloatClass *)this)->x > ((FloatClass *)other)->x);
}

static bool Float_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((FloatClass *)this)->x < ((FloatClass *)other)->x);
}

static const FloatClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;
