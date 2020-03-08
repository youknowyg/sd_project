/**
 * Copyright (C) 2017, dominic
 * All rights reserved.
 * @file DefinedCANMessage.h
 * @brief 对CAN报文信息进行宏定义
 *
 * 获取与ICU相关的CAN报文，方便进行编程
 * 注：宏定义的命名规则中涉及字母缩写简称是采用"_"加以区分，其他的采用单词首字母大写。
 *
 * @author dominic email:1021258016@qq.com
 * @version 1.0.0.0
 */

//ID278 defined with EMS transmite message
#define EngineSpeed_RPM			(can_rx[ID278].data[0].pp << 8 | can_rx[ID278].data[1].pp)	/**< (8,16) */
#define Error_EngineSpeedSigna	(can_rx[ID278].data[4].bit.p0)						/**< (32,1) */

//ID281 defined with EMS transmite message
#define EngineCoolantTemperature				can_rx[ID281].data[0].pp				/**< (0,8) */
#define FuelConsumptionInst						can_rx[ID281].data[2].pp				/**< (16,8) */
#define Error_EngineCoolantTemperature			can_rx[ID281].data[3].bit.p2			/**< (26,1) */
#define EOBD_MIL_LampSignal						can_rx[ID281].data[3].bit.p3			/**< (27,1) */
#define Engine_EPC_LampSignal					can_rx[ID281].data[3].bit.p4			/**< (28,1) */
#define EMS_SSWarningLampSts					(can_rx[ID281].data[4].pp & 0x03)			/**< (32,2) 预留部分 */
#define EMS_IdleStopStatus						can_rx[ID281].data[4].bit.p2			/**< (34,1) 预留部分 */
#define TargetVehicleSpeedforCruiseControl		can_rx[ID281].data[5].pp				/**< (40,8) */
#define EMS_CruiseCtrlSt						(can_rx[ID281].data[6].pp & 0x03)			/**< (48,2) */

//ID1A0 defined when TCU transmite message
#define St_TCU_Fault		(can_rx[ID1A0].data[0].pp & 0x03)			/**< (0,2) */
#define St_gearLeverPos		(can_rx[ID1A0].data[1].pp & 0x0F)			/**< (8,4) */
#define St_driveMode		((can_rx[ID1A0].data[4].pp & 0x1C) >> 2)	/**< (34,3) */
#define St_GearBoxOverHeat	can_rx[ID1A0].data[6].bit.p0			/**< (48,1) */
#define St_GearBoxEPReq		can_rx[ID1A0].data[6].bit.p7			/**< (53,1) */


//ID1A3 defined with GSM message
#define RockerArmMotor	(can_rx[ID1A3].data[4].pp & 0x03)		/**< (32,2) */

//defined with ABS message
//ID311 
#define VehicleSpeedVSOSigValidData		can_rx[ID311].data[1].bit.p0	/**< (8,1) */
#define EBD_Fault			can_rx[ID311].data[3].bit.p0		/**< (24,1) */
#define ABS_Fault			can_rx[ID311].data[3].bit.p1		/**< (25,1) */
#define VehicleSpeedVSOSig	((can_rx[ID311].data[4].pp << 8 | can_rx[ID311].data[5].pp & 0xF8) >> 3)	/**< (43,13) */
//ID2EA
#define DiagSessionStatus		can_rx[ID2EA].data[1].bit.p0		/**< (8,1) */
#define WssRL_EdgesSumValidData	can_rx[ID2EA].data[3].bit.p2		/**< (26,1) */
#define WssRR_EdgesSumValidData	can_rx[ID2EA].data[3].bit.p1		/**< (25,1) */
#define WssRL_EdgesSum			(can_rx[ID2EA].data[4].pp << 8 | can_rx[ID2EA].data[5].pp)	/**< (40,16) */
#define WssRR_EdgesSum			(can_rx[ID2EA].data[6].pp << 8 | can_rx[ID2EA].data[7].pp)	/**< (56,16) */

