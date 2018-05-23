//
//  CommonConstantsDefine.h
//  Yuesao
//
//  Created by apple on 16/5/10.
//  Copyright © 2016年 zhangjie. All rights reserved.
//

#ifndef CommonConstantsDefine_h
#define CommonConstantsDefine_h


//
//
//#define kCIAAppID  @"cdd188e1b6164cefb580e6e9348faedf"
//#define kCIAAppKey @"7bba6e514acd4864acbacea6d	db4de04"
//
//// 诸葛io
//#define ZHUGEIO_APPKEY          @"c69a963b9be849149fb280ca15619669"
//#define ZHUGEIO_SecretKey       @"026b7535976d4df9ac589ce6e84b886f"

// 个推
#define kGtAppId                       @"YUUdC100StAdCdkXewggI7"
#define kGtAppKey                      @"vGztD3M2Y06vhO3GPvarJ4"
#define kGtAppSecret                   @"1rOZgCFcFj6XKuTvPGTgC7"

//测试
#define AESKEY                              @"123456"
#define HUANXIN_APPKEY                      @"yunjiankang#medical"
#define HUANXIN_APNSCreName                 @"XHDoctor_Doctor_dev"
#define kRealmNameForAppStore               @"http://test.xhkhealth.com/"
#define kXHWAPLinkURL(pressureID,tokenStr) [@"http://test.xhkhealth.com/" stringByAppendingFormat:@"%@?token=%@", pressureID,tokenStr]


//线上
//#define AESKEY                         @"yiWPXxRz5g4pvaU0zAPgbA=="
//#define HUANXIN_APPKEY                 @"yunjiankang#xhdoctor"
////#define HUANXIN_APNSCreName            @"Doctor_dev"/
//#define HUANXIN_APNSCreName            @"Doctor_dis"//生产环境
//#define kRealmNameForAppStore          @"https://api.xhdoctor.com/"
//#define kXHWAPLinkURL(pressureID,tokenStr) [@"https://api.xhdoctor.com/" stringByAppendingFormat:@"%@?token=%@", pressureID,tokenStr]

// 当前版本号
#define TOYSTORE_CLIENT_VERSION @"1.4.1"
#define TOYSTORE_CLIENT_VERSION_CODE @"141"

#pragma mark - 域名

#define DATABASE_ERROR  ([[response objectOrNilForKey:@"return_code"] intValue] != 200000) // 数据库操作失败
#define SUCCESS_CODE    ([[response objectOrNilForKey:@"return_code"] intValue] == 200000) // 操作成功状态码
#define CallSUCCESS_CODE    ([[response objectOrNilForKey:@"return_code"] intValue] == 500001) // 操作成功状态码
#define REQUESTDATA     ([response objectOrNilForKey:@"data"])

#pragma mark - Requests Action

#pragma mark -
#pragma mark - 检测当前是否有新版本更新
#define kXHClientChectVersion          @"api/xh_client/check_version"
//打电话
#define kXHPhoneCallUser            @"101/doctor/call_user"

#define kXHPhoneCallAsstant            @"101/doctor/call_assistant"

//获取Banner数据
#define kXHClientBanner                @"102/articles/doctor_banner"
//获取5条数据
#define kXHClientHealthMessage         @"102/articles/less_medical_news"

//获取分页健康咨询
#define kDoctorHealthMessage         @"102/articles/medical_news"

// 获取登录验证码
#define kDoctorSendSMS                @"api/doctor/send_sms"

// 登录
#define kDoctorLogin                   @"api/doctor/login"

// 退出登录
#define kDoctorLogout                  @"api/doctor/logout"

// 根据token获取医生信息
#define kDoctorGetInfo                 @"api/doctor/getdoctorinfo"

// 新建医生纪录
#define kDoctorUpDataNote              @"api/doctor/update_note"

// 修改医生纪录
#define kDoctorModifyNote              @"api/doctor/modify_note"

// 删除医生纪录
#define kDoctorDeleteNote              @"api/doctor/delete_note"

// 获取医生纪录
//#define kDoctorGetNotes                @"101/doctor/get_notes"

// 获取医生的日程安排
#define kDoctorGetSchedule             @"101/doctor/getdoctor_schedule"

