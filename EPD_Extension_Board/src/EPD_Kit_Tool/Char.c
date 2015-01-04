/**
* \file
*
* \brief The definition of ASCII characters
*
* Copyright (c) 2012-2014 Pervasive Displays Inc. All rights reserved.
*
*  Authors: Pervasive Displays Inc.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*  1. Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*  2. Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

const unsigned char ASCII_character_bitmaps[][8] = {
	{
		/* @0 '_' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @0 '!' (7 pixels wide) */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x10, /*    #     */
		~0x00  /*          */
	},
	{
		/* @10 '"' (7 pixels wide) */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @20 '#' (7 pixels wide) */
		~0x14, /*    # #   */
		~0x28, /*   # #    */
		~0x7C, /*  #####   */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x7C, /*  #####   */
		~0x28, /*   # #    */
		~0x50  /*  # #     */
	},
	{
		/* @30 '$' (7 pixels wide) */
		~0x10, /*    #     */
		~0x38, /*   ###    */
		~0x40, /*  #       */
		~0x30, /*   ##     */
		~0x08, /*     #    */
		~0x70, /*  ###     */
		~0x20, /*   #      */
		~0x20  /*   #      */
	},
	{
		/* @40 '%' (7 pixels wide) */
		~0x20, /*   #      */
		~0x50, /*  # #     */
		~0x20, /*   #      */
		~0x78, /*  ####    */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x10, /*    #     */
		~0x00  /*          */
	},
	{
		/* @50 '&' (7 pixels wide) */
		~0x00, /*          */
		~0x18, /*    ##    */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x58, /*  # ##    */
		~0x48, /*  #  #    */
		~0x3C, /*   ####   */
		~0x00  /*          */
	},
	{
		/* @60 ''' (7 pixels wide) */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @70 '(' (7 pixels wide) */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x08, /*     #    */
		~0x08  /*     #    */
	},
	{
		/* @80 ')' (7 pixels wide) */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x20, /*   #      */
		~0x20  /*   #      */
	},
	{
		/* @90 '*' (7 pixels wide) */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @100 '+' (7 pixels wide) */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x00  /*          */
	},
	{
		/* @110 ',' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x18, /*    ##    */
		~0x30, /*   ##     */
		~0x20  /*   #      */
	},
	{
		/* @120 '-' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x7C, /*  #####   */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @130 '.' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x30, /*   ##     */
		~0x00  /*          */
	},
	{
		/* @140 '/' (7 pixels wide) */
		~0x04, /*      #   */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x40  /*  #       */
	},
	{
		/* @150 '0' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @160 '1' (7 pixels wide) */
		~0x30, /*   ##     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @170 '2' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x20, /*   #      */
		~0x40, /*  #       */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @180 '3' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x04, /*      #   */
		~0x18, /*    ##    */
		~0x04, /*      #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @190 '4' (7 pixels wide) */
		~0x08, /*     #    */
		~0x18, /*    ##    */
		~0x28, /*   # #    */
		~0x48, /*  #  #    */
		~0x7C, /*  #####   */
		~0x08, /*     #    */
		~0x1C, /*    ###   */
		~0x00  /*          */
	},
	{
		/* @200 '5' (7 pixels wide) */
		~0x3C, /*   ####   */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x38, /*   ###    */
		~0x04, /*      #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @210 '6' (7 pixels wide) */
		~0x1C, /*    ###   */
		~0x20, /*   #      */
		~0x40, /*  #       */
		~0x78, /*  ####    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00, /*          */
	},
	{
		/* @220 '7' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x44, /*  #   #   */
		~0x04, /*      #   */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x00  /*          */
	},
	{
		/* @230 '8' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @240 '9' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x3C, /*   ####   */
		~0x04, /*      #   */
		~0x08, /*     #    */
		~0x70, /*  ###     */
		~0x00  /*          */
	},
	{
		/* @250 ':' (7 pixels wide) */
		~0x00, /*          */
		~0x30, /*   ##     */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x30, /*   ##     */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @260 ';' (7 pixels wide) */
		~0x00, /*          */
		~0x18, /*    ##    */
		~0x00, /*          */
		~0x00, /*          */
		~0x18, /*    ##    */
		~0x30, /*   ##     */
		~0x20, /*   #      */
		~0x00  /*          */
	},
	{
		/* @270 '<' (7 pixels wide) */
		~0x00, /*          */
		~0x04, /*      #   */
		~0x18, /*    ##    */
		~0x60, /*  ##      */
		~0x18, /*    ##    */
		~0x04, /*      #   */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @280 '=' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x7C, /*  #####   */
		~0x00, /*          */
		~0x7C, /*  #####   */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @290 '>' (7 pixels wide) */
		~0x00, /*          */
		~0x40, /*  #       */
		~0x30, /*   ##     */
		~0x0C, /*     ##   */
		~0x30, /*   ##     */
		~0x40, /*  #       */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @300 '?' (7 pixels wide) */
		~0x30, /*   ##     */
		~0x48, /*  #  #    */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x30, /*   ##     */
		~0x00  /*          */
	},
	{
		/* @310 '@' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x4C, /*  #  ##   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x4C, /*  #  ##   */
		~0x40, /*  #       */
		~0x3C  /*   ####   */
	},
	{
		/* @320 'A' (7 pixels wide) */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x00  /*          */
	},
	{
		/* @330 'B' (7 pixels wide) */
		(unsigned char)( ~0xF8),/* #####    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x78, /*  ####    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xF8),/* #####    */
		~0x00  /*          */
	},
	{
		/* @340 'C' (7 pixels wide) */
		~0x3C, /*   ####   */
		~0x44, /*  #   #   */
		~0x40, /*  #       */
		~0x40, /*  #       */
		~0x40, /*  #       */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @350 'D' (7 pixels wide) */
		(unsigned char)( ~0xF0),/* ####     */
		~0x48, /*  #  #    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x48, /*  #  #    */
		(unsigned char)( ~0xF0),/* ####     */
		~0x00  /*          */
	},
	{
		/* @360 'E' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x24, /*   #  #   */
		~0x20, /*   #      */
		~0x38, /*   ###    */
		~0x20, /*   #      */
		~0x24, /*   #  #   */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @370 'F' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x24, /*   #  #   */
		~0x20, /*   #      */
		~0x38, /*   ###    */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x70, /*  ###     */
		~0x00  /*          */
	},
	{
		/* @380 'G' (7 pixels wide) */
		~0x3C, /*   ####   */
		~0x44, /*  #   #   */
		~0x40, /*  #       */
		~0x40, /*  #       */
		~0x4E, /*  #  ###  */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @390 'H' (7 pixels wide) */
		(unsigned char)(~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x7C, /*  #####   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)(~0xEE),/* ### ###  */
		~0x00  /*          */
	},
	{
		/* @400 'I' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @410 'J' (7 pixels wide) */
		~0x3C, /*   ####   */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x48, /*  #  #    */
		~0x48, /*  #  #    */
		~0x30, /*   ##     */
		~0x00  /*          */
	},
	{
		/* @420 'K' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x48, /*  #  #    */
		~0x70, /*  ###     */
		~0x48, /*  #  #    */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xE6),/* ###  ##  */
		~0x00  /*          */
	},
	{
		/* @430 'L' (7 pixels wide) */
		~0x70, /*  ###     */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x24, /*   #  #   */
		~0x24, /*   #  #   */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @440 'M' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x6C, /*  ## ##   */
		~0x6C, /*  ## ##   */
		~0x54, /*  # # #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x00  /*          */
	},
	{
		/* @450 'N' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x64, /*  ##  #   */
		~0x64, /*  ##  #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x4C, /*  #  ##   */
		(unsigned char)(	~0xEC),/* ### ##   */
		~0x00  /*          */
	},
	{
		/* @460 'O' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @470 'P' (7 pixels wide) */
		~0x78, /*  ####    */
		~0x24, /*   #  #   */
		~0x24, /*   #  #   */
		~0x24, /*   #  #   */
		~0x38, /*   ###    */
		~0x20, /*   #      */
		~0x70, /*  ###     */
		~0x00  /*          */
	},
	{
		/* @480 'Q' (7 pixels wide) */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x1C  /*    ###   */
	},
	{
		/* @490 'R' (7 pixels wide) */
		~0x78, /*  ####    */
		~0x24, /*   #  #   */
		~0x24, /*   #  #   */
		~0x24, /*   #  #   */
		~0x38, /*   ###    */
		~0x24, /*   #  #   */
		~0x72, /*  ###  #  */
		~0x00  /*          */
	},
	{
		/* @500 'S' (7 pixels wide) */
		~0x34, /*   ## #   */
		~0x4C, /*  #  ##   */
		~0x40, /*  #       */
		~0x38, /*   ###    */
		~0x04, /*      #   */
		~0x44, /*  #   #   */
		~0x78, /*  ####    */
		~0x00  /*          */
	},
	{
		/* @510 'T' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x54, /*  # # #   */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @520 'U' (7 pixels wide) */
		(unsigned char)(	~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @530 'V' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x48, /*  #  #    */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x30, /*   ##     */
		~0x00  /*          */
	},
	{
		/* @540 'W' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x28, /*   # #    */
		~0x00  /*          */
	},
	{
		/* @550 'X' (7 pixels wide) */
		(unsigned char)( ~0xC6),/* ##   ##  */
		~0x44, /*  #   #   */
		~0x28, /*   # #    */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xC6),/* ##   ##  */
		~0x00  /*          */
	},
	{
		/* @560 'Y' (7 pixels wide) */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x28, /*   # #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @570 'Z' (7 pixels wide) */
		~0x7C, /*  #####   */
		~0x44, /*  #   #   */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x20, /*   #      */
		~0x44, /*  #   #   */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @580 '[' (7 pixels wide) */
		~0x18, /*    ##    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x18  /*    ##    */
	},
	{
		/* @590 '\' (7 pixels wide) */
		~0x40, /*  #       */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x08, /*     #    */
		~0x08  /*     #    */
	},
	{
		/* @600 ']' (7 pixels wide) */
		~0x30, /*   ##     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x30  /*   ##     */
	},
	{
		/* @610 '^' (7 pixels wide) */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x44, /*  #   #   */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @620 '_' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xFE) /* #######  */
	},
	{
		/* @630 '`' (7 pixels wide) */
		~0x20, /*   #      */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	},
	{
		/* @640 'a' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x3C, /*   ####   */
		~0x44, /*  #   #   */
		~0x7E, /*  ######  */
		~0x00  /*          */
	},
	{
		/* @650 'b' (7 pixels wide) */
		(unsigned char)( ~0xC0),/* ##       */
		~0x40, /*  #       */
		~0x58, /*  # ##    */
		~0x64, /*  ##  #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xF8),/* #####    */
		~0x00  /*          */
	},
	{
		/* @660 'c' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x3C, /*   ####   */
		~0x44, /*  #   #   */
		~0x40, /*  #       */
		~0x40, /*  #       */
		~0x3C, /*   ####   */
		~0x00  /*          */
	},
	{
		/* @670 'd' (7 pixels wide) */
		~0x0C, /*     ##   */
		~0x04, /*      #   */
		~0x34, /*   ## #   */
		~0x4C, /*  #  ##   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x3E, /*   #####  */
		~0x00  /*          */
	},
	{
		/* @680 'e' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x7C, /*  #####   */
		~0x40, /*  #       */
		~0x3C, /*   ####   */
		~0x00  /*          */
	},
	{
		/* @690 'f' (7 pixels wide) */
		~0x0C, /*     ##   */
		~0x10, /*    #     */
		~0x3C, /*   ####   */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x3C, /*   ####   */
		~0x00  /*          */
	},
	{
		/* @700 'g' (7 pixels wide) */
		~0x00, /*          */
		~0x36, /*   ## ##  */
		~0x4C, /*  #  ##   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x3C, /*   ####   */
		~0x04, /*      #   */
		~0x38  /*   ###    */
	},
	{
		/* @710 'h' (7 pixels wide) */
		(unsigned char)( ~0xC0),/* ##       */
		~0x40, /*  #       */
		~0x58, /*  # ##    */
		~0x64, /*  ##  #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x00  /*          */
	},
	{
		/* @720 'i' (7 pixels wide) */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x70, /*  ###     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @730 'j' (7 pixels wide) */
		~0x10, /*    #     */
		~0x00, /*          */
		~0x78, /*  ####    */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x08, /*     #    */
		~0x70  /*  ###     */
	},
	{
		/* @740 'k' (7 pixels wide) */
		(unsigned char)( ~0xC0),/* ##       */
		~0x40, /*  #       */
		~0x5C, /*  # ###   */
		~0x48, /*  #  #    */
		~0x70, /*  ###     */
		~0x48, /*  #  #    */
		(unsigned char)( ~0xDC),/* ## ###   */
		~0x00  /*          */
	},
	{
		/* @750 'l' (7 pixels wide) */
		~0x30, /*   ##     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @760 'm' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xE8),/* ### #    */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		(unsigned char)( ~0xFE),/* #######  */
		~0x00  /*          */
	},
	{
		/* @770 'n' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xD8),/* ## ##    */
		~0x64, /*  ##  #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x00  /*          */
	},
	{
		/* @780 'o' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x38, /*   ###    */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @790 'p' (7 pixels wide) */
		~0x00, /*          */
		(unsigned char)( ~0xD8),/* ## ##    */
		~0x64, /*  ##  #   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x78, /*  ####    */
		~0x40, /*  #       */
		(unsigned char)( ~0xE0) /* ###      */
	},
	{
		/* @800 'q' (7 pixels wide) */
		~0x00, /*          */
		~0x36, /*   ## ##  */
		~0x4C, /*  #  ##   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x3C, /*   ####   */
		~0x04, /*      #   */
		~0x0E  /*     ###  */
	},
	{
		/* @810 'r' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x6C, /*  ## ##   */
		~0x30, /*   ##     */
		~0x20, /*   #      */
		~0x20, /*   #      */
		~0x78, /*  ####    */
		~0x00  /*          */
	},
	{
		/* @820 's' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x3C, /*   ####   */
		~0x40, /*  #       */
		~0x38, /*   ###    */
		~0x04, /*      #   */
		~0x78, /*  ####    */
		~0x00  /*          */
	},
	{
		/* @830 't' (7 pixels wide) */
		~0x00, /*          */
		~0x40, /*  #       */
		(unsigned char)( ~0xF8),/* #####    */
		~0x40, /*  #       */
		~0x40, /*  #       */
		~0x44, /*  #   #   */
		~0x38, /*   ###    */
		~0x00  /*          */
	},
	{
		/* @840 'u' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xCC),/* ##  ##   */
		~0x44, /*  #   #   */
		~0x44, /*  #   #   */
		~0x4C, /*  #  ##   */
		~0x36, /*   ## ##  */
		~0x00  /*          */
	},
	{
		/* @850 'v' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x48, /*  #  #    */
		~0x28, /*   # #    */
		~0x30, /*   ##     */
		~0x00  /*          */
	},
	{
		/* @860 'w' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x54, /*  # # #   */
		~0x54, /*  # # #   */
		~0x28, /*   # #    */
		~0x00  /*          */
	},
	{
		/* @870 'x' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x6C, /*  ## ##   */
		~0x28, /*   # #    */
		~0x10, /*    #     */
		~0x28, /*   # #    */
		~0x6C, /*  ## ##   */
		~0x00  /*          */
	},
	{
		/* @880 'y' (7 pixels wide) */
		~0x00, /*          */
		(unsigned char)( ~0xEE),/* ### ###  */
		~0x44, /*  #   #   */
		~0x28, /*   # #    */
		~0x28, /*   # #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x70  /*  ###     */
	},
	{
		/* @890 'z' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x7C, /*  #####   */
		~0x48, /*  #  #    */
		~0x10, /*    #     */
		~0x24, /*   #  #   */
		~0x7C, /*  #####   */
		~0x00  /*          */
	},
	{
		/* @900 '{' (7 pixels wide) */
		~0x08, /*     #    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x30, /*   ##     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x08, /*     #    */
		~0x00  /*          */
	},
	{
		/* @910 '|' (7 pixels wide) */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x10  /*    #     */
	},
	{
		/* @920 '}' (7 pixels wide) */
		~0x20, /*   #      */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x18, /*    ##    */
		~0x10, /*    #     */
		~0x10, /*    #     */
		~0x20, /*   #      */
		~0x00  /*          */
	},
	{
		/* @930 '~' (7 pixels wide) */
		~0x00, /*          */
		~0x00, /*          */
		~0x00, /*          */
		~0x34, /*   ## #   */
		~0x58, /*  # ##    */
		~0x00, /*          */
		~0x00, /*          */
		~0x00  /*          */
	}
};