//defined with ESP message
//ID211
#define ESP_LampActive		can_rx[ID211].data[0].bit.p0			/**< (0,1) */
#define ESP_Off_PALA_Lamp	can_rx[ID211].data[0].bit.p2			/**< (2,1) */
#define MessageCounter		(can_rx[ID211].data[0].pp >> 4)			/**< (4,4) */
#define ESP_LampFault		can_rx[ID211].data[1].bit.p0			/**< (8,1) */

//defined with EPB transmite message
//ID320
#define EPB_Status			((can_rx[ID320].data[0].pp & 0x60) >> 5)	/**< (5,2) */
#define EPB_ParkingStatus	((can_rx[ID320].data[0].pp & 0x18) >> 3) 	/**< (3,2) */
#define EPB_Fault			can_rx[ID320].data[0].bit.p2			/**< (2,1) */


//defined with PEPS transmite message
//ID58B
#define PEPS_PepsICUAlarm	(can_rx[ID58B].data[2].pp >> 4)	/**< (20,4) */
//ID51D
#define PIN1		can_rx[ID51D].data[0].pp		/**< (0,8) */ 
#define PIN2		can_rx[ID51D].data[1].pp		/**< (8,8) */
#define PIN3		can_rx[ID51D].data[2].pp		/**< (16,8) */ 
#define PIN4		can_rx[ID51D].data[3].pp		/**< (24,8) */
#define random1		can_rx[ID51D].data[4].pp		/**< (32,8) */
#define random2		can_rx[ID51D].data[5].pp		/**< (40,8) */
#define random3		can_rx[ID51D].data[6].pp		/**< (48,8) */
#define random4		can_rx[ID51D].data[7].pp		/**< (56,8) */


//defined ALS transmite message
//ID3E1
#define AlarmMode	(can_rx[ID3E1].data[0].pp & 0x03)		/**< (0,2) */


//defined SRS transmite message
//ID31D
#define AirBagFailSts	(can_rx[ID31D].data[0].pp & 0x03)				/**< (0,2) */
#define RollingCounter	((can_rx[ID31D].data[0].pp & 0x3C) >> 2)		/**< (2,4) */
#define CheckSum		(can_rx[ID31D].data[7].pp & 0x0F)				/**< (56,4) */


//defined PDC transmite message
//ID525
#define FFLPDC_Distance		(can_rx[ID525].data[0].pp & 0x1F)		/**< (0,5) 前左雷达距离及状态 */
#define FSLPDC_Distance		(can_rx[ID525].data[1].pp & 0x1F)		/**< (8,5) 前左中雷达距离及状态 */
#define FSRPDC_Distance		(can_rx[ID525].data[2].pp & 0x1F)		/**< (16,5) 前右中雷达距离及状态 */
#define FFRPDC_Distance		(can_rx[ID525].data[3].pp & 0x1F)		/**< (24,5) 前右雷达距离及状态 */
#define RFLPDC_Distance		(can_rx[ID525].data[4].pp & 0x1F)		/**< (32,5) 后左雷达距离及状态 */
#define RSLPDC_Distance		(can_rx[ID525].data[5].pp & 0x1F)		/**< (40,5) 后左中雷达距离及状态 */
#define RSRPDC_Distance		(can_rx[ID525].data[6].pp & 0x1F)		/**< (48,5) 后右中雷达距离及状态 */
#define RFRPDC_Distance		(can_rx[ID525].data[7].pp & 0x1F)		/**< (56,5) 后右雷达距离及状态 */
#define PAS_SW			can_rx[ID525].data[0].bit.p5			/**< (5,1) 泊车辅助系统开闭位,1-开启,0-关闭 */
#define PDC_SysSts		(can_rx[ID525].data[0].pp >> 6)	/**< (6,2) 泊车辅助系统状态信息,1-开启，0-关闭，2-系统错误 */
#define FPDC_Warning	(can_rx[ID525].data[1].pp >> 5)	/**< (13,3) */


//defined AVM transmite message
//ID428
#define LDW_ErrorStatus		can_rx[ID428].data[0].bit.p7	/**< (7,1) INVO智华(预留) */
#define LDW_AudioWarning	can_rx[ID428].data[1].bit.p4	/**< (12,1) INVO智华(预留) */
#define LDW_WorkStatus		(can_rx[ID428].data[1].pp >> 5)	/**< (13,3) INVO智华(预留) */


