/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 "Guillaume Ludwig" <guillaume.ludwig@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/nlr.h"
#include "py/obj.h"
#include "py/objint.h"
#include "py/runtime.h"


STATIC mp_obj_t st7789_read(void) {
    return MP_OBJ_NEW_SMALL_INT(42);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(st7789_read_obj, st7789_read);


STATIC mp_obj_t st7789_add5(mp_obj_t value_to_add) {
    return mp_obj_new_int_from_uint(MP_OBJ_SMALL_INT_VALUE(value_to_add) + 5);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(st7789_add5_obj, st7789_add5);

STATIC const mp_rom_map_elem_t st7789_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_st7789) },

    { MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&st7789_read_obj) },
    { MP_ROM_QSTR(MP_QSTR_add5), MP_ROM_PTR(&st7789_add5_obj) },
};

STATIC MP_DEFINE_CONST_DICT(st7789_module_globals, st7789_module_globals_table);

const mp_obj_module_t st7789_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&st7789_module_globals,
};