// 获取医助的日程
#define kDoctorGetAstantSchedule       @"101/doctor/getassistant_schedule"

// 修改医生的日程
#define kDoctorUpDataSchedule          @"101/doctor/modify_schedule"

// 添加医生的日程
#define kDoctorAddSchedule             @"101/doctor/update_schedule"

//删除医生日程
#define kDoctorDeleteschedule          @"101/doctor/delete_schedule"

// 获取血压分组
#define kUserDataGetBP                 @"api/doctor/get_user_bloodpressure"

// 血压值与等级换算
#define kXHClientBPLevelMap            @"api/xh_client/getbloodpressuremap"

// 心率与等级换算
#define kXHClientRateLevelMap          @"api/xh_client/getratelevelmap"

// 获取医生的会员列表
#define kDoctorGetUsers                @"api/doctor/getusers"

// 获取预约检记录
#define kDoctorGetyuyueBodyNote        @"api/doctor/get_examination_note"

// 获取转诊记录
#define kDoctorGetreferralNote          @"api/doctor/get_dcotor_referral_note"

// 获取用药指导的记录
#define kDoctorGetDosageNote            @"101/doctor/get_doctor_dosage_note"

// 获取预约面检记录
#define kDoctorGetyuyueFaceNote        @"api/doctor/get_diagnosis_note"

// 获取医助信息
#define kDoctorGetAssistant            @"api/doctor/getassistant"

// 获取医生联系人
#define kDoctorGetAssistantAndUsers    @"102/doctor/get_assistant_and_users"

// 使用api拨打用户电话
#define kDoctorMakePhoneCall            @"101/doctor/call_user"

// 使用api拨打助理电话
#define kDoctorCallToAssistant          @"101/doctor/call_assistant"

#pragma mark - 服务记录

//  按搜索条件查询服务记录(记录模块)
#define kDoctorSearchNote             @"102/service_record/doctor_service_record"

// 用药指导记录(记录模块)
#define kDoctorDosageGuide             @"102/service_record/doctor_dosage_guide"

// 获取预约面诊记录（记录模块）
#define kDoctorDiagnosisNote           @"102/service_record/doctor_diagnosis_note"

// 转诊记录（记录模块）
#define kDoctorReferralNote            @"102/service_record/doctor_referral_note"

// 预约体检记录（记录模块）
#define kDoctorExaminationNote         @"102/service_record/doctor_examination_note"

// 获取四种记录的天数
#define kDoctorRecordDays              @"102/service_record/doctor_record_days"

//获取记录的天数(会员头像)
#define kDoctorGetDayCountFromIcon      @"102/service_record/user_record_days"

//预约体检记录(会员头像)
#define kDoctorGetUserExaminationNoteFromIcon    @"102/service_record/user_examination_note"

// 预约面诊记录(会员头像)
#define kDoctorGetUserDiagnosisNoteFromIcon    @"102/service_record/user_diagnosis_note"

// 转诊记录(会员头像)
#define kDoctorGetUserReferralNoteFromIcon    @"102/service_record/user_referral_note"

// 用药指导(会员头像)
#define kDoctorGetUserDosageGuideFromIcon    @"102/service_record/user_dosage_guide"

// 按搜索条件查询服务记录(会员头像)
#define kDoctorGetUserSearchNoteFromIcon    @"102/service_record/user_service_record"

#pragma mark - 定时提醒
// 将用户从提醒列表里删除
#define kDoctorDeleteUserFromReminder       @"102/reminder/doctor/delete_user_from_reminder/"

// 创建定时提醒
#define kDoctorCreatReminder                @"102/reminder/doctor/creat_reminder"

// 删除定时提醒
#define kDoctorDeleteReminder               @"102/reminder/doctor/delete_reminder/"

// 获取提醒列表
#define kDoctorGetReminderList              @"102/reminder/doctor/get_reminder_list"

// 获取定时提醒的详情
#define kDoctorGetReminderDetail            @"102/reminder/doctor/get_reminder_detail/"

// 医生获取用户的提醒列表
#define kDoctorGetUserReminder              @"102/reminder/doctor/get_user_reminder/"

// 修改定时提醒
#define kDoctorUpdateReminder               @"102/reminder/doctor/update_reminder/"

