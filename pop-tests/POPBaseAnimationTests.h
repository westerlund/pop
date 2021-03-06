/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#define SENTEST_IGNORE_DEPRECATION_WARNING
#import <SenTestingKit/SenTestingKit.h>
#import "POPCGUtils.h"

@class CALayer;
@class POPAnimator;
@class POPAnimatableProperty;

@interface POPBaseAnimationTests : SenTestCase

// two layers for test use
@property (strong, nonatomic) CALayer *layer1, *layer2;

// the animator to use for rendering
@property (strong, nonatomic) POPAnimator *animator;

// the time tests began
@property (assign, nonatomic) CFTimeInterval beginTime;

// radius animatable property
@property (strong, nonatomic) POPAnimatableProperty *radiusProperty;

@end

// max frame count required for animations to converge
extern NSUInteger kPOPAnimationConvergenceMaxFrameCount;

// counts the number of events of value within epsilon, starting from end
extern NSUInteger POPAnimationCountLastEventValues(NSArray *events, NSNumber *value, float epsilon = 0);

// returns YES if array of value events contain specified value
extern BOOL POPAnimationEventsContainValue(NSArray *events, NSNumber *value);

// equality with epsilon
#define _EQLF_(x, y, epsilon) (fabsf ((x) - (y)) < epsilon)

// color equality assert
#define POPAssertColorEqual(c1, c2) \
{ \
  CGFloat v1[4], v2[4]; \
  POPCGColorGetRGBAComponents(c1, v1); \
  POPCGColorGetRGBAComponents(c2, v2); \
  STAssertTrue(_EQLF_(v1[0], v2[0], 1e-6) && _EQLF_(v1[1], v2[1], 1e-6) && _EQLF_(v1[2], v2[2], 1e-6) && _EQLF_(v1[3], v2[3], 1e-6), @"not equal color:[r:%f g:%f b:%f a:%f] color:[r:%f g:%f b:%f a:%f]", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]); \
}