//defined DVD transmite message
//ID5A0
#define DVD5_KeyAC_SelectUint can_rx[ID5A0].data[3].p7		/**< (31,1) 温度单位:0-华氏度，1-摄氏度 */
//ID5A1
#define TimeHours		((can_rx[ID5A1].data[0].pp & 0xF8) >> 3)  /**< (3,5) */
#define TimeMinutes		(((can_rx[ID5A1].data[0].pp & 0x07) << 8 | can_rx[ID5A1].data[1].pp) >> 5)  /**< (13,6) */
#define TurnType		(can_rx[ID5A1].data[0].pp & 0x7H)		/**< (16,7) */
#define TimeSeconds		((can_rx[ID5A1].data[1].pp & 0x1F) << 1 | can_rx[ID5A1].data[2].bit.p7)		/**< (23,6) */
#define DVD_Active		can_rx[ID5A1].data[5].bit.p0		/**< (40,1) 导航信息激活显示 */
#define GuideType		(can_rx[ID5A1].data[5].bit.pp >> 3)	/**< (43,5) */
//ID5A2
#define TurnDistance	(can_rx[ID5A2].data[2].pp >> 4 |	can_rx[ID5A2].data[1].pp << 4 | can_rx[ID5A2].data[0] << 12)		/**< (20,20) */
#define DestDistance	(can_rx[ID5A2].data[4].pp | can_rx[ID5A2].data[3] << 8 | (can_rx[ID5A2].data[1] & 0x0F) << 16)	/**< (32,20) */
//ID5A5
#define DVD5_Towards		(can_rx[ID5A5].data[0] >> 4)		/**< (4,4) */
#define DVD5_ClockGuide		(can_rx[ID5A5].data[1] | (can_rx[ID5A5].data[0] & 0x0F) << 8)		/**< (8,12) */
#define DVD5_GuideType		(can_rx[ID5A5].data[2] & 0x03)	/**< (16,2) */

//defined the TPMS transmite message
//ID540
#define SignalStatus		can_rx[ID540].data[0].bit.p7		/**< (7,1) */
#define TirePosition		(can_rx[ID540].data[0].pp & 0x07)	/**< (0,3) */
#define LF_Pressure			can_rx[ID540].data[1].pp			/**< (8,8) */
#define RF_Pressure			can_rx[ID540].data[2].pp			/**< (16,8) */
#define RR_Pressure			can_rx[ID540].data[3].pp			/**< (24,8) */
#define LR_Pressure			can_rx[ID540].data[4].pp			/**< (32,8) */
#define TireTemperature		can_rx[ID540].data[5].pp			/**< (40,8) */
#define LF_PressureWarning		(can_rx[ID540].data[6].pp >> 5)				/**< (53,3) */
#define RF_PressureWarning		((can_rx[ID540].data[6].pp & 0x1C) >> 2)	/**< (50,3) */
#define RR_PressureWarning		(can_rx[ID540].data[7].pp >> 5)				/**< (61,3) */
#define LR_PressureWarning		((can_rx[ID540].data[7].pp & 0x1C) >> 2)	/**< (58,3) */
#define TemperatureWarning		can_rx[ID540].data[7].bit.p1			/**< (57,1) */
#define SystemWarning			can_rx[ID540].data[7].bit.p0			/**< (56,1) */


