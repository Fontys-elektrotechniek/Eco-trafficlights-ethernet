///////////////////////////////////////////////////////////////////////////
//  Product/Project : Trafficlights-ethernet                             //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Main.c
//  Version      : 1.0
//  Description  : This is the boiler-plate code for your project
//
//  Author       : Jim Clermonts
//  Target       : Cerebot 32MX4 (PIC32MX460L512F)
//  Compiler     : MPLAB C Compiler for PIC32
//  IDE          : MPLAB X IDE Beta5.0
//  Programmer   : SKDE PIC32
//  Last Updated : 14-04-2012
//
//  Copyright (c) Fontys 2012.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
//
///////////////////////////////////////////////////////////////////////////

#define SET_FUSES_CEREBOT32MX4

#include "TCPIP Stack/TCPIP.h"
#include "Main.h"
#include "Cerebot.h"

// Declare AppConfig structure and some other supporting stack variables
APP_CONFIG AppConfig;
DWORD dwLastIP = 0;

int main(void)
{
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    InitalizeCrossroadIO();
    InitializeUART();
    INTEnableInterrupts();
    WriteString("*** running traffic-ethernet ***\r\n");
    InitializeBoard();

    // Initialize stack-related hardware components that may be
    // required by the UART configuration routines
    TickInit();
#if defined(STACK_USE_MPFS) || defined(STACK_USE_MPFS2)
    MPFSInit();
#endif

    // Initialize Stack and application related NV variables into AppConfig.
    InitAppConfig();

    // Initialize core stack layers (MAC, ARP, TCP, UDP) and
    // application modules (HTTP, SNMP, etc.)
    StackInit();

    // Now that all items are initialized, begin the co-operative
    // multitasking loop.  This infinite loop will continuously
    // execute all stack-related tasks, as well as your own
    // application's functions.  
    // Note that this is a "co-operative mult-tasking" mechanism
    // where every task performs its tasks (whether all in one shot
    // or part of it) and returns so that other tasks can do their
    // job.
    // If a task needs very long time to do its job, it must be broken
    // down into smaller pieces so that other tasks can have CPU time.
    while (1)
    {
        BlinkLed1();
        CheckForButtonPressed();
        // This task performs normal stack task including checking
        // for incoming packet, type of packet and calling
        // appropriate stack entity to process it.
        StackTask();
        // This tasks invokes each of the core stack application tasks
        StackApplications();
        ProcessIO();
        WriteString("*** Testing UART ***\r\n");
        CheckIfIPChanged();
    }
}

