/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef OCAC_MDNS_H
#define OCAC_MDNS_H

#define OCAC_MDNS_SRV_TCP       "_oca._tcp"
#define OCAC_MDNS_SRV_TCPSEC    "_ocasec._tcp"
#define OCAC_MDNS_SRV_UDP       "_oca._udp"
#define OCAC_MDNS_SRV_WEBSOCK   "_ocaws._tcp"


/**
 * Generic macro for service txt entry data
 */
#define OCAC_MDNS_TXT( __txtverslen__, __txtvers__, __protoverslen__, __protovers__)                            #__txtverslen__ "txtvers=" #__txtvers__ #__protoverslen__ "protovers=" #__protovers__

/**
 * Typical format and version length fields
 */
#define OCAC_MDNS_TXT_TYPICAL(__txtvers__, __protovers__)                                                       OCAC_MDNS_TXT("\x09", __txtvers__, "\x0B", __protovers__)

#define OCAC_MDNS_TXT_WS( __txtverslen__, __txtvers__, __protoverslen__, __protovers__, __pathlen__, __path__ ) OCAC_MDNS_TXT( __txtverslen__, __txtvers__, __protoverslen__, __protovers__ ) #__pathlen__ "path" = #__path__

#define OCAC_MDNS_TXT_WS_TYPICAL(__txtvers__, __protovers__, __pathlen__, __path__)                             OCAC_MDNS_TXT_WS( "\x09", __txtvers__, "\x0B", __protovers__, __pathlen__, __path__ )



#endif //OCAC_MDNS_H
