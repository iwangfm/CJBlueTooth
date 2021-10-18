//
//  BluetoothTool.h
//  BluetoothDemo_Base
//
//  Created by 创建iMac_2017 on 14/5/2019.
//  Copyright © 2019 创健科技. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BluetoothTool : NSObject

+ (NSString *)macString:(NSDictionary *)advData;

+ (NSString *)snString:(NSDictionary *)advData;

/*
 All sampleSate come from protocols, the gki value is considered to be a provision.
 11 blood glucose
 12 GKI mode of blood glucose
 22 blood glucose control solutin
 23 GKI mode of blood glucose control solutin
 55 blood ketone
 56 GKI mode of blood ketone
 57 GKI value
 66 blood ketone control solutin
 67 GKI mode of blood ketone control solutin
 33 error
 */
+ (NSString *)getDataTypeWithSampleSate:(NSString *)sampleSate;

+ (BOOL)isComplianceSampleSate:(NSString *)sampleSate;
+ (BOOL)isBloodKetoneSampleSate:(NSString *)sampleSate;
@end


NS_ASSUME_NONNULL_END
