//
//  WXOMessageBodyImage.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
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






#import "YWMessageBodyImage.h"

#define WXOGetImageProgressBlock        YWGetImageProgressBlock
#define WXOGetImageCompletionBlock      YWGetImageCompletionBlock


/**
 *  图片类型
 */
typedef NS_ENUM(NSUInteger, WXOMessageBodyImageTypeDef){
    /**
     *  普通静态图片
     */
    WXOMessageBodyImageTypeNormal = YWMessageBodyImageTypeNormal,
    /**
     *  GIF 动态图片
     */
    WXOMessageBodyImageTypeGIF = YWMessageBodyImageTypeGIF
};
#define WXOMessageBodyImageType     YWMessageBodyImageType


/**
 * 图片消息体
 */

__deprecated_msg("请使用YWMessageBodyImage替代") @interface WXOMessageBodyImage : YWMessageBodyImage

/// 初始化
- (instancetype)initWithMessageImage:(UIImage *)aMessageImage;

/**
 *  异步下载缩略图
 */
- (void)asyncGetThumbnailImageWithProgress:(WXOGetImageProgressBlock)progress
                                completion:(WXOGetImageCompletionBlock)completion;
/**
 *  异步下载大图
 */
- (void)asyncGetOriginalImageWithProgress:(WXOGetImageProgressBlock)progress
                                completion:(WXOGetImageCompletionBlock)completion;

/**
 *  缩略图尺寸
 */
@property (nonatomic, assign, readonly) CGSize thumbnailImageSize;


/**
 *  原始图片的类型，用于区分普通静态图片和 GIF 动态图片
 *  缩略图永远为静态图片
 */
@property (nonatomic, assign, readonly) WXOMessageBodyImageType originalImageType;

@end
