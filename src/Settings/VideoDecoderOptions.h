/****************************************************************************
*
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once


enum VideoDecoderOptions {
    ForceVideoDecoderDefault = 0,
    ForceVideoDecoderSoftware,
    ForceVideoDecoderNVIDIA,
    ForceVideoDecoderVAAPI,
    ForceVideoDecoderDirectX3D,
    ForceVideoDecoderVideoToolbox,
};
