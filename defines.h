/*
 * Kinect Fluids
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

#ifndef DEFINES_H
#define DEFINES_H

#ifdef __DEVICE_EMULATION__
#define DIM    64        // Square size of solver domain
#else
#define DIMX  512       // Square size of solver domain
#define DIMY  512       // Square size of solver domain
#endif
#define DS    (DIMX*DIMY)  // Total domain size
#define CPADW (DIMX/2+1)  // Padded width for real->complex in-place FFT
#define RPADW (2*(DIMX/2+1))  // Padded width for real->complex in-place FFT
#define PDS   (DIMX*CPADW) // Padded total domain size

#define DT     0.09f     // Delta T for interative solver
#define VIS    0.0025f   // Viscosity constant
#define FORCE (5.8f*DIMX) // Force scale factor 
#define FR     4         // Force update radius

#define TILEX 64 // Tile width
#define TILEY 64 // Tile height
#define TIDSX 64 // Tids in X
#define TIDSY 4  // Tids in Y

#define gKinectVideoWidth  640
#define gKinectVideoHeight 480
#define gKinectVideo       4

#define gKinectDepthWidth  320
#define gKinectDepthHeight 240
#define gKinectDepth       2

#endif
