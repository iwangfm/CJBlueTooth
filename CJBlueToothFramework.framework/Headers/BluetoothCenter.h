//
//  BluetoothCenter.h
//  BluetoothDemo_Base
//
//  Created by 创建iMac_2017 on 9/5/2019.
//  Copyright © 2019 创健科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CJProgressReminder.h"
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface BluetoothCenter : NSObject

+(instancetype)shareInstance;

/*
 * Device Action Reminders
 */
@property (nonatomic, copy)void(^CJProgressReminderBlock)(ProgressReminderType progressReminder, NSString *message);
/*
 * Current connection device
 */
@property (nonatomic , strong) CBPeripheral * currentConnectedPer;
/*
 * Mobile Bluetooth status
 */
@property(nonatomic, copy)void(^CJCentralManagerCentralBlock)(CBCentralManager *central);
/*
 * Cancel Scan
 */
@property(nonatomic, copy)void(^CJCancelScanBlock)(CBCentralManager *centralManager);
/*
 * Search Discovery Device
 */
@property(nonatomic, copy)void(^CJDiscoverPeripheralsBlcok)(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI);
/*
 * Device Connection succeeded
 */
@property(nonatomic, copy)void(^CJConnectedPeripheralBlock)(CBCentralManager *central, CBPeripheral *peripheral);
/*
 * Device Connection Failed
 */
@property(nonatomic, copy)void(^CJFailToConnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);
/*
 * Device disconnected
 */
@property(nonatomic, copy)void(^CJDisConnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);
/*
 * Get the SN code
 */
@property(nonatomic, copy)void(^CJReadyForOperationBlock)(NSDictionary *dic);

/*
 * Turn off status reminders
 */
- (void)closeReminders;
/*
 * Set up bluetooth channel and prepare related protocols
 * If sn and mac both exist, search for the device
 * deviceNames is the name of device you want to search, when deviceNames = @[@"custom"]/nil, search for devices exist
 */
- (void)setupBlueToolWithChannel:(NSString *)channel sn:(NSString *)sn mac:(NSString *)mac deviceNames:(NSArray *)deviceNames;

/*
 * Start scan with no time limit
 */
- (void)startScan;
/*
 * Start scan with duration, default 30 seconds
 */
- (void)startScanWithDuration:(int)duration;
/*
 * Cancel scan
 */
- (void)cancelScan;
/*
 * Connect a device
 */
- (void)startConnectPeripheral:(CBPeripheral *)peripheral;
/*
 * Manual Disconnect Device
 */
- (void)cancelPeripheralConnection:(CBPeripheral *)peripheral;
/*
 * Manually disconnect all attached devices
 */
- (void)cancelAllPeripheralsConnection;
/*
 * Set up auto-connect, Foreground
 */
- (void)autoReconnectPeripheral:(CBPeripheral *)peripheral;
/*
 * Cancel auto-Connect
 */
- (void)autoReconnectCancelPeripheral:(CBPeripheral *)peripheral;


/*
 * Read SN
 */
- (void)readSNBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Read unit
 */
- (void)readUnitBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * SynchronizeTime
 */
- (void)synchronizeTimeBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Read time
 */
- (void)readTimeBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Real-time Measurement data
 */
- (void)testDataBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Read Multiple data
 */
- (void)readMultipleDataNumber:(float)number Block:(void(^)(NSDictionary *dataDic))block;
/*
 * Read historical data
 */
- (void)readHistoryBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Delete a piece of data, cant't delete GKI history
 */
- (void)commandDeleteSingleDataBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Delete all history data
 */
-(void)commandDeleteAllHistoryDataBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Get Device Message
 */
- (void)getDeviceMessageBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Read glucose concentration
 */
- (void)readGlucoseConcentrationBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Set glucose concentration
 */
- (void)setGlucoseConcentrationWithTargetMaxValue:(float)maxValue
                                         minValue:(float)minValue
                                            Block:(void(^)(NSDictionary *dataDic))block;
/*
 * Reading GKI historical data
 */
- (void)readGKIHistoryBlock:(void(^)(NSDictionary *dataDic))block;
/*
 * Other message
 * GKI mode, error message
 */
- (void)otherMessageBlock:(void(^)(NSDictionary *dataDic))block;
@end

NS_ASSUME_NONNULL_END