#pragma mark - 记录
// 修改记录
#define kDoctorUpdateNote                   @"service_record/update_service/doctor_follow_up_update"

// 添加记录
#define kDoctorInsertNote                   @"service_record/add_service/doctor_follow_up"

// 获取记录列表
#define kDoctorGetNotes                     @"service_record/services/doctor_follow_up_list"

// 修改随访记录
#define kDoctorDeletesuifangNotes           @"service_record/delete_service/doctor_follow_up_delete"

// 修改体检记录
#define kDoctorUpdatetijianNotes           @"service_record/update_service/doctor_update_examination"

#define kDoctorUpdatequankeNotes           @"service_record/update_service/doctor_update_inquiry"

#define kDoctorUpdatejieduNotes            @"service_record/update_service/doctor_unscramble_report_update"

#define kDoctorUpdatesuifangNotes            @"service_record/update_service/doctor_follow_up_update"

#pragma mark - 文章

// 分页获取健康咨询
//#define kDoctorUpdateReminder               @"102/reminder/doctor/update_reminder/"
//
//// 医生版首页banner文章
//#define kDoctorUpdateReminder               @"102/reminder/doctor/update_reminder/"
//
//// 获取5条最新资讯api
//#define kDoctorUpdateReminder               @"102/reminder/doctor/update_reminder/"

#pragma mark - 系统消息
// 获取消息列表
#define kDoctorGetPush                      @"102/push/doctor/get_push"

// 获取最新的一条消息
#define kDoctorGetRecentPush                @"102/push/doctor/get_recent_push"

// 修改消息为已读
#define kDoctorUpdatePush                   @"102/push/doctor/update_push/"

#pragma mark - 医生日程
// 医生删除自己的日程
#define kDoctorDeleteDoctorSchedule         @"102/doctor/delete_doctor_schedule"

// 医生修改自己的日程
#define kDoctorModifyDoctorSchedule         @"102/doctor/modify_doctor_schedule"

// 医生创建自己的日程
#define kDoctorInsertDoctorSchedule         @"api/schedule/doctor_insert"

// 医生获取自己的日程列表
#define kDoctorGetDoctorSchedule            @"102/doctor/get_doctor_schedule"

#pragma mark - 医助日程
// 医生获取医助日程列表
#define kDoctorGetAssistantSchedule         @"102/doctor/get_assistant_schedule"

// 医生查看用户信息
#define kDoctorGetUserInfoDict              @"102/doctor/get_user_info"

// 医生获取会员的健康档案
#define kDoctorGetUserHealthFile            @"pages/user_health_records_for_doctor"

//获取最新的推送消息
#define kDoctorGetNewNofationMessage            @"102/push/doctor/get_recent_push"

#pragma mark - 健康数据
// 医生查看用户的健康数据列表（血糖）
#define kDoctorGetUserGlucoseList               @"102/doctor/get_user_glucose_list"

// 医生查看用户的健康数据列表（血氧）
#define kDoctorGetUserOxygenList                @"102/doctor/get_user_oxygen_list"

// 医生查看用户的健康数据列表（血压）
#define kDoctorGetUserBloodpressureList         @"102/doctor/get_user_bloodpressure_list"

// 录入用户血压数据
#define kDoctorInsertUserBloodPressure          @"102/doctor/insert_user_bloodpressure"

// 录入用户血糖数据
#define kDoctorInsertUserGlucose                @"102/doctor/insert_user_glucose"

// 录入用户血氧数据
#define kDoctorInsertUserOxygen                 @"102/doctor/insert_user_oxygen"

// 获取用户血糖历史数据(折线图)
#define kDoctorGetUserGlucoseHistory            @"api/userdata/get_user_glucose_history"

// 获取用户血压历史数据(折线图)
#define kDoctorGetUserBlodPressureHistory       @"api/userdata/get_user_blodpressure_history"

//标签 医生获取标签列表
#define kDoctorGetAllTags                       @"label/label/doctor_get_label"

//标签 获取会员的标签列表
#define kDoctorGetUserTags                      @"label/label/show_user_label"

//标签 会员标签的添加修改
#define kDoctorEditUserTags                     @"label/label/creat_user_label"

// 根据标签和其他属性搜索用户
#define kDoctorGetUserByClass                   @"label/user/doctor/get_users_by_class"



