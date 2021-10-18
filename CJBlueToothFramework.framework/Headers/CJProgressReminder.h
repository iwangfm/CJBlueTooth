//
//  CJProgressReminder.h
//  BluetoothDemo_Base
//
//  Created by 创建iMac_2017 on 16/5/2019.
//  Copyright © 2019 创健科技. All rights reserved.
//

#ifndef CJProgressReminder_h
#define CJProgressReminder_h

typedef NS_ENUM(NSUInteger, ProgressReminderType) {
    
    ProgressReminder_Defalut, //no message for progress
    ProgressReminder_Success, //success
    ProgressReminder_Error, //error
    ProgressReminder_Unsupported, //Unsupported instructions
    ProgressReminder_Unconnect, //device disconnected,please reconnected
    ProgressReminder_NoPermission, //this characteristic have no permission
    ProgressReminder_SynchronizeSucceed, //synchronize time succeed
    ProgressReminder_NoData, //no data
    ProgressReminder_AllDataDeleted, //delete history data succeed
    ProgressReminder_SingleDataDeleted, //delete single history data succeed
    ProgressReminder_InsertStrip, //please insert strip
    ProgressReminder_StripInserted, //Strip has been inserted
    ProgressReminder_AddBlood, //add blood
    ProgressReminder_Waiting, //waiting...
};

#endif /* CJProgressReminder_h */
