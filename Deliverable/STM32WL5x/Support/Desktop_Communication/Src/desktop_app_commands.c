/*
 * com_presentation_layer.c
 *
 *  Created on: Aug 28, 2023
 *      Author: kevinimlay
 */


#include <desktop_app_commands.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <uart_packet_helpers.h>


/* code_to_appActions
 *
 * Map char array command code to numerical code.  If no match is found,
 * NO_ACTION is returned.
 */
AppActions code_to_appActions(const char* code)
{
	// set calendar date/time
	if (!strncmp(code, SET_CALENDAR_DATETIME_CODE, UART_PACKET_HEADER_SIZE))
		return SET_CALENDAR_DATETIME;

	// get calendar date/time
	else if (!strncmp(code, GET_CALENDAR_DATETIME_CODE, UART_PACKET_HEADER_SIZE))
		return GET_CALENDAR_DATETIME;

	// add calendar event
	else if (!strncmp(code, ADD_CALENDAR_EVENT_CODE, UART_PACKET_HEADER_SIZE))
			return ADD_CALENDAR_EVENT;

	// get/view calendar event
	else if (!strncmp(code, GET_CALENDAR_EVENT_CODE, UART_PACKET_HEADER_SIZE))
			return GET_CALENDAR_EVENT;

	// remove calendar event
	else if (!strncmp(code, REMOVE_CALENDAR_EVENT_CODE, UART_PACKET_HEADER_SIZE))
			return REMOVE_CALENDAR_EVENT;

	// clear all calendar events
	else if (!strncmp(code, CLEAR_CALENDAR_EVENTS_CODE, UART_PACKET_HEADER_SIZE))
			return CLEAR_CALENDAR_EVENTS;

	// start calendar
	else if (!strncmp(code, START_CALENDAR_CODE, UART_PACKET_HEADER_SIZE))
			return START_CALENDAR;

	// invalid code
	else
		return NO_ACTION;
}


/* appActions_to_code
 *
 * Map numerical code to char array command code.  If no valid numerical
 * code is passed, NO_CODE is returned.
 */
const char* appActions_to_code(AppActions action)
{
	// set date/time
	if (SET_CALENDAR_DATETIME)
		return SET_CALENDAR_DATETIME_CODE;

	// get date/time
	else if (GET_CALENDAR_DATETIME)
		return GET_CALENDAR_DATETIME_CODE;

	// add calendar event
	else if (ADD_CALENDAR_EVENT)
		return ADD_CALENDAR_EVENT_CODE;

	// get/view calendar event
	else if (GET_CALENDAR_EVENT)
		return GET_CALENDAR_EVENT_CODE;

	// remove calendar event
	else if (REMOVE_CALENDAR_EVENT)
		return REMOVE_CALENDAR_EVENT_CODE;

	// clear all calendar events
	else if (CLEAR_CALENDAR_EVENTS)
		return CLEAR_CALENDAR_EVENTS_CODE;

	// start calendar
	else if (START_CALENDAR)
		return START_CALENDAR_CODE;

	// invalid code
	else
		return NO_CODE;
}


/* parseDateTime
 *
 * Parse a DateTime from a formatted string.  String formatting is:
 * "yy;mm;dd;hh;mm;ss".  No error checking is performed.
 */
bool parseDateTime(DateTime* dateTime, char data[UART_PACKET_PAYLOAD_SIZE])
{
	// parse values from string
	dateTime->year = atoi(data + sizeof(char) * 3 * 0);
	dateTime->month = atoi(data + sizeof(char) * 3 * 1);
	dateTime->day = atoi(data + sizeof(char) * 3 * 2);
	dateTime->hour = atoi(data + sizeof(char) * 3 * 3);
	dateTime->minute = atoi(data + sizeof(char) * 3 * 4);
	dateTime->second = atoi(data + sizeof(char) * 3 * 5);

	return true;
}


/* formatDateTime
 *
 * Format a string from a DateTime.  String formatting is:
 * "yy;mm;dd;hh;mm;ss".  No error checking is performed.
 */
bool formatDateTime(char data[UART_PACKET_PAYLOAD_SIZE], const DateTime* dateTime)
{
	int formatCount;

	// format values into string
	memset(data, 0, UART_PACKET_PAYLOAD_SIZE*sizeof(char));
	formatCount = snprintf(data, UART_PACKET_PAYLOAD_SIZE, "%02d;%02d;%02d;%02d;%02d;%02d",
			(int)(dateTime->year),
			(int)(dateTime->month),
			(int)(dateTime->day),
			(int)(dateTime->hour),
			(int)(dateTime->minute),
			(int)(dateTime->second));

	// if the resulting string is not longer than the packet payload size and there was no
	// error formatting, return true
	if (formatCount >= 0 && formatCount <= UART_PACKET_PAYLOAD_SIZE)
		return true;

	// else, return false
	else
		return false;
}


/* parseEvent
 *
 * Parse a CalendarEvent from a formatted string.  String formatting is:
 * "yy;mm;dd;hh;mm;ss;yy;mm;dd;hh;mm;ss".  No error checking is performed.
 */
bool parseEvent(CalendarEvent* event, char data[UART_PACKET_PAYLOAD_SIZE])
{
	// parse values from string
	event->start.year = atoi(data + sizeof(char) * 3 * 0);
	event->start.month = atoi(data + sizeof(char) * 3 * 1);
	event->start.day = atoi(data + sizeof(char) * 3 * 2);
	event->start.hour = atoi(data + sizeof(char) * 3 * 3);
	event->start.minute = atoi(data + sizeof(char) * 3 * 4);
	event->start.second = atoi(data + sizeof(char) * 3 * 5);
	event->end.year = atoi(data + sizeof(char) * 3 * 6);
	event->end.month = atoi(data + sizeof(char) * 3 * 7);
	event->end.day = atoi(data + sizeof(char) * 3 * 8);
	event->end.hour = atoi(data + sizeof(char) * 3 * 9);
	event->end.minute = atoi(data + sizeof(char) * 3 * 10);
	event->end.second = atoi(data + sizeof(char) * 3 * 11);

	return true;
}


/* formatEvent
 *
 * Format a string from a CalenderEvent.  String formatting is:
 * "yy;mm;dd;hh;mm;ss;yy;mm;dd;hh;mm;ss".  No error checking is performed.
 */
bool formatEvent(char data[UART_PACKET_PAYLOAD_SIZE], const CalendarEvent* event)
{
	int formatCount;

	// format values into string
	memset(data, 0, UART_PACKET_PAYLOAD_SIZE*sizeof(char));
	formatCount = snprintf(data, UART_PACKET_PAYLOAD_SIZE,
			"%02d;%02d;%02d;%02d;%02d;%02d;%02d;%02d;%02d;%02d;%02d;%02d",
			(int)(event->start.year),
			(int)(event->start.month),
			(int)(event->start.day),
			(int)(event->start.hour),
			(int)(event->start.minute),
			(int)(event->start.second),
			(int)(event->end.year),
			(int)(event->end.month),
			(int)(event->end.day),
			(int)(event->end.hour),
			(int)(event->end.minute),
			(int)(event->end.second));

	// if the resulting string is not longer than the packet payload size and there was no
	// error formatting, return true
	if (formatCount >= 0 && formatCount <= UART_PACKET_PAYLOAD_SIZE)
		return true;

	// else, return false
	else
		return false;
}