// 医生获取医助和会员的聊天列表
#define kDoctorGetChatNoteList                   @"chat/chatlist/doctor_chatlist"

// 医生获取聊天的详细内容
#define kDoctorGetChatNoteDetail                 @"chat/chatlist/doctor_chatlist_detail"

// 医生发起反馈建议
#define kDoctorReturnFeedBack                   @"feedback/feedback/doctor_insert_feedback"

// 医生端获取用户的套餐内容
#define kXHGetUserServicePlanInfo               @"service/service_plans/doctor_service_plan"

#define  kXHGetUserServiceLog                   @"service_record/services/doctor_services_record"

// 会员健康档案
// 家族史
#define kDoctorFamilyhistory                    @"health_record/record/doctor_familyhistory"

// 过敏史
#define kDoctorAllergyhistory                   @"health_record/record/doctor_allergyhistory"

// 饮酒史
#define kDoctorDrink                            @"health_record/record/doctor_drink"

// 吸烟史
#define kDoctorSmokinghistory                   @"health_record/record/doctor_smokinghistory"

// 心里状况
#define kDoctorPsychological                    @"health_record/record/doctor_psychological"

// 健康问题/主诉
#define kDoctorHealthQuestion                   @"health_record/record/doctor_health_question"

// 疾病手术史
#define kDoctorDiseasehistory                   @"health_record/record/doctor_diseasehistory"

// 膳食调查
#define kDoctorDietcondition                    @"health_record/record/doctor_dietcondition"

// 运动史
#define kDoctorSport                            @"health_record/record/doctor_sport"

// 睡眠状况
#define kDoctorSleep                            @"health_record/record/doctor_sleep"

// 其他问卷
#define kDoctorQuestionnaire                    @"health_record/record/doctor_questionnaire"

    
// 编辑用户的随访重点
#define kDoctorModifyUserFollowUpFocus          @"102/doctor/modify_user_follow_up_focus"

// 获取用户的随访重点
#define kDoctorGetUserFollowUpFocus              @"102/doctor/get_user_follow_up_focus"

// 编辑用户的主要健康状况
#define kDoctorGetModifyUserHealthStatus         @"102/doctor/modify_user_health_status"

// 获取用户的主要健康状况
#define kDoctorGetUserHealthStatus               @"102/doctor/get_user_health_status"

// 服务进度
#define kDoctorServicesSchedule                  @"service_record/services/doctor_services_schedule"

#pragma mark -
#pragma mark - 服务记录
// 医生端添加全科问诊
#define kDoctorAddInquiry                        @"service_record/add_service/doctor_add_inquiry"
// 接口名称 医生端-添加体检记录
#define kDoctorAddExamination                    @"service_record/add_service/doctor_add_examination"
// 接口名称 添加随访记录
#define kDoctorAddFollowUp                       @"service_record/add_service/doctor_follow_up"
// 接口名称 添加解读报告记录
#define kDoctorAddUnscrambleReport               @"service_record/add_service/doctor_unscramble_report"


#define kDoctorGetTijianPDF                  @"service_record/services/doctor_examination_pdf"

#define kDoctorGetGanYuPDF                   @"service_record/services/doctor_health_pdf"

#pragma mark -
#pragma mark - 赔付记录
// 赔付额度接口
#define kDoctorCompensationAmount            @"compensation_record/compensation/doctor_compensation_amount"

// 删除赔付记录接口
#define kDoctorCompensationDelete            @"compensation_record/compensation/doctor_compensation_delete"

// 获取赔付额度详情列表数据
#define kDoctorCompensationList              @"compensation_record/compensation/doctor_compensation_list"

// 添加牙科赔付记录
#define kDoctorAddDental                     @"compensation_record/compensation/doctor_add_dental"

// 添加门诊赔付记录
#define kDoctorAddOutpatient                 @"compensation_record/compensation/doctor_add_outpatient"

// 添加生育赔付记录
#define kDoctorAddFertility                  @"compensation_record/compensation/doctor_add_fertility"

// 添加住院赔付记录
#define kDoctorAddHospital                   @"compensation_record/compensation/doctor_add_hospital"




#endif /* CommonConstantsDefine_h */