//defined the BCM transmite message
//ID392
#define KeyReminder				can_rx[ID392].data[0].bit.p3	/**< (3,1) */
#define TurnRightStatus			can_rx[ID392].data[0].bit.p4	/**< (4,1) */
#define TurnLeftStatus			can_rx[ID392].data[0].bit.p5	/**< (5,1) */
#define HazardStatus			can_rx[ID392].data[0].bit.p6	/**< (6,1) */
#define ParkingLightStatus		can_rx[ID392].data[0].bit.p7	/**< (7,1) */
#define HighBeamStatus			can_rx[ID392].data[1].bit.p0	/**< (8,1) */
#define DriverDoorStatus		can_rx[ID392].data[1].bit.p2	/**< (10,1) */
#define PassengerDoorStatus		can_rx[ID392].data[1].bit.p3	/**< (11,1) */
#define HoodStatus				can_rx[ID392].data[1].bit.p4	/**< (12,1) */
#define RearRightDoorStatus		can_rx[ID392].data[1].bit.p5	/**< (13,1) */
#define RearLeftDoorStatus		can_rx[ID392].data[1].bit.p6	/**< (14,1) */
#define BackDoorStatus			can_rx[ID392].data[1].bit.p7	/**< (15,1) */
#define RearFogStatus			can_rx[ID392].data[2].bit.p0	/**< (16,1) */
#define FrontFogStatus			can_rx[ID392].data[2].bit.p1	/**< (17,1) */
#define KeyPosition				((can_rx[ID392].data[2].pp & 0x18) >> 3)	/**< (19,2) */
#define DRL_Status				can_rx[ID392].data[2].bit.p7				/**< (23,1) */
#define ERR_STATE_RAIN_SENS		((can_rx[ID392].data[5].pp & 0x0C) >> 2)	/**< (42,2) */
#define ERR_STATE_LIGH_SENS		(can_rx[ID392].data[5].pp >> 6)			/**< (46,2) */

//define the ABCM transmite message
//ID393
#define ABCM_ICU_Indication			(can_rx[ID393].data[2].pp & 0x30) >> 4)		/**< (20,2) */
#define DSM_Stcolumn_Fault			can_rx[ID393].data[2].bit.p6		/**< (22,1) */
#define DSM_Stcolumn_Initialized	can_rx[ID393].data[2].bit.p7		/**< (23,1) 记忆系统初始化状态。0-未初始化，1-已初始化 */


/**
 * @brief Set_****(X)
 *
 * x必须与设置的函数的位数值匹配，若不匹配可能就会出错
 * @param[in] x  设置对应值 
*/
//defined the ICU transmite message
//ID431
#define Set_ParkBrake(x)			can_rx[ID431].data[0].bit.p0 = x
#define Set_Vacuum(x)				can_rx[ID431].data[0].bit.p1 = x
#define Set_AirFilter(x)			can_rx[ID431].data[0].bit.p2 = x
#define Set_BrakeFluildLevel(x)		can_rx[ID431].data[0].bit.p3 = x
#define Set_ICU_Fault(x)			can_rx[ID431].data[0].bit.p4 = x
#define Set_Reserved(x)				can_rx[ID431].data[0].bit.p5 = x
#define Set_AirbagAlarmLampStatus(x)		can_rx[ID431].data[0].pp = can_rx[ID431].data[0].pp & 0x3F | x << 6
#define Set_FuelVolume(x)					can_rx[ID431].data[1].pp = x
#define Set_TotalOdometer_km(x)				can_rx[ID431].data[4].pp = can_rx[ID431].data[4].pp & 0x0F | x << 4; can_rx[ID431].data[3].pp = x >> 4; can_rx[ID431].data[2].pp = x >> 12
#define Set_ReverseGearSwitch(x)			can_rx[ID431].data[4].bit.p3 = x
#define Set_NeutralGearSwitch(x)			can_rx[ID431].data[4].bit.p2 = x
#define Set_PassSeatBeltStatus(x)			can_rx[ID431].data[4].pp = can_rx[ID431].data[4].pp & 0xFC | x
#define Set_DriverSeatBeltStatus(x)			can_rx[ID431].data[5].pp = can_rx[ID431].data[5].pp & 0x3F | x << 6
#define Set_ReverseGearSwitchValidData(x)	can_rx[ID431].data[5].bit.p5 = x
#define Set_NeutralGearSwitchValidData(x)	can_rx[ID431].data[5].bit.p4 = x
#define Set_FuelAlarm(x)				can_rx[ID431].data[5].bit.p3 = x
#define Set_ChargeStatusLight(x)		can_rx[ID431].data[5].bit.p2 = x
#define Set_OilPressureLight(x)			can_rx[ID431].data[5].bit.p1 = x
#define Set_BackgrondLampSwitch(x)		can_rx[ID431].data[7].pp = can_rx[ID431].data[7].pp & 0xE0 | x << 5
