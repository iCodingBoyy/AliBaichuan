//
//  WXOMessageBodyCustomize.h
//  WXOpenIMSDK
//
//  Created by 慕桥(黄玉坤) on 1/15/15.
//  Copyright (c) 2015 taobao. All rights reserved.
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





#import "YWMessageBodyCustomize.h"

__deprecated_msg("请使用YWMessageBodyCustomize替代") @interface WXOMessageBodyCustomize : YWMessageBodyCustomize

/// 自定义数据
@property (nonatomic, strong, readonly) NSString *content;

/// 推送穿透内容
@property (nonatomic, strong, readonly) NSString *summary;

/// 初始化
- (instancetype)initWithMessageCustomizeContent:(NSString *)content summary:(NSString *)summary;
@end
