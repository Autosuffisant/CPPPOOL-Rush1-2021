/*
** EPITECH PROJECT, 2021
** B CPP Rush 1
** File description:
** Ex01
*/

#include "object.h"
#include "player.h"

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    if (ptr)
        free(ptr);
}

Object  *va_new(const Class *class, va_list* ap)
{
    Class *new  = malloc(class->__size__);

    if (new == NULL)
        raise("Constructor Error.");
    if (memcpy(new, class, class->__size__) == NULL)
        raise("Constructor Error.");
    if (class->__ctor__)
        class->__ctor__(new, ap);
    return ((Object *)new);
}

Object  *new(const Class *class, ...)
{
    Class *new;
    va_list ap;

    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);
    return ((Object *)new);
}
