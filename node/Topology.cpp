/*
 * ZeroTier One - Network Virtualization Everywhere
 * Copyright (C) 2011-2016  ZeroTier, Inc.  https://www.zerotier.com/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Constants.hpp"
#include "Topology.hpp"
#include "RuntimeEnvironment.hpp"
#include "Node.hpp"
#include "Network.hpp"
#include "NetworkConfig.hpp"
#include "Buffer.hpp"

namespace ZeroTier {

// 2015-11-16 -- The Fabulous Four (should have named them after Beatles!)
//#define ZT_DEFAULT_WORLD_LENGTH 494
//static const unsigned char ZT_DEFAULT_WORLD[ZT_DEFAULT_WORLD_LENGTH] = {0x01,0x00,0x00,0x00,0x00,0x08,0xea,0xc9,0x0a,0x00,0x00,0x01,0x51,0x11,0x70,0xb2,0xfb,0xb8,0xb3,0x88,0xa4,0x69,0x22,0x14,0x91,0xaa,0x9a,0xcd,0x66,0xcc,0x76,0x4c,0xde,0xfd,0x56,0x03,0x9f,0x10,0x67,0xae,0x15,0xe6,0x9c,0x6f,0xb4,0x2d,0x7b,0x55,0x33,0x0e,0x3f,0xda,0xac,0x52,0x9c,0x07,0x92,0xfd,0x73,0x40,0xa6,0xaa,0x21,0xab,0xa8,0xa4,0x89,0xfd,0xae,0xa4,0x4a,0x39,0xbf,0x2d,0x00,0x65,0x9a,0xc9,0xc8,0x18,0xeb,0x80,0x31,0xa4,0x65,0x95,0x45,0x06,0x1c,0xfb,0xc2,0x4e,0x5d,0xe7,0x0a,0x40,0x7a,0x97,0xce,0x36,0xa2,0x3d,0x05,0xca,0x87,0xc7,0x59,0x27,0x5c,0x8b,0x0d,0x4c,0xb4,0xbb,0x26,0x2f,0x77,0x17,0x5e,0xb7,0x4d,0xb8,0xd3,0xb4,0xe9,0x23,0x5d,0xcc,0xa2,0x71,0xa8,0xdf,0xf1,0x23,0xa3,0xb2,0x66,0x74,0xea,0xe5,0xdc,0x8d,0xef,0xd3,0x0a,0xa9,0xac,0xcb,0xda,0x93,0xbd,0x6c,0xcd,0x43,0x1d,0xa7,0x98,0x6a,0xde,0x70,0xc0,0xc6,0x1c,0xaf,0xf0,0xfd,0x7f,0x8a,0xb9,0x76,0x13,0xe1,0xde,0x4f,0xf3,0xd6,0x13,0x04,0x7e,0x19,0x87,0x6a,0xba,0x00,0x2a,0x6e,0x2b,0x23,0x18,0x93,0x0f,0x60,0xeb,0x09,0x7f,0x70,0xd0,0xf4,0xb0,0x28,0xb2,0xcd,0x6d,0x3d,0x0c,0x63,0xc0,0x14,0xb9,0x03,0x9f,0xf3,0x53,0x90,0xe4,0x11,0x81,0xf2,0x16,0xfb,0x2e,0x6f,0xa8,0xd9,0x5c,0x1e,0xe9,0x66,0x71,0x56,0x41,0x19,0x05,0xc3,0xdc,0xcf,0xea,0x78,0xd8,0xc6,0xdf,0xaf,0xba,0x68,0x81,0x70,0xb3,0xfa,0x00,0x01,0x04,0xc6,0xc7,0x61,0xdc,0x27,0x09,0x88,0x41,0x40,0x8a,0x2e,0x00,0xbb,0x1d,0x31,0xf2,0xc3,0x23,0xe2,0x64,0xe9,0xe6,0x41,0x72,0xc1,0xa7,0x4f,0x77,0x89,0x95,0x55,0xed,0x10,0x75,0x1c,0xd5,0x6e,0x86,0x40,0x5c,0xde,0x11,0x8d,0x02,0xdf,0xfe,0x55,0x5d,0x46,0x2c,0xcf,0x6a,0x85,0xb5,0x63,0x1c,0x12,0x35,0x0c,0x8d,0x5d,0xc4,0x09,0xba,0x10,0xb9,0x02,0x5d,0x0f,0x44,0x5c,0xf4,0x49,0xd9,0x2b,0x1c,0x00,0x01,0x04,0x6b,0xbf,0x2e,0xd2,0x27,0x09,0x8a,0xcf,0x05,0x9f,0xe3,0x00,0x48,0x2f,0x6e,0xe5,0xdf,0xe9,0x02,0x31,0x9b,0x41,0x9d,0xe5,0xbd,0xc7,0x65,0x20,0x9c,0x0e,0xcd,0xa3,0x8c,0x4d,0x6e,0x4f,0xcf,0x0d,0x33,0x65,0x83,0x98,0xb4,0x52,0x7d,0xcd,0x22,0xf9,0x31,0x12,0xfb,0x9b,0xef,0xd0,0x2f,0xd7,0x8b,0xf7,0x26,0x1b,0x33,0x3f,0xc1,0x05,0xd1,0x92,0xa6,0x23,0xca,0x9e,0x50,0xfc,0x60,0xb3,0x74,0xa5,0x00,0x01,0x04,0xa2,0xf3,0x4d,0x6f,0x27,0x09,0x9d,0x21,0x90,0x39,0xf3,0x00,0x01,0xf0,0x92,0x2a,0x98,0xe3,0xb3,0x4e,0xbc,0xbf,0xf3,0x33,0x26,0x9d,0xc2,0x65,0xd7,0xa0,0x20,0xaa,0xb6,0x9d,0x72,0xbe,0x4d,0x4a,0xcc,0x9c,0x8c,0x92,0x94,0x78,0x57,0x71,0x25,0x6c,0xd1,0xd9,0x42,0xa9,0x0d,0x1b,0xd1,0xd2,0xdc,0xa3,0xea,0x84,0xef,0x7d,0x85,0xaf,0xe6,0x61,0x1f,0xb4,0x3f,0xf0,0xb7,0x41,0x26,0xd9,0x0a,0x6e,0x00,0x01,0x04,0x80,0xc7,0xc5,0xd9,0x27,0x09};

// 2015-11-20 -- Alice and Bob are live, and we're now IPv6 dual-stack!
//#define ZT_DEFAULT_WORLD_LENGTH 792
//static const unsigned char ZT_DEFAULT_WORLD[ZT_DEFAULT_WORLD_LENGTH] = {0x01,0x00,0x00,0x00,0x00,0x08,0xea,0xc9,0x0a,0x00,0x00,0x01,0x51,0x26,0x6f,0x7c,0x8a,0xb8,0xb3,0x88,0xa4,0x69,0x22,0x14,0x91,0xaa,0x9a,0xcd,0x66,0xcc,0x76,0x4c,0xde,0xfd,0x56,0x03,0x9f,0x10,0x67,0xae,0x15,0xe6,0x9c,0x6f,0xb4,0x2d,0x7b,0x55,0x33,0x0e,0x3f,0xda,0xac,0x52,0x9c,0x07,0x92,0xfd,0x73,0x40,0xa6,0xaa,0x21,0xab,0xa8,0xa4,0x89,0xfd,0xae,0xa4,0x4a,0x39,0xbf,0x2d,0x00,0x65,0x9a,0xc9,0xc8,0x18,0xeb,0xe8,0x0a,0xf5,0xbc,0xf8,0x3d,0x97,0xcd,0xc3,0xf8,0xe2,0x41,0x16,0x42,0x0f,0xc7,0x76,0x8e,0x07,0xf3,0x7e,0x9e,0x7d,0x1b,0xb3,0x23,0x21,0x79,0xce,0xb9,0xd0,0xcb,0xb5,0x94,0x7b,0x89,0x21,0x57,0x72,0xf6,0x70,0xa1,0xdd,0x67,0x38,0xcf,0x45,0x45,0xc2,0x8d,0x46,0xec,0x00,0x2c,0xe0,0x2a,0x63,0x3f,0x63,0x8d,0x33,0x08,0x51,0x07,0x77,0x81,0x5b,0x32,0x49,0xae,0x87,0x89,0xcf,0x31,0xaa,0x41,0xf1,0x52,0x97,0xdc,0xa2,0x55,0xe1,0x4a,0x6e,0x3c,0x04,0xf0,0x4f,0x8a,0x0e,0xe9,0xca,0xec,0x24,0x30,0x04,0x9d,0x21,0x90,0x39,0xf3,0x00,0x01,0xf0,0x92,0x2a,0x98,0xe3,0xb3,0x4e,0xbc,0xbf,0xf3,0x33,0x26,0x9d,0xc2,0x65,0xd7,0xa0,0x20,0xaa,0xb6,0x9d,0x72,0xbe,0x4d,0x4a,0xcc,0x9c,0x8c,0x92,0x94,0x78,0x57,0x71,0x25,0x6c,0xd1,0xd9,0x42,0xa9,0x0d,0x1b,0xd1,0xd2,0xdc,0xa3,0xea,0x84,0xef,0x7d,0x85,0xaf,0xe6,0x61,0x1f,0xb4,0x3f,0xf0,0xb7,0x41,0x26,0xd9,0x0a,0x6e,0x00,0x0c,0x04,0xbc,0xa6,0x5e,0xb1,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x02,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x7d,0x00,0x01,0x27,0x09,0x04,0x9a,0x42,0xc5,0x21,0x27,0x09,0x06,0x2c,0x0f,0xf8,0x50,0x01,0x54,0x01,0x97,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x27,0x09,0x04,0x9f,0xcb,0x61,0xab,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x08,0x00,0x00,0xa1,0x00,0x00,0x00,0x00,0x00,0x54,0x60,0x01,0x27,0x09,0x04,0xa9,0x39,0x8f,0x68,0x27,0x09,0x06,0x26,0x07,0xf0,0xd0,0x1d,0x01,0x00,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x27,0x09,0x04,0x6b,0xaa,0xc5,0x0e,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x00,0x01,0x00,0x20,0x00,0x00,0x00,0x00,0x02,0x00,0xe0,0x01,0x27,0x09,0x04,0x80,0xc7,0xc5,0xd9,0x27,0x09,0x06,0x24,0x00,0x61,0x80,0x00,0x00,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0xb7,0x40,0x01,0x27,0x09,0x88,0x41,0x40,0x8a,0x2e,0x00,0xbb,0x1d,0x31,0xf2,0xc3,0x23,0xe2,0x64,0xe9,0xe6,0x41,0x72,0xc1,0xa7,0x4f,0x77,0x89,0x95,0x55,0xed,0x10,0x75,0x1c,0xd5,0x6e,0x86,0x40,0x5c,0xde,0x11,0x8d,0x02,0xdf,0xfe,0x55,0x5d,0x46,0x2c,0xcf,0x6a,0x85,0xb5,0x63,0x1c,0x12,0x35,0x0c,0x8d,0x5d,0xc4,0x09,0xba,0x10,0xb9,0x02,0x5d,0x0f,0x44,0x5c,0xf4,0x49,0xd9,0x2b,0x1c,0x00,0x0c,0x04,0x2d,0x20,0xc6,0x82,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x64,0x00,0x81,0xc3,0x54,0x00,0x00,0xff,0xfe,0x18,0x1d,0x61,0x27,0x09,0x04,0x2e,0x65,0xa0,0xf9,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x03,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x6a,0x30,0x01,0x27,0x09,0x04,0x6b,0xbf,0x2e,0xd2,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x68,0x00,0x83,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x64,0x27,0x09,0x04,0x2d,0x20,0xf6,0xb3,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x58,0x00,0x8b,0xf8,0x54,0x00,0x00,0xff,0xfe,0x15,0xb3,0x9a,0x27,0x09,0x04,0x2d,0x20,0xf8,0x57,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x70,0x00,0x9b,0xc9,0x54,0x00,0x00,0xff,0xfe,0x15,0xc4,0xf5,0x27,0x09,0x04,0x9f,0xcb,0x02,0x9a,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x0c,0xad,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x26,0x70,0x01,0x27,0x09,0x7e,0x19,0x87,0x6a,0xba,0x00,0x2a,0x6e,0x2b,0x23,0x18,0x93,0x0f,0x60,0xeb,0x09,0x7f,0x70,0xd0,0xf4,0xb0,0x28,0xb2,0xcd,0x6d,0x3d,0x0c,0x63,0xc0,0x14,0xb9,0x03,0x9f,0xf3,0x53,0x90,0xe4,0x11,0x81,0xf2,0x16,0xfb,0x2e,0x6f,0xa8,0xd9,0x5c,0x1e,0xe9,0x66,0x71,0x56,0x41,0x19,0x05,0xc3,0xdc,0xcf,0xea,0x78,0xd8,0xc6,0xdf,0xaf,0xba,0x68,0x81,0x70,0xb3,0xfa,0x00,0x01,0x04,0xc6,0xc7,0x61,0xdc,0x27,0x09,0x8a,0xcf,0x05,0x9f,0xe3,0x00,0x48,0x2f,0x6e,0xe5,0xdf,0xe9,0x02,0x31,0x9b,0x41,0x9d,0xe5,0xbd,0xc7,0x65,0x20,0x9c,0x0e,0xcd,0xa3,0x8c,0x4d,0x6e,0x4f,0xcf,0x0d,0x33,0x65,0x83,0x98,0xb4,0x52,0x7d,0xcd,0x22,0xf9,0x31,0x12,0xfb,0x9b,0xef,0xd0,0x2f,0xd7,0x8b,0xf7,0x26,0x1b,0x33,0x3f,0xc1,0x05,0xd1,0x92,0xa6,0x23,0xca,0x9e,0x50,0xfc,0x60,0xb3,0x74,0xa5,0x00,0x01,0x04,0xa2,0xf3,0x4d,0x6f,0x27,0x09};

// 2015-12-17 -- Old New York root is dead, old SF still alive
//#define ZT_DEFAULT_WORLD_LENGTH 732
//static const unsigned char ZT_DEFAULT_WORLD[ZT_DEFAULT_WORLD_LENGTH] = {0x01,0x00,0x00,0x00,0x00,0x08,0xea,0xc9,0x0a,0x00,0x00,0x01,0x51,0xb1,0x7e,0x39,0x9d,0xb8,0xb3,0x88,0xa4,0x69,0x22,0x14,0x91,0xaa,0x9a,0xcd,0x66,0xcc,0x76,0x4c,0xde,0xfd,0x56,0x03,0x9f,0x10,0x67,0xae,0x15,0xe6,0x9c,0x6f,0xb4,0x2d,0x7b,0x55,0x33,0x0e,0x3f,0xda,0xac,0x52,0x9c,0x07,0x92,0xfd,0x73,0x40,0xa6,0xaa,0x21,0xab,0xa8,0xa4,0x89,0xfd,0xae,0xa4,0x4a,0x39,0xbf,0x2d,0x00,0x65,0x9a,0xc9,0xc8,0x18,0xeb,0x8a,0xca,0xf2,0x3d,0x71,0x2e,0xc2,0x39,0x45,0x66,0xb3,0xe9,0x39,0x79,0xb1,0x55,0xc4,0xa9,0xfc,0xbc,0xfc,0x55,0xaf,0x8a,0x2f,0x38,0xc8,0xcd,0xe9,0x02,0x5b,0x86,0xa9,0x72,0xf7,0x16,0x00,0x35,0xb7,0x84,0xc9,0xfc,0xe4,0xfa,0x96,0x8b,0xf4,0x1e,0xba,0x60,0x9f,0x85,0x14,0xc2,0x07,0x4b,0xfd,0xd1,0x6c,0x19,0x69,0xd3,0xf9,0x09,0x9c,0x9d,0xe3,0xb9,0x8f,0x11,0x78,0x71,0xa7,0x4a,0x05,0xd8,0xcc,0x60,0xa2,0x06,0x66,0x9f,0x47,0xc2,0x71,0xb8,0x54,0x80,0x9c,0x45,0x16,0x10,0xa9,0xd0,0xbd,0xf7,0x03,0x9d,0x21,0x90,0x39,0xf3,0x00,0x01,0xf0,0x92,0x2a,0x98,0xe3,0xb3,0x4e,0xbc,0xbf,0xf3,0x33,0x26,0x9d,0xc2,0x65,0xd7,0xa0,0x20,0xaa,0xb6,0x9d,0x72,0xbe,0x4d,0x4a,0xcc,0x9c,0x8c,0x92,0x94,0x78,0x57,0x71,0x25,0x6c,0xd1,0xd9,0x42,0xa9,0x0d,0x1b,0xd1,0xd2,0xdc,0xa3,0xea,0x84,0xef,0x7d,0x85,0xaf,0xe6,0x61,0x1f,0xb4,0x3f,0xf0,0xb7,0x41,0x26,0xd9,0x0a,0x6e,0x00,0x0c,0x04,0xbc,0xa6,0x5e,0xb1,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x02,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x7d,0x00,0x01,0x27,0x09,0x04,0x9a,0x42,0xc5,0x21,0x27,0x09,0x06,0x2c,0x0f,0xf8,0x50,0x01,0x54,0x01,0x97,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x27,0x09,0x04,0x9f,0xcb,0x61,0xab,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x08,0x00,0x00,0xa1,0x00,0x00,0x00,0x00,0x00,0x54,0x60,0x01,0x27,0x09,0x04,0xa9,0x39,0x8f,0x68,0x27,0x09,0x06,0x26,0x07,0xf0,0xd0,0x1d,0x01,0x00,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x27,0x09,0x04,0x6b,0xaa,0xc5,0x0e,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x00,0x01,0x00,0x20,0x00,0x00,0x00,0x00,0x02,0x00,0xe0,0x01,0x27,0x09,0x04,0x80,0xc7,0xc5,0xd9,0x27,0x09,0x06,0x24,0x00,0x61,0x80,0x00,0x00,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0xb7,0x40,0x01,0x27,0x09,0x88,0x41,0x40,0x8a,0x2e,0x00,0xbb,0x1d,0x31,0xf2,0xc3,0x23,0xe2,0x64,0xe9,0xe6,0x41,0x72,0xc1,0xa7,0x4f,0x77,0x89,0x95,0x55,0xed,0x10,0x75,0x1c,0xd5,0x6e,0x86,0x40,0x5c,0xde,0x11,0x8d,0x02,0xdf,0xfe,0x55,0x5d,0x46,0x2c,0xcf,0x6a,0x85,0xb5,0x63,0x1c,0x12,0x35,0x0c,0x8d,0x5d,0xc4,0x09,0xba,0x10,0xb9,0x02,0x5d,0x0f,0x44,0x5c,0xf4,0x49,0xd9,0x2b,0x1c,0x00,0x0c,0x04,0x2d,0x20,0xc6,0x82,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x64,0x00,0x81,0xc3,0x54,0x00,0x00,0xff,0xfe,0x18,0x1d,0x61,0x27,0x09,0x04,0x2e,0x65,0xa0,0xf9,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x03,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x6a,0x30,0x01,0x27,0x09,0x04,0x6b,0xbf,0x2e,0xd2,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x68,0x00,0x83,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x64,0x27,0x09,0x04,0x2d,0x20,0xf6,0xb3,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x58,0x00,0x8b,0xf8,0x54,0x00,0x00,0xff,0xfe,0x15,0xb3,0x9a,0x27,0x09,0x04,0x2d,0x20,0xf8,0x57,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x70,0x00,0x9b,0xc9,0x54,0x00,0x00,0xff,0xfe,0x15,0xc4,0xf5,0x27,0x09,0x04,0x9f,0xcb,0x02,0x9a,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x0c,0xad,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x26,0x70,0x01,0x27,0x09,0x7e,0x19,0x87,0x6a,0xba,0x00,0x2a,0x6e,0x2b,0x23,0x18,0x93,0x0f,0x60,0xeb,0x09,0x7f,0x70,0xd0,0xf4,0xb0,0x28,0xb2,0xcd,0x6d,0x3d,0x0c,0x63,0xc0,0x14,0xb9,0x03,0x9f,0xf3,0x53,0x90,0xe4,0x11,0x81,0xf2,0x16,0xfb,0x2e,0x6f,0xa8,0xd9,0x5c,0x1e,0xe9,0x66,0x71,0x56,0x41,0x19,0x05,0xc3,0xdc,0xcf,0xea,0x78,0xd8,0xc6,0xdf,0xaf,0xba,0x68,0x81,0x70,0xb3,0xfa,0x00,0x02,0x04,0xc6,0xc7,0x61,0xdc,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x00,0x01,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0xc5,0xf0,0x01,0x27,0x09};

// 2016-01-13 -- Old San Francisco 1.0.1 root is dead, now we're just on Alice and Bob!
#define ZT_DEFAULT_WORLD_LENGTH 634
static const unsigned char ZT_DEFAULT_WORLD[ZT_DEFAULT_WORLD_LENGTH] = {0x01,0x00,0x00,0x00,0x00,0x08,0xea,0xc9,0x0a,0x00,0x00,0x01,0x52,0x3c,0x32,0x50,0x1a,0xb8,0xb3,0x88,0xa4,0x69,0x22,0x14,0x91,0xaa,0x9a,0xcd,0x66,0xcc,0x76,0x4c,0xde,0xfd,0x56,0x03,0x9f,0x10,0x67,0xae,0x15,0xe6,0x9c,0x6f,0xb4,0x2d,0x7b,0x55,0x33,0x0e,0x3f,0xda,0xac,0x52,0x9c,0x07,0x92,0xfd,0x73,0x40,0xa6,0xaa,0x21,0xab,0xa8,0xa4,0x89,0xfd,0xae,0xa4,0x4a,0x39,0xbf,0x2d,0x00,0x65,0x9a,0xc9,0xc8,0x18,0xeb,0x4a,0xf7,0x86,0xa8,0x40,0xd6,0x52,0xea,0xae,0x9e,0x7a,0xbf,0x4c,0x97,0x66,0xab,0x2d,0x6f,0xaf,0xc9,0x2b,0x3a,0xff,0xed,0xd6,0x30,0x3e,0xc4,0x6a,0x65,0xf2,0xbd,0x83,0x52,0xf5,0x40,0xe9,0xcc,0x0d,0x6e,0x89,0x3f,0x9a,0xa0,0xb8,0xdf,0x42,0xd2,0x2f,0x84,0xe6,0x03,0x26,0x0f,0xa8,0xe3,0xcc,0x05,0x05,0x03,0xef,0x12,0x80,0x0d,0xce,0x3e,0xb6,0x58,0x3b,0x1f,0xa8,0xad,0xc7,0x25,0xf9,0x43,0x71,0xa7,0x5c,0x9a,0xc7,0xe1,0xa3,0xb8,0x88,0xd0,0x71,0x6c,0x94,0x99,0x73,0x41,0x0b,0x1b,0x48,0x84,0x02,0x9d,0x21,0x90,0x39,0xf3,0x00,0x01,0xf0,0x92,0x2a,0x98,0xe3,0xb3,0x4e,0xbc,0xbf,0xf3,0x33,0x26,0x9d,0xc2,0x65,0xd7,0xa0,0x20,0xaa,0xb6,0x9d,0x72,0xbe,0x4d,0x4a,0xcc,0x9c,0x8c,0x92,0x94,0x78,0x57,0x71,0x25,0x6c,0xd1,0xd9,0x42,0xa9,0x0d,0x1b,0xd1,0xd2,0xdc,0xa3,0xea,0x84,0xef,0x7d,0x85,0xaf,0xe6,0x61,0x1f,0xb4,0x3f,0xf0,0xb7,0x41,0x26,0xd9,0x0a,0x6e,0x00,0x0c,0x04,0xbc,0xa6,0x5e,0xb1,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x02,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x7d,0x00,0x01,0x27,0x09,0x04,0x9a,0x42,0xc5,0x21,0x27,0x09,0x06,0x2c,0x0f,0xf8,0x50,0x01,0x54,0x01,0x97,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x27,0x09,0x04,0x9f,0xcb,0x61,0xab,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x08,0x00,0x00,0xa1,0x00,0x00,0x00,0x00,0x00,0x54,0x60,0x01,0x27,0x09,0x04,0xa9,0x39,0x8f,0x68,0x27,0x09,0x06,0x26,0x07,0xf0,0xd0,0x1d,0x01,0x00,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x27,0x09,0x04,0x6b,0xaa,0xc5,0x0e,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x00,0x01,0x00,0x20,0x00,0x00,0x00,0x00,0x02,0x00,0xe0,0x01,0x27,0x09,0x04,0x80,0xc7,0xc5,0xd9,0x27,0x09,0x06,0x24,0x00,0x61,0x80,0x00,0x00,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0xb7,0x40,0x01,0x27,0x09,0x88,0x41,0x40,0x8a,0x2e,0x00,0xbb,0x1d,0x31,0xf2,0xc3,0x23,0xe2,0x64,0xe9,0xe6,0x41,0x72,0xc1,0xa7,0x4f,0x77,0x89,0x95,0x55,0xed,0x10,0x75,0x1c,0xd5,0x6e,0x86,0x40,0x5c,0xde,0x11,0x8d,0x02,0xdf,0xfe,0x55,0x5d,0x46,0x2c,0xcf,0x6a,0x85,0xb5,0x63,0x1c,0x12,0x35,0x0c,0x8d,0x5d,0xc4,0x09,0xba,0x10,0xb9,0x02,0x5d,0x0f,0x44,0x5c,0xf4,0x49,0xd9,0x2b,0x1c,0x00,0x0c,0x04,0x2d,0x20,0xc6,0x82,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x64,0x00,0x81,0xc3,0x54,0x00,0x00,0xff,0xfe,0x18,0x1d,0x61,0x27,0x09,0x04,0x2e,0x65,0xa0,0xf9,0x27,0x09,0x06,0x2a,0x03,0xb0,0xc0,0x00,0x03,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x6a,0x30,0x01,0x27,0x09,0x04,0x6b,0xbf,0x2e,0xd2,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x68,0x00,0x83,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x64,0x27,0x09,0x04,0x2d,0x20,0xf6,0xb3,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x58,0x00,0x8b,0xf8,0x54,0x00,0x00,0xff,0xfe,0x15,0xb3,0x9a,0x27,0x09,0x04,0x2d,0x20,0xf8,0x57,0x27,0x09,0x06,0x20,0x01,0x19,0xf0,0x70,0x00,0x9b,0xc9,0x54,0x00,0x00,0xff,0xfe,0x15,0xc4,0xf5,0x27,0x09,0x04,0x9f,0xcb,0x02,0x9a,0x27,0x09,0x06,0x26,0x04,0xa8,0x80,0x0c,0xad,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x26,0x70,0x01,0x27,0x09};

Topology::Topology(const RuntimeEnvironment *renv) :
	RR(renv),
	_trustedPathCount(0),
	_amRoot(false)
{
	// Get cached world if present
	std::string dsWorld(RR->node->dataStoreGet("world"));
	World cachedWorld;
	if (dsWorld.length() > 0) {
		try {
			Buffer<ZT_WORLD_MAX_SERIALIZED_LENGTH> dswtmp(dsWorld.data(),(unsigned int)dsWorld.length());
			cachedWorld.deserialize(dswtmp,0);
		} catch ( ... ) {
			cachedWorld = World(); // clear if cached world is invalid
		}
	}

	// Use default or cached world depending on which is shinier
	World defaultWorld;
	{
		Buffer<ZT_DEFAULT_WORLD_LENGTH> wtmp(ZT_DEFAULT_WORLD,ZT_DEFAULT_WORLD_LENGTH);
		defaultWorld.deserialize(wtmp,0); // throws on error, which would indicate a bad static variable up top
	}
	if (cachedWorld.shouldBeReplacedBy(defaultWorld,false)) {
		_setWorld(defaultWorld);
		if (dsWorld.length() > 0)
			RR->node->dataStoreDelete("world");
	} else _setWorld(cachedWorld);
}

Topology::~Topology()
{
}

SharedPtr<Peer> Topology::addPeer(const SharedPtr<Peer> &peer)
{
#ifdef ZT_TRACE
	if ((!peer)||(peer->address() == RR->identity.address())) {
		if (!peer)
			fprintf(stderr,"FATAL BUG: addPeer() caught attempt to add NULL peer" ZT_EOL_S);
		else fprintf(stderr,"FATAL BUG: addPeer() caught attempt to add peer for self" ZT_EOL_S);
		abort();
	}
#endif

	SharedPtr<Peer> np;
	{
		Mutex::Lock _l(_lock);
		SharedPtr<Peer> &hp = _peers[peer->address()];
		if (!hp)
			hp = peer;
		np = hp;
	}

	np->use(RR->node->now());
	saveIdentity(np->identity());

	return np;
}

SharedPtr<Peer> Topology::getPeer(const Address &zta)
{
	if (zta == RR->identity.address()) {
		TRACE("BUG: ignored attempt to getPeer() for self, returned NULL");
		return SharedPtr<Peer>();
	}

	{
		Mutex::Lock _l(_lock);
		const SharedPtr<Peer> *const ap = _peers.get(zta);
		if (ap) {
			(*ap)->use(RR->node->now());
			return *ap;
		}
	}

	try {
		Identity id(_getIdentity(zta));
		if (id) {
			SharedPtr<Peer> np(new Peer(RR,RR->identity,id));
			{
				Mutex::Lock _l(_lock);
				SharedPtr<Peer> &ap = _peers[zta];
				if (!ap)
					ap.swap(np);
				ap->use(RR->node->now());
				return ap;
			}
		}
	} catch ( ... ) {
		fprintf(stderr,"EXCEPTION in getPeer() part 2\n");
		abort();
	} // invalid identity on disk?

	return SharedPtr<Peer>();
}

Identity Topology::getIdentity(const Address &zta)
{
	if (zta == RR->identity.address()) {
		return RR->identity;
	} else {
		Mutex::Lock _l(_lock);
		const SharedPtr<Peer> *const ap = _peers.get(zta);
		if (ap)
			return (*ap)->identity();
	}
	return _getIdentity(zta);
}

void Topology::saveIdentity(const Identity &id)
{
	if (id) {
		char p[128];
		Utils::snprintf(p,sizeof(p),"iddb.d/%.10llx",(unsigned long long)id.address().toInt());
		RR->node->dataStorePut(p,id.toString(false),false);
	}
}

SharedPtr<Peer> Topology::getBestRoot(const Address *avoid,unsigned int avoidCount,bool strictAvoid)
{
	const uint64_t now = RR->node->now();
	Mutex::Lock _l(_lock);

	if (_amRoot) {
		/* If I am a root server, the "best" root server is the one whose address
		 * is numerically greater than mine (with wrap at top of list). This
		 * causes packets searching for a route to pretty much literally
		 * circumnavigate the globe rather than bouncing between just two. */

		for(unsigned long p=0;p<_rootAddresses.size();++p) {
			if (_rootAddresses[p] == RR->identity.address()) {
				for(unsigned long q=1;q<_rootAddresses.size();++q) {
					const SharedPtr<Peer> *const nextsn = _peers.get(_rootAddresses[(p + q) % _rootAddresses.size()]);
					if ((nextsn)&&((*nextsn)->hasActiveDirectPath(now))) {
						(*nextsn)->use(now);
						return *nextsn;
					}
				}
				break;
			}
		}

	} else {
		/* If I am not a root server, the best root server is the active one with
		 * the lowest quality score. (lower == better) */

		unsigned int bestQualityOverall = ~((unsigned int)0);
		unsigned int bestQualityNotAvoid = ~((unsigned int)0);
		const SharedPtr<Peer> *bestOverall = (const SharedPtr<Peer> *)0;
		const SharedPtr<Peer> *bestNotAvoid = (const SharedPtr<Peer> *)0;

		for(std::vector< SharedPtr<Peer> >::const_iterator r(_rootPeers.begin());r!=_rootPeers.end();++r) {
			bool avoiding = false;
			for(unsigned int i=0;i<avoidCount;++i) {
				if (avoid[i] == (*r)->address()) {
					avoiding = true;
					break;
				}
			}
			const unsigned int q = (*r)->relayQuality(now);
			if (q <= bestQualityOverall) {
				bestQualityOverall = q;
				bestOverall = &(*r);
			}
			if ((!avoiding)&&(q <= bestQualityNotAvoid)) {
				bestQualityNotAvoid = q;
				bestNotAvoid = &(*r);
			}
		}

		if (bestNotAvoid) {
			(*bestNotAvoid)->use(now);
			return *bestNotAvoid;
		} else if ((!strictAvoid)&&(bestOverall)) {
			(*bestOverall)->use(now);
			return *bestOverall;
		}

	}

	return SharedPtr<Peer>();
}

