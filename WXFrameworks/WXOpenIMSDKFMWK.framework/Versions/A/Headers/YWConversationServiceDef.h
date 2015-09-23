//
//  YWConversationServiceDef.h
//  
//
//  Created by huanglei on 14/12/18.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  收到新消息的回调
 *  @param aMessages 收到的新消息，数组中包含的对象都遵循 IYWMessage 协议，您可以直接访问 IYWMessage 中的方法
 */
typedef void(^YWConversationOnNewMessageBlock)(NSArray *aMessages);

/**
 *  收到新消息的回调
 *  @param aMessages 收到的新消息，数组中包含的对象都遵循 IYWMessage 协议，您可以直接访问 IYWMessage 中的方法
 *  @param aIsOffline 是否离线消息
 */
typedef void(^YWConversationOnNewMessageBlockV2)(NSArray *aMessages, BOOL aIsOffline);

/// 对象变更方式
typedef enum : NSUInteger {
    /// 对象被插入
    YWObjectChangeTypeInsert = 1,
    /// 对象被删除
    YWObjectChangeTypeDelete = 2,
    /// 对象被移动
    YWObjectChangeTypeMove = 3,
    /// 对象被修改
    YWObjectChangeTypeUpdate = 4
} YWObjectChangeType;


/**
 *  数据集发生变更的回调，用于变更前或者变更完成时
 */
typedef void (^YWContentChangeBlock)(void);
/**
 *  数据集变更的回调，用于变更过程。
 *  @param object 被变更的对象
 *  @param indexPath 对象原先的位置
 *  @param newIndexPath 对象的新位置
 *  @param type 变更的方式，参见： YWObjectChangeType。
 */
typedef void (^YWObjectChangeBlock)(id object, NSIndexPath *indexPath, YWObjectChangeType type, NSIndexPath *newIndexPath);

@interface YWConversationServiceDef : NSObject

@end
