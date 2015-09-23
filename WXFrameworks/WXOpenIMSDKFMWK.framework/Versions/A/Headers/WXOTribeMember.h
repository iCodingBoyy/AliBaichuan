//
//  WXOTribeMember.h
//  WXOpenIMSDK
//
//  Created by Jai Chen on 15/1/19.
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






#import "YWTribeMember.h"

/**
 群成员角色类型
 */
typedef NS_ENUM(NSUInteger, WXOTribeMemberRoleDef) {
    /// 普通群成员
    WXOTribeMemberRoleNormal = YWTribeMemberRoleNormal,
    /// 群主
    WXOTribeMemberRoleOwner = YWTribeMemberRoleOwner,
};
#define WXOTribeMemberRole      YWTribeMemberRole


/**
 *  群成员对象
 */
__deprecated_msg("请使用YWTribeMember替代") @interface WXOTribeMember : YWTribeMember

/**
 *  群成员角色类型
 */
@property (readonly, nonatomic) WXOTribeMemberRole role;

@end
