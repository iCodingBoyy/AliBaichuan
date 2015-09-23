//
//  YWBaseBubbleViewModel.h
//  Messenger
//
//  Created by 慕桥(黄玉坤) on 12/3/14.
//
//

#import <Foundation/Foundation.h>
#import "YWBaseBubbleChatView.h"

@interface YWBaseBubbleViewModel : NSObject
{
    NSUInteger _layout;
    NSData *_backgroundImage;
    NSData *_highLightBGImage;
}

/// 期望展示的气泡样式
@property (nonatomic, assign) BubbleStyle bubbleStyle;

/// 消息内容供应方，用于显示“消息来源”
@property (nonatomic, strong) NSString *ownerName;

/// ViewModel对应的bubbleView
@property (nonatomic, weak) YWBaseBubbleChatView *bubbleView;

@end

/**
 *  气泡的布局
 */
typedef enum : NSUInteger {
    /// 居中
    WXOBubbleLayoutCenter,
    /// 居左
    WXOBubbleLayoutLeft,
    /// 居右
    WXOBubbleLayoutRight,
} WXOBubbleLayout;

/**
 *  如果BubbleStyle等于BubbleStyleCustomize时，你可以通过设置以下属性，来控制气泡的自定义显示
 */
@interface YWBaseBubbleViewModel(Customize)
/// 自定义气泡的布局方式(左|中|右)
@property (nonatomic, assign) WXOBubbleLayout layout;

/// 自定义气泡背景
@property (nonatomic, strong) NSData *backgroundImage;

/// 自定义高亮气泡背景
@property (nonatomic, strong) NSData *highLightBGImage;

/// 自定义气泡遮罩(不能和背景同时使用)，优先背景使用
@property (nonatomic, strong) NSData *maskImage;

/// 自定义高亮气泡遮罩(不能和背景同时使用)，优先背景使用
@property (nonatomic, strong) NSData *highLightMaskImage;

@end


