//
//  NotificationDefine.h
//
//  Created by apple on 16/8/15.
//  Copyright © 2016年 XH. All rights reserved.
//

#ifndef NotificationDefine_h
#define NotificationDefine_h

// 登录成功
#define kNOTIFICATION_LOGIN       @"kNotificationLogin"

// 退出登录
#define kNOTIFICATION_LOGOUT      @"kNotificationLogout"

// 推送通知
#define kNOTIFICATION_GETUINEWS     @"kNotificationGeTuiNews"

// 统计未登录
#define kNOTIFICATION_UnreadMessageCount   @"setupUnreadMessageCount"
//关闭打电话的页面
#define kNOTIFICATION_ClosePhoneCall   @"closecallView"

//当日程记录为空时清除小星星
#define kNOTIFICATION_reloadCalendarData   @"reloadCalendarData"

#define kAppDidReceiveResiveVideoNotifation       @"reciveVideo"

#define kNOTIFICATION_Contact  @"contact"

//当日程添加或者修改之后重新加载数据
#define kNOTIFICATION_UpdateCalendarData   @"upDateCalendarData"
#endif /* NotificationDefine_h */
