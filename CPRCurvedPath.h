/*
 *  CPRCurvedPath.h
 *  OsiriX
 *
 *  Created by Joël Spaltenstein on 10/14/10.
 *  Copyright 2010 OsiriX Team. All rights reserved.
 *
 */

#import "CPRGeometry.h"

@class CPRMutableBezierPath;
@class CPRVolumeData;
@class DICOMExport;

// all points in the CurvedPath live in patient space
// in order to avoid confusion about what coordinate space things are in all methods take points in an arbitrary coordinate
// space and take the transform from that space to the patient space

typedef uint32_t CPRCurvedPathControlToken;

extern const int32_t CPRCurvedPathControlTokenNone;

// CPRCurved path is all the data related to a CPR. All the transitory UI stuff is in CPRDisplayInfo

@interface CPRCurvedPath : NSObject <NSCopying, NSCoding>
{
    CPRMutableBezierPath *_bezierPath;
    NSMutableArray *_nodes;
    NSMutableArray *_nodeRelativePositions; // NSNumbers with a cache of the nodes' relative positions;
    
    CPRVector _initialNormal;
    CGFloat _thickness;
    CGFloat _transverseSectionSpacing;
    CGFloat _transverseSectionPosition;
}

+ (BOOL)controlTokenIsNode:(CPRCurvedPathControlToken)token;
+ (NSInteger)nodeIndexForToken:(CPRCurvedPathControlToken)token;

- (id)init;

- (void)addNode:(NSPoint)point transform:(CPRAffineTransform3D)transform; // adds the point to z = 0 in the arbitrary coordinate space
- (void)insertNodeAtRelativePosition:(CGFloat)relativePosition;
- (void)removeNodeAtIndex:(NSInteger)index;

- (void)moveControlToken:(CPRCurvedPathControlToken)token toPoint:(NSPoint)point transform:(CPRAffineTransform3D)transform; // resets Z by default

- (CPRCurvedPathControlToken)controlTokenNearPoint:(NSPoint)point transform:(CPRAffineTransform3D)transform;

- (CGFloat)relativePositionForPoint:(NSPoint)point transform:(CPRAffineTransform3D)transform;
- (CGFloat)relativePositionForPoint:(NSPoint)point transform:(CPRAffineTransform3D)transform distanceToPoint:(CGFloat *)distance; // returns the distance the coordinate space of point (screen coordinates)
- (CGFloat)relativePositionForControlToken:(CPRCurvedPathControlToken)token;
- (CGFloat)relativePositionForNodeAtIndex:(NSUInteger)nodeIndex;

@property (nonatomic, readonly, retain) CPRMutableBezierPath *bezierPath;
@property (nonatomic, readwrite, assign) CGFloat thickness;
@property (nonatomic, readwrite, assign) CPRVector initialNormal;
@property (nonatomic, readwrite, assign) CGFloat transverseSectionSpacing; // in mm
@property (nonatomic, readwrite, assign) CGFloat transverseSectionPosition; // as a relative position [0, 1] pass -1 if you don't want the trasvers section to appear
@property (nonatomic, readonly, assign) CGFloat leftTransverseSectionPosition;
@property (nonatomic, readonly, assign) CGFloat rightTransverseSectionPosition;
@property (readonly, copy) NSArray* nodes; // CPRVectors stored in NSValues


@end