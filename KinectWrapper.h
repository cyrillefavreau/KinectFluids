/*
 * Kinect Fluids - Based on NVIDIA CUDA SDK example
 * Copyright (C) 2011-2012 Cyrille Favreau <cyrille_favreau@hotmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Author: Cyrille Favreau <cyrille_favreau@hotmail.com>
 *
 */

#pragma once

#include <windows.h>
#include <nuiapi.h>

struct Float3 
{
   float x,y,z;
};

class KinectWrapper
{

public:

   KinectWrapper(void);
   ~KinectWrapper(void);

public:

   void  initialize();
   BYTE* getDepthFrame();
   BYTE* getVideoFrame();
   bool  getSkeletonPositions(Float3* positions);
   
public:
   void  DepthToWorld(int x, int y, int depthValue, float& rx, float& ry, float& rz);
   float RawDepthToMeters(int depthValue);

   RGBQUAD KinNuiShortToQuadDepth( USHORT s );

private:

   int                m_mouse_x;
   int                m_mouse_y;

   HANDLE             m_skeletons;
   HANDLE             m_hNextDepthFrameEvent; 
   HANDLE             m_hNextVideoFrameEvent;
   HANDLE             m_hNextSkeletonEvent;
   HANDLE             m_pVideoStreamHandle;
   HANDLE             m_pDepthStreamHandle;
   NUI_SKELETON_FRAME m_skeletonFrame;
};

