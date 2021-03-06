/*
    Copyright (c) 2007-2013 Contributors as noted in the AUTHORS file

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_SCTP_HPP_INCLUDED__
#define __ZMQ_SCTP_HPP_INCLUDED__

#include "fd.hpp"

namespace zmq
{

    //  Tunes the supplied SCTP socket for the best latency.
    void tune_sctp_socket (fd_t s_);

    //  Sets the socket send buffer size.
    void set_sctp_send_buffer (fd_t sockfd_, int bufsize_);

    //  Sets the socket receive buffer size.
    void set_sctp_receive_buffer (fd_t sockfd_, int bufsize_);

    //  Tunes SCTP keep-alives
    void tune_sctp_keepalives (fd_t s_, int keepalive_, int keepalive_cnt_, int keepalive_idle_, int keepalive_intvl_);

}

#endif 
