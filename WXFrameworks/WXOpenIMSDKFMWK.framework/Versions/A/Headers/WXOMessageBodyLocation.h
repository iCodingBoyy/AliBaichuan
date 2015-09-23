//
//  WXOMessageBodyLocation.h
//  WXOpenIMSDK
//
//  Created by Jai Chen on 15/1/8.
//  Copyright (c) 2015年 taobao. All rights reserved.
//




/*********************************************************************************
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 
 * 注意点：所有WXO或者IWXO开头命名的类、接口、类型、常量等都已废弃，请使用YW或者IYW开头的定义 *
 
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 ********************************************************************************/






#import "YWMessageBodyLocation.h"
#import <MapKit/MapKit.h>

/**
 * 文本消息体
 */
__deprecated_msg("请使用YWMessageBodyLocation替代") @interface WXOMessageBodyLocation : YWMessageBodyLocation

/**
 *  地理位置
 */
@property (readonly, assign, nonatomic) CLLocationCoordinate2D location;
/**
 *  位置名称
 */
@property (readonly, copy, nonatomic) NSString *locationName;

/// 初始化
- (instancetype)initWithMessageLocation:(CLLocationCoordinate2D)location locationName:(NSString *)locationName;
@end
