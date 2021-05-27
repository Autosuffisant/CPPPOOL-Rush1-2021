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
#include "char.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        raise("This must be initialized");
    this->x = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (this == NULL)
        raise("This must be initialized");
}

static char *Char_str(CharClass *this)
{
    char *buf = NULL;

    if (this == NULL)
        raise("This must be initialized");
    asprintf(&buf, "<%s (%c)>", ((Class *)this)->__name__, this->x);
    return (buf);
}

static Object *Char_add(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Char, ((CharClass *)this)->x);
    ((CharClass *)res)->x += ((CharClass *)other)->x;
    return ((Object *)res);
}

static Object *Char_sub(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Char, ((CharClass *)this)->x, ((CharClass *)this)->x);
    ((CharClass *)res)->x -= ((CharClass *)other)->x;
    return ((Object *)res);
}

static Object *Char_mul(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Char, ((CharClass *)this)->x);
    ((CharClass *)res)->x *= ((CharClass *)other)->x;
    return ((Object *)res);
}

static Object *Char_div(const Object *this, const Object *other)
{
    Class *res;

    if (this == NULL || other == NULL)
        raise("This must be initialized");
    res = new(Char, ((CharClass *)this)->x, ((CharClass *)this)->x);
    ((CharClass *)res)->x /= ((CharClass *)other)->x;
    return ((Object *)res);
}

static bool Char_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((CharClass *)this)->x == ((CharClass *)other)->x);
}

static bool Char_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((CharClass *)this)->x > ((CharClass *)other)->x);
}

static bool Char_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("This must be initialized");
    return (((CharClass *)this)->x < ((CharClass *)other)->x);
}

static const CharClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;
