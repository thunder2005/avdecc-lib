/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2014 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * external_port_input_descriptor_imp.cpp
 *
 * EXTERNAL_PORT_INPUT descriptor implementation
 */

#include <mutex>

#include "avdecc_error.h"
#include "enumeration.h"
#include "log_imp.h"
#include "end_station_imp.h"
#include "external_port_input_descriptor_imp.h"
#include "descriptor_field_imp.h"

namespace avdecc_lib
{
external_port_input_descriptor_imp::external_port_input_descriptor_imp(end_station_imp * end_station_obj, const uint8_t * frame, ssize_t pos, size_t frame_len) : descriptor_base_imp(end_station_obj, frame, frame_len, pos) {}

external_port_input_descriptor_imp::~external_port_input_descriptor_imp() {}

external_port_input_descriptor_response * STDCALL external_port_input_descriptor_imp::get_external_port_input_response()
{
    std::lock_guard<std::mutex> guard(base_end_station_imp_ref->locker); //mutex lock end station
    return resp = new external_port_input_descriptor_response_imp(resp_ref->get_desc_buffer(),
                                                                  resp_ref->get_desc_size(), resp_ref->get_desc_pos());
}
}
