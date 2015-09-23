//
//  YWTribe.h
//
//
//  Created by Jai Chen on 15/1/13.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  群对象
 */
@interface YWTribe : NSObject<NSCoding>

/**
 *  群的唯一标识符
 */
@property (readonly, copy, nonatomic) NSString *tribeId;

/**
 *  群名称
 */
@property (readonly, copy, nonatomic) NSString *tribeName;

/**
 *  群公告
 */
@property (readonly, copy, nonatomic) NSString *notice;


- (BOOL)isEqualToTribe:(YWTribe *)tribe;

@end
