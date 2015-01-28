/**************************************************************************/
/*! 
  @file     DF_GPS.h
  @author   lisper (leyapin@gmail.com, lisper.li@gmail.com)
  @license  LGPLv3 (see license.txt) 

  parse gps gpgga protocol

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _DF_GPS
#define _DF_GPS

#include <Arduino.h>


typedef struct {
	struct utc{	//1:UTC time
		uint8_t hour;
		uint8_t minute;
		uint8_t second;
	}utc;
	double longitude;	//2:
	char ns;		//3:
	double satellites;	//4:
	char ew;		//5:
	uint8_t fix;	//6:gps status 0 1 2 3 4 5 6 7 8 9
	uint8_t num;	//7:
	double hdop;	//8:水平精度
	double altitude;	//9:海拔高度
	char a_units;	//10:单位M
	double level;	//11:大地水准面高度
	char l_units;	//12:单位M
	double diff_time;	//13:差分GPS数据期限(RTCM SC-104)，最后设立RTCM传送的秒数量，如不是差分定位则为空
	uint8_t diff_id;	//14:差分参考基站标号
} gpgga_s;

//
uint8_t decToInt2 (char *the_buf); 

//
uint8_t hexToInt2 (char *the_buf); 

// check sum using xor
uint8_t gps_checksum (char *array); 

//get gga checksum
uint8_t gps_read_checksum (char **the_str); 

//
uint8_t split_by_char (char *the_src, char the_char, char **the_des, uint8_t the_siz); 

//
uint8_t split_by_comma (char *the_src, char **the_des, uint8_t the_siz); 

//
//void gps_print_debug (char **the_strp, uint8_t the_leng); 

//
int gps_gpgga_parse (char* gps_string, gpgga_s *gpgga_data); 

#endif