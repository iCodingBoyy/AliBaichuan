//
//  WXOConversationViewController.h
//  testFreeOpenIM
//
//  Created by Jai Chen on 15/1/12.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "IYWUIServiceDef.h"

#import "YWMessageInputView.h"

@class YWConversation;
@class YWIMCore;
@class YWIMKit;


@interface YWConversationViewController : UIViewController
<UITableViewDataSource, UITableViewDelegate,
YWViewControllerEventProtocol>


/**
 *  创建消息列表Controller
 *  @param aIMKit IMKit对象
 *  @param aConversation 会话对象
 */
+ (instancetype)makeControllerWithIMKit:(YWIMKit *)aIMKit conversation:(YWConversation *)aConversation;

/**
 *  YWIMKit对象的弱引用
 */
@property (nonatomic, weak, readonly)   YWIMKit *kitRef;

/**
 *  会话对象
 */
@property (nonatomic, strong, readonly) YWConversation *conversation;

#pragma mark - for CustomUI

/// 输入框
@property (nonatomic, strong, readonly) YWMessageInputView *messageInputView;

/// 顶部自定义View
@property (nonatomic, strong) UIView *customTopView;

/**
 * 设置顶部自定义View及其显示和隐藏View
 * @param customTopView, 顶部自定义View
 * @param hideView, 可选，显示在customTopView下方，用户点击会触发收起customTopView，若为nil，customTopView将会一直显示
 * @param showView, 可选，用户点击展开customTopView，若为nil且hideView不为nil，则会使用hideView
 */
- (void)setCustomTopView:(UIView *)customTopView withOptionHideView:(UIView *)hideView andOptionShowView:(UIView *)showView;

/// 通过接口设置背景图片
@property (nonatomic, strong) UIImage *backgroundImage;


#pragma mark - 消息发送
/// 文本发送
- (void)sendTextMessage:(NSString *)text;

/* 图片发送 包含图片上传交互
 * @param image, 要发送的图片
 * @param useOriginImage, 是否强制发送原图
 */
- (void)sendImageMessage:(UIImage *)image;
- (void)sendImageMessageData:(NSData *)ImageData;


/// 语音发送
- (void)sendVoiceMessage:(NSData*)wavData andTime:(NSTimeInterval)nRecordingTime;

@end

