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

#ifndef __ZMQ_OPTIONS_HPP_INCLUDED__
#define __ZMQ_OPTIONS_HPP_INCLUDED__

#include <string>
#include <vector>

#include "stddef.h"
#include "stdint.hpp"
#include "ip_address.hpp"
#include "../include/zmq.h"

//  Normal base 256 key is 32 bytes
#define CURVE_KEYSIZE       32
//  Key encoded using Z85 is 40 bytes
#define CURVE_KEYSIZE_Z85   40

namespace zmq
{
    struct options_t
    {
        options_t ();

        int setsockopt (int option_, const void *optval_, size_t optvallen_);
        int getsockopt (int option_, void *optval_, size_t *optvallen_);

        //  High-water marks for message pipes.
        int sndhwm;
        int rcvhwm;

        //  I/O thread affinity.
        uint64_t affinity;

        //  Socket identity
        unsigned char identity_size;
        unsigned char identity [256];

        //  Maximum transfer rate [kb/s]. Default 100kb/s.
        int rate;

        //  Reliability time interval [ms]. Default 10 seconds.
        int recovery_ivl;

        // Sets the time-to-live field in every multicast packet sent.
        int multicast_hops;

        // SO_SNDBUF and SO_RCVBUF to be passed to underlying transport sockets.
        int sndbuf;
        int rcvbuf;

        //  Socket type.
        int type;

        //  Linger time, in milliseconds.
        int linger;

        //  Minimum interval between attempts to reconnect, in milliseconds.
        //  Default 100ms
        int reconnect_ivl;

        //  Maximum interval between attempts to reconnect, in milliseconds.
        //  Default 0 (unused)
        int reconnect_ivl_max;

        //  Maximum backlog for pending connections.
        int backlog;

        //  Maximal size of message to handle.
        int64_t maxmsgsize;

        // The timeout for send/recv operations for this socket.
        int rcvtimeo;
        int sndtimeo;

        //  If true, IPv6 is enabled (as well as IPv4)
        bool ipv6;

        //  If 1, connecting pipes are not attached immediately, meaning a send()
        //  on a socket with only connecting pipes would block
        int immediate;

        //  If 1, (X)SUB socket should filter the messages. If 0, it should not.
        bool filter;

        //  If true, the identity message is forwarded to the socket.
        bool recv_identity;

        // if true, router socket accepts non-zmq tcp connections
        bool raw_sock;

        //  TCP keep-alive settings.
        //  Defaults to -1 = do not change socket options
        int tcp_keepalive;
        int tcp_keepalive_cnt;
        int tcp_keepalive_idle;
        int tcp_keepalive_intvl;

        // TCP accept() filters
        typedef std::vector <ip_address_mask_t> tcp_accept_filters_t;
        tcp_accept_filters_t tcp_accept_filters;

        //  SCTP keep-alive settings.
        //  Defaults to -1 = do not change socket options
        int sctp_keepalive;
        int sctp_keepalive_cnt;
        int sctp_keepalive_idle;
        int sctp_keepalive_intvl;

        // SCTP accept() filters
        typedef std::vector <ip_address_mask_t> sctp_accept_filters_t;
        sctp_accept_filters_t sctp_accept_filters;

        //  Security mechanism for all connections on this socket
        int mechanism;

        //  If peer is acting as server for PLAIN or CURVE mechanisms
        int as_server;

        //  ZAP authentication domain
        std::string zap_domain;

        //  Security credentials for PLAIN mechanism
        std::string plain_username;
        std::string plain_password;

        //  Security credentials for CURVE mechanism
        uint8_t curve_public_key [CURVE_KEYSIZE];
        uint8_t curve_secret_key [CURVE_KEYSIZE];
        uint8_t curve_server_key [CURVE_KEYSIZE];

        //  ID of the socket.
        int socket_id;

        //  If true, socket conflates outgoing/incoming messages.
        //  Applicable to dealer, push/pull, pub/sub socket types.
        //  Cannot receive multi-part messages.
        //  Ignores hwm
        bool conflate;
    };
}

#endif
