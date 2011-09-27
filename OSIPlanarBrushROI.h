/*=========================================================================
 Program:   OsiriX
 
 Copyright (c) OsiriX Team
 All rights reserved.
 Distributed under GNU - LGPL
 
 See http://www.osirix-viewer.com/copyright.html for details.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.
 =========================================================================*/

#import "OSIROI.h"
#import "OSIGeometry.h"

@class OSIROIMask;
@class ROI;

@interface OSIPlanarBrushROI : OSIROI
{
    ROI *_osiriXROI;
    
    OSIROIMask *_roiMask;
    OSIFloatVolumeData *_homeFloatVolumeData;
    N3Plane _plane;
    NSArray *_convexHull; // mask onto the _homeFloatVolumeData
}
@end