bool Topology::isUpstream(const Identity &id) const
{
	return isRoot(id);
}

bool Topology::worldUpdateIfValid(const World &newWorld)
{
	Mutex::Lock _l(_lock);
	if (_world.shouldBeReplacedBy(newWorld,true)) {
		_setWorld(newWorld);
		try {
			Buffer<ZT_WORLD_MAX_SERIALIZED_LENGTH> dswtmp;
			newWorld.serialize(dswtmp,false);
			RR->node->dataStorePut("world",dswtmp.data(),dswtmp.size(),false);
		} catch ( ... ) {
			RR->node->dataStoreDelete("world");
		}
		return true;
	}
	return false;
}

void Topology::clean(uint64_t now)
{
	Mutex::Lock _l(_lock);
	{
		Hashtable< Address,SharedPtr<Peer> >::Iterator i(_peers);
		Address *a = (Address *)0;
		SharedPtr<Peer> *p = (SharedPtr<Peer> *)0;
		while (i.next(a,p)) {
			if (((now - (*p)->lastUsed()) >= ZT_PEER_IN_MEMORY_EXPIRATION)&&(std::find(_rootAddresses.begin(),_rootAddresses.end(),*a) == _rootAddresses.end()))
				_peers.erase(*a);
		}
	}
	{
		Hashtable< Path::HashKey,SharedPtr<Path> >::Iterator i(_paths);
		Path::HashKey *k = (Path::HashKey *)0;
		SharedPtr<Path> *p = (SharedPtr<Path> *)0;
		while (i.next(k,p)) {
			if (p->reclaimIfWeak())
				_paths.erase(*k);
		}
	}
}

Identity Topology::_getIdentity(const Address &zta)
{
	char p[128];
	Utils::snprintf(p,sizeof(p),"iddb.d/%.10llx",(unsigned long long)zta.toInt());
	std::string ids(RR->node->dataStoreGet(p));
	if (ids.length() > 0) {
		try {
			return Identity(ids);
		} catch ( ... ) {} // ignore invalid IDs
	}
	return Identity();
}

void Topology::_setWorld(const World &newWorld)
{
	// assumed _lock is locked (or in constructor)
	_world = newWorld;
	_amRoot = false;
	_rootAddresses.clear();
	_rootPeers.clear();
	for(std::vector<World::Root>::const_iterator r(_world.roots().begin());r!=_world.roots().end();++r) {
		_rootAddresses.push_back(r->identity.address());
		if (r->identity.address() == RR->identity.address()) {
			_amRoot = true;
		} else {
			SharedPtr<Peer> *rp = _peers.get(r->identity.address());
			if (rp) {
				_rootPeers.push_back(*rp);
			} else {
				SharedPtr<Peer> newrp(new Peer(RR,RR->identity,r->identity));
				_peers.set(r->identity.address(),newrp);
				_rootPeers.push_back(newrp);
			}
		}
	}
}

} // namespace ZeroTier
