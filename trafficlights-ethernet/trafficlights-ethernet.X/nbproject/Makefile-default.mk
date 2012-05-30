#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1295770447/Announce.o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o ${OBJECTDIR}/_ext/1295770447/ARP.o ${OBJECTDIR}/_ext/1295770447/AutoIP.o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o ${OBJECTDIR}/_ext/1295770447/BigInt.o ${OBJECTDIR}/_ext/1295770447/Delay.o ${OBJECTDIR}/_ext/1295770447/DHCP.o ${OBJECTDIR}/_ext/1295770447/DHCPs.o ${OBJECTDIR}/_ext/1295770447/DNS.o ${OBJECTDIR}/_ext/1295770447/DNSs.o ${OBJECTDIR}/_ext/1295770447/DynDNS.o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o ${OBJECTDIR}/_ext/1295770447/FileSystem.o ${OBJECTDIR}/_ext/1295770447/FTP.o ${OBJECTDIR}/_ext/1295770447/Hashes.o ${OBJECTDIR}/_ext/1295770447/Helpers.o ${OBJECTDIR}/_ext/1295770447/HTTP2.o ${OBJECTDIR}/_ext/1295770447/HTTP.o ${OBJECTDIR}/_ext/1295770447/ICMP.o ${OBJECTDIR}/_ext/1295770447/IP.o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o ${OBJECTDIR}/_ext/1295770447/MPFS.o ${OBJECTDIR}/_ext/1295770447/NBNS.o ${OBJECTDIR}/_ext/1295770447/Random.o ${OBJECTDIR}/_ext/1295770447/Reboot.o ${OBJECTDIR}/_ext/1295770447/RSA.o ${OBJECTDIR}/_ext/1295770447/SMTP.o ${OBJECTDIR}/_ext/1295770447/SNMP.o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o ${OBJECTDIR}/_ext/1295770447/SNTP.o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o ${OBJECTDIR}/_ext/1295770447/SSL.o ${OBJECTDIR}/_ext/1295770447/StackTsk.o ${OBJECTDIR}/_ext/1295770447/TCP.o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/Telnet.o ${OBJECTDIR}/_ext/1295770447/TFTPc.o ${OBJECTDIR}/_ext/1295770447/Tick.o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o ${OBJECTDIR}/_ext/1295770447/UART.o ${OBJECTDIR}/_ext/1295770447/UDP.o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ${OBJECTDIR}/_ext/1472/MPFSImg.o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Cerebot.o ${OBJECTDIR}/_ext/1295770447/MPFS2.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d ${OBJECTDIR}/_ext/1472/PingDemo.o.d ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d ${OBJECTDIR}/_ext/1472/UARTConfig.o.d ${OBJECTDIR}/_ext/1295770447/Announce.o.d ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d ${OBJECTDIR}/_ext/1295770447/ARP.o.d ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d ${OBJECTDIR}/_ext/1295770447/BigInt.o.d ${OBJECTDIR}/_ext/1295770447/Delay.o.d ${OBJECTDIR}/_ext/1295770447/DHCP.o.d ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d ${OBJECTDIR}/_ext/1295770447/DNS.o.d ${OBJECTDIR}/_ext/1295770447/DNSs.o.d ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d ${OBJECTDIR}/_ext/1295770447/FTP.o.d ${OBJECTDIR}/_ext/1295770447/Hashes.o.d ${OBJECTDIR}/_ext/1295770447/Helpers.o.d ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d ${OBJECTDIR}/_ext/1295770447/HTTP.o.d ${OBJECTDIR}/_ext/1295770447/ICMP.o.d ${OBJECTDIR}/_ext/1295770447/IP.o.d ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d ${OBJECTDIR}/_ext/1295770447/MPFS.o.d ${OBJECTDIR}/_ext/1295770447/NBNS.o.d ${OBJECTDIR}/_ext/1295770447/Random.o.d ${OBJECTDIR}/_ext/1295770447/Reboot.o.d ${OBJECTDIR}/_ext/1295770447/RSA.o.d ${OBJECTDIR}/_ext/1295770447/SMTP.o.d ${OBJECTDIR}/_ext/1295770447/SNMP.o.d ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d ${OBJECTDIR}/_ext/1295770447/SNTP.o.d ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d ${OBJECTDIR}/_ext/1295770447/SSL.o.d ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d ${OBJECTDIR}/_ext/1295770447/TCP.o.d ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d ${OBJECTDIR}/_ext/1295770447/Telnet.o.d ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d ${OBJECTDIR}/_ext/1295770447/Tick.o.d ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d ${OBJECTDIR}/_ext/1295770447/UART.o.d ${OBJECTDIR}/_ext/1295770447/UDP.o.d ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d ${OBJECTDIR}/_ext/1472/MPFSImg.o.d ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d ${OBJECTDIR}/_ext/1472/Main.o.d ${OBJECTDIR}/_ext/1472/Cerebot.o.d ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1295770447/Announce.o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o ${OBJECTDIR}/_ext/1295770447/ARP.o ${OBJECTDIR}/_ext/1295770447/AutoIP.o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o ${OBJECTDIR}/_ext/1295770447/BigInt.o ${OBJECTDIR}/_ext/1295770447/Delay.o ${OBJECTDIR}/_ext/1295770447/DHCP.o ${OBJECTDIR}/_ext/1295770447/DHCPs.o ${OBJECTDIR}/_ext/1295770447/DNS.o ${OBJECTDIR}/_ext/1295770447/DNSs.o ${OBJECTDIR}/_ext/1295770447/DynDNS.o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o ${OBJECTDIR}/_ext/1295770447/FileSystem.o ${OBJECTDIR}/_ext/1295770447/FTP.o ${OBJECTDIR}/_ext/1295770447/Hashes.o ${OBJECTDIR}/_ext/1295770447/Helpers.o ${OBJECTDIR}/_ext/1295770447/HTTP2.o ${OBJECTDIR}/_ext/1295770447/HTTP.o ${OBJECTDIR}/_ext/1295770447/ICMP.o ${OBJECTDIR}/_ext/1295770447/IP.o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o ${OBJECTDIR}/_ext/1295770447/MPFS.o ${OBJECTDIR}/_ext/1295770447/NBNS.o ${OBJECTDIR}/_ext/1295770447/Random.o ${OBJECTDIR}/_ext/1295770447/Reboot.o ${OBJECTDIR}/_ext/1295770447/RSA.o ${OBJECTDIR}/_ext/1295770447/SMTP.o ${OBJECTDIR}/_ext/1295770447/SNMP.o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o ${OBJECTDIR}/_ext/1295770447/SNTP.o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o ${OBJECTDIR}/_ext/1295770447/SSL.o ${OBJECTDIR}/_ext/1295770447/StackTsk.o ${OBJECTDIR}/_ext/1295770447/TCP.o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/Telnet.o ${OBJECTDIR}/_ext/1295770447/TFTPc.o ${OBJECTDIR}/_ext/1295770447/Tick.o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o ${OBJECTDIR}/_ext/1295770447/UART.o ${OBJECTDIR}/_ext/1295770447/UDP.o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ${OBJECTDIR}/_ext/1472/MPFSImg.o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Cerebot.o ${OBJECTDIR}/_ext/1295770447/MPFS2.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o: ../../Microchip/TCPIP\ Stack/BigInt_helper_C32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.ok ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d" "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d" -t $(SILENT) -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d"  -o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o "../../Microchip/TCPIP Stack/BigInt_helper_C32.S"  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d",--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PIC32MXSK=1,-I".."
	
else
${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o: ../../Microchip/TCPIP\ Stack/BigInt_helper_C32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.ok ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d" "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d" -t $(SILENT) -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d"  -o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o "../../Microchip/TCPIP Stack/BigInt_helper_C32.S"  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d",--gdwarf-2,-I".."
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ../BerkeleyTCPClientDemo.c  
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ../BerkeleyTCPServerDemo.c  
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ../BerkeleyUDPClientDemo.c  
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ../GenericTCPClient.c  
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ../GenericTCPServer.c  
	
${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o: ../LegacyHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ../LegacyHTTPApp.c  
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d" -o ${OBJECTDIR}/_ext/1472/PingDemo.o ../PingDemo.c  
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ../SMTPDemo.c  
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" -o ${OBJECTDIR}/_ext/1472/UARTConfig.o ../UARTConfig.c  
	
${OBJECTDIR}/_ext/1295770447/Announce.o: ../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Announce.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Announce.o.d" -o ${OBJECTDIR}/_ext/1295770447/Announce.o "../../Microchip/TCPIP Stack/Announce.c"  
	
${OBJECTDIR}/_ext/1295770447/ARCFOUR.o: ../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o "../../Microchip/TCPIP Stack/ARCFOUR.c"  
	
${OBJECTDIR}/_ext/1295770447/ARP.o: ../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARP.o "../../Microchip/TCPIP Stack/ARP.c"  
	
${OBJECTDIR}/_ext/1295770447/AutoIP.o: ../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" -o ${OBJECTDIR}/_ext/1295770447/AutoIP.o "../../Microchip/TCPIP Stack/AutoIP.c"  
	
${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o: ../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o "../../Microchip/TCPIP Stack/BerkeleyAPI.c"  
	
${OBJECTDIR}/_ext/1295770447/BigInt.o: ../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" -o ${OBJECTDIR}/_ext/1295770447/BigInt.o "../../Microchip/TCPIP Stack/BigInt.c"  
	
${OBJECTDIR}/_ext/1295770447/Delay.o: ../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Delay.o.d" -o ${OBJECTDIR}/_ext/1295770447/Delay.o "../../Microchip/TCPIP Stack/Delay.c"  
	
${OBJECTDIR}/_ext/1295770447/DHCP.o: ../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCP.o "../../Microchip/TCPIP Stack/DHCP.c"  
	
${OBJECTDIR}/_ext/1295770447/DHCPs.o: ../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCPs.o "../../Microchip/TCPIP Stack/DHCPs.c"  
	
${OBJECTDIR}/_ext/1295770447/DNS.o: ../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNS.o "../../Microchip/TCPIP Stack/DNS.c"  
	
${OBJECTDIR}/_ext/1295770447/DNSs.o: ../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNSs.o "../../Microchip/TCPIP Stack/DNSs.c"  
	
${OBJECTDIR}/_ext/1295770447/DynDNS.o: ../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DynDNS.o "../../Microchip/TCPIP Stack/DynDNS.c"  
	
${OBJECTDIR}/_ext/1295770447/ENC28J60.o: ../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o "../../Microchip/TCPIP Stack/ENC28J60.c"  
	
${OBJECTDIR}/_ext/1295770447/ENCX24J600.o: ../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o "../../Microchip/TCPIP Stack/ENCX24J600.c"  
	
${OBJECTDIR}/_ext/1295770447/FileSystem.o: ../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" -o ${OBJECTDIR}/_ext/1295770447/FileSystem.o "../../Microchip/TCPIP Stack/FileSystem.c"  
	
${OBJECTDIR}/_ext/1295770447/FTP.o: ../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/FTP.o "../../Microchip/TCPIP Stack/FTP.c"  
	
${OBJECTDIR}/_ext/1295770447/Hashes.o: ../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" -o ${OBJECTDIR}/_ext/1295770447/Hashes.o "../../Microchip/TCPIP Stack/Hashes.c"  
	
${OBJECTDIR}/_ext/1295770447/Helpers.o: ../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" -o ${OBJECTDIR}/_ext/1295770447/Helpers.o "../../Microchip/TCPIP Stack/Helpers.c"  
	
${OBJECTDIR}/_ext/1295770447/HTTP2.o: ../../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP2.o "../../Microchip/TCPIP Stack/HTTP2.c"  
	
${OBJECTDIR}/_ext/1295770447/HTTP.o: ../../Microchip/TCPIP\ Stack/HTTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP.o "../../Microchip/TCPIP Stack/HTTP.c"  
	
${OBJECTDIR}/_ext/1295770447/ICMP.o: ../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ICMP.o "../../Microchip/TCPIP Stack/ICMP.c"  
	
${OBJECTDIR}/_ext/1295770447/IP.o: ../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/IP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/IP.o.d" -o ${OBJECTDIR}/_ext/1295770447/IP.o "../../Microchip/TCPIP Stack/IP.c"  
	
${OBJECTDIR}/_ext/1295770447/LCDBlocking.o: ../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o "../../Microchip/TCPIP Stack/LCDBlocking.c"  
	
${OBJECTDIR}/_ext/1295770447/MPFS.o: ../../Microchip/TCPIP\ Stack/MPFS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS.o "../../Microchip/TCPIP Stack/MPFS.c"  
	
${OBJECTDIR}/_ext/1295770447/NBNS.o: ../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/NBNS.o "../../Microchip/TCPIP Stack/NBNS.c"  
	
${OBJECTDIR}/_ext/1295770447/Random.o: ../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Random.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Random.o.d" -o ${OBJECTDIR}/_ext/1295770447/Random.o "../../Microchip/TCPIP Stack/Random.c"  
	
${OBJECTDIR}/_ext/1295770447/Reboot.o: ../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" -o ${OBJECTDIR}/_ext/1295770447/Reboot.o "../../Microchip/TCPIP Stack/Reboot.c"  
	
${OBJECTDIR}/_ext/1295770447/RSA.o: ../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/RSA.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/RSA.o.d" -o ${OBJECTDIR}/_ext/1295770447/RSA.o "../../Microchip/TCPIP Stack/RSA.c"  
	
${OBJECTDIR}/_ext/1295770447/SMTP.o: ../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SMTP.o "../../Microchip/TCPIP Stack/SMTP.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMP.o: ../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMP.o "../../Microchip/TCPIP Stack/SNMP.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMPv3.o: ../../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o "../../Microchip/TCPIP Stack/SNMPv3.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o: ../../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o "../../Microchip/TCPIP Stack/SNMPv3USM.c"  
	
${OBJECTDIR}/_ext/1295770447/SNTP.o: ../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNTP.o "../../Microchip/TCPIP Stack/SNTP.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o: ../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o "../../Microchip/TCPIP Stack/SPIEEPROM.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIFlash.o: ../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o "../../Microchip/TCPIP Stack/SPIFlash.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIRAM.o: ../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o "../../Microchip/TCPIP Stack/SPIRAM.c"  
	
${OBJECTDIR}/_ext/1295770447/SSL.o: ../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SSL.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SSL.o.d" -o ${OBJECTDIR}/_ext/1295770447/SSL.o "../../Microchip/TCPIP Stack/SSL.c"  
	
${OBJECTDIR}/_ext/1295770447/StackTsk.o: ../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" -o ${OBJECTDIR}/_ext/1295770447/StackTsk.o "../../Microchip/TCPIP Stack/StackTsk.c"  
	
${OBJECTDIR}/_ext/1295770447/TCP.o: ../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCP.o "../../Microchip/TCPIP Stack/TCP.c"  
	
${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o "../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  
	
${OBJECTDIR}/_ext/1295770447/Telnet.o: ../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" -o ${OBJECTDIR}/_ext/1295770447/Telnet.o "../../Microchip/TCPIP Stack/Telnet.c"  
	
${OBJECTDIR}/_ext/1295770447/TFTPc.o: ../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" -o ${OBJECTDIR}/_ext/1295770447/TFTPc.o "../../Microchip/TCPIP Stack/TFTPc.c"  
	
${OBJECTDIR}/_ext/1295770447/Tick.o: ../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Tick.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Tick.o.d" -o ${OBJECTDIR}/_ext/1295770447/Tick.o "../../Microchip/TCPIP Stack/Tick.c"  
	
${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o: ../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o "../../Microchip/TCPIP Stack/UART2TCPBridge.c"  
	
${OBJECTDIR}/_ext/1295770447/UART.o: ../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART.o "../../Microchip/TCPIP Stack/UART.c"  
	
${OBJECTDIR}/_ext/1295770447/UDP.o: ../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDP.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDP.o "../../Microchip/TCPIP Stack/UDP.c"  
	
${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o "../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o: ../../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o "../../Microchip/TCPIP Stack/ZeroconfHelper.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o: ../../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o "../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o: ../../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o "../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  
	
${OBJECTDIR}/_ext/1472/MPFSImg2.o: ../MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ../MPFSImg2.c  
	
${OBJECTDIR}/_ext/1472/MPFSImg.o: ../MPFSImg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg.o ../MPFSImg.c  
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ../CustomHTTPApp.c  
	
${OBJECTDIR}/_ext/1472/CustomSNMPApp.o: ../CustomSNMPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ../CustomSNMPApp.c  
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ../CustomSSLCert.c  
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	
${OBJECTDIR}/_ext/1472/Cerebot.o: ../Cerebot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Cerebot.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Cerebot.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/Cerebot.o.d" -o ${OBJECTDIR}/_ext/1472/Cerebot.o ../Cerebot.c  
	
${OBJECTDIR}/_ext/1295770447/MPFS2.o: ../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS2.o "../../Microchip/TCPIP Stack/MPFS2.c"  
	
else
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ../BerkeleyTCPClientDemo.c  
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ../BerkeleyTCPServerDemo.c  
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ../BerkeleyUDPClientDemo.c  
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ../GenericTCPClient.c  
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ../GenericTCPServer.c  
	
${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o: ../LegacyHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ../LegacyHTTPApp.c  
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d" -o ${OBJECTDIR}/_ext/1472/PingDemo.o ../PingDemo.c  
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ../SMTPDemo.c  
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" -o ${OBJECTDIR}/_ext/1472/UARTConfig.o ../UARTConfig.c  
	
${OBJECTDIR}/_ext/1295770447/Announce.o: ../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Announce.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Announce.o.d" -o ${OBJECTDIR}/_ext/1295770447/Announce.o "../../Microchip/TCPIP Stack/Announce.c"  
	
${OBJECTDIR}/_ext/1295770447/ARCFOUR.o: ../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o "../../Microchip/TCPIP Stack/ARCFOUR.c"  
	
${OBJECTDIR}/_ext/1295770447/ARP.o: ../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARP.o "../../Microchip/TCPIP Stack/ARP.c"  
	
${OBJECTDIR}/_ext/1295770447/AutoIP.o: ../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" -o ${OBJECTDIR}/_ext/1295770447/AutoIP.o "../../Microchip/TCPIP Stack/AutoIP.c"  
	
${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o: ../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o "../../Microchip/TCPIP Stack/BerkeleyAPI.c"  
	
${OBJECTDIR}/_ext/1295770447/BigInt.o: ../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" -o ${OBJECTDIR}/_ext/1295770447/BigInt.o "../../Microchip/TCPIP Stack/BigInt.c"  
	
${OBJECTDIR}/_ext/1295770447/Delay.o: ../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Delay.o.d" -o ${OBJECTDIR}/_ext/1295770447/Delay.o "../../Microchip/TCPIP Stack/Delay.c"  
	
${OBJECTDIR}/_ext/1295770447/DHCP.o: ../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCP.o "../../Microchip/TCPIP Stack/DHCP.c"  
	
${OBJECTDIR}/_ext/1295770447/DHCPs.o: ../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCPs.o "../../Microchip/TCPIP Stack/DHCPs.c"  
	
${OBJECTDIR}/_ext/1295770447/DNS.o: ../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNS.o "../../Microchip/TCPIP Stack/DNS.c"  
	
${OBJECTDIR}/_ext/1295770447/DNSs.o: ../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNSs.o "../../Microchip/TCPIP Stack/DNSs.c"  
	
${OBJECTDIR}/_ext/1295770447/DynDNS.o: ../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DynDNS.o "../../Microchip/TCPIP Stack/DynDNS.c"  
	
${OBJECTDIR}/_ext/1295770447/ENC28J60.o: ../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o "../../Microchip/TCPIP Stack/ENC28J60.c"  
	
${OBJECTDIR}/_ext/1295770447/ENCX24J600.o: ../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o "../../Microchip/TCPIP Stack/ENCX24J600.c"  
	
${OBJECTDIR}/_ext/1295770447/FileSystem.o: ../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" -o ${OBJECTDIR}/_ext/1295770447/FileSystem.o "../../Microchip/TCPIP Stack/FileSystem.c"  
	
${OBJECTDIR}/_ext/1295770447/FTP.o: ../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/FTP.o "../../Microchip/TCPIP Stack/FTP.c"  
	
${OBJECTDIR}/_ext/1295770447/Hashes.o: ../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" -o ${OBJECTDIR}/_ext/1295770447/Hashes.o "../../Microchip/TCPIP Stack/Hashes.c"  
	
${OBJECTDIR}/_ext/1295770447/Helpers.o: ../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" -o ${OBJECTDIR}/_ext/1295770447/Helpers.o "../../Microchip/TCPIP Stack/Helpers.c"  
	
${OBJECTDIR}/_ext/1295770447/HTTP2.o: ../../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP2.o "../../Microchip/TCPIP Stack/HTTP2.c"  
	
${OBJECTDIR}/_ext/1295770447/HTTP.o: ../../Microchip/TCPIP\ Stack/HTTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP.o "../../Microchip/TCPIP Stack/HTTP.c"  
	
${OBJECTDIR}/_ext/1295770447/ICMP.o: ../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ICMP.o "../../Microchip/TCPIP Stack/ICMP.c"  
	
${OBJECTDIR}/_ext/1295770447/IP.o: ../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/IP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/IP.o.d" -o ${OBJECTDIR}/_ext/1295770447/IP.o "../../Microchip/TCPIP Stack/IP.c"  
	
${OBJECTDIR}/_ext/1295770447/LCDBlocking.o: ../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o "../../Microchip/TCPIP Stack/LCDBlocking.c"  
	
${OBJECTDIR}/_ext/1295770447/MPFS.o: ../../Microchip/TCPIP\ Stack/MPFS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS.o "../../Microchip/TCPIP Stack/MPFS.c"  
	
${OBJECTDIR}/_ext/1295770447/NBNS.o: ../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/NBNS.o "../../Microchip/TCPIP Stack/NBNS.c"  
	
${OBJECTDIR}/_ext/1295770447/Random.o: ../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Random.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Random.o.d" -o ${OBJECTDIR}/_ext/1295770447/Random.o "../../Microchip/TCPIP Stack/Random.c"  
	
${OBJECTDIR}/_ext/1295770447/Reboot.o: ../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" -o ${OBJECTDIR}/_ext/1295770447/Reboot.o "../../Microchip/TCPIP Stack/Reboot.c"  
	
${OBJECTDIR}/_ext/1295770447/RSA.o: ../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/RSA.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/RSA.o.d" -o ${OBJECTDIR}/_ext/1295770447/RSA.o "../../Microchip/TCPIP Stack/RSA.c"  
	
${OBJECTDIR}/_ext/1295770447/SMTP.o: ../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SMTP.o "../../Microchip/TCPIP Stack/SMTP.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMP.o: ../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMP.o "../../Microchip/TCPIP Stack/SNMP.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMPv3.o: ../../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o "../../Microchip/TCPIP Stack/SNMPv3.c"  
	
${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o: ../../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o "../../Microchip/TCPIP Stack/SNMPv3USM.c"  
	
${OBJECTDIR}/_ext/1295770447/SNTP.o: ../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNTP.o "../../Microchip/TCPIP Stack/SNTP.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o: ../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o "../../Microchip/TCPIP Stack/SPIEEPROM.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIFlash.o: ../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o "../../Microchip/TCPIP Stack/SPIFlash.c"  
	
${OBJECTDIR}/_ext/1295770447/SPIRAM.o: ../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o "../../Microchip/TCPIP Stack/SPIRAM.c"  
	
${OBJECTDIR}/_ext/1295770447/SSL.o: ../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SSL.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SSL.o.d" -o ${OBJECTDIR}/_ext/1295770447/SSL.o "../../Microchip/TCPIP Stack/SSL.c"  
	
${OBJECTDIR}/_ext/1295770447/StackTsk.o: ../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" -o ${OBJECTDIR}/_ext/1295770447/StackTsk.o "../../Microchip/TCPIP Stack/StackTsk.c"  
	
${OBJECTDIR}/_ext/1295770447/TCP.o: ../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCP.o "../../Microchip/TCPIP Stack/TCP.c"  
	
${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o "../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  
	
${OBJECTDIR}/_ext/1295770447/Telnet.o: ../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" -o ${OBJECTDIR}/_ext/1295770447/Telnet.o "../../Microchip/TCPIP Stack/Telnet.c"  
	
${OBJECTDIR}/_ext/1295770447/TFTPc.o: ../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" -o ${OBJECTDIR}/_ext/1295770447/TFTPc.o "../../Microchip/TCPIP Stack/TFTPc.c"  
	
${OBJECTDIR}/_ext/1295770447/Tick.o: ../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Tick.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Tick.o.d" -o ${OBJECTDIR}/_ext/1295770447/Tick.o "../../Microchip/TCPIP Stack/Tick.c"  
	
${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o: ../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o "../../Microchip/TCPIP Stack/UART2TCPBridge.c"  
	
${OBJECTDIR}/_ext/1295770447/UART.o: ../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART.o "../../Microchip/TCPIP Stack/UART.c"  
	
${OBJECTDIR}/_ext/1295770447/UDP.o: ../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDP.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDP.o "../../Microchip/TCPIP Stack/UDP.c"  
	
${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o "../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o: ../../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o "../../Microchip/TCPIP Stack/ZeroconfHelper.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o: ../../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o "../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  
	
${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o: ../../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o "../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  
	
${OBJECTDIR}/_ext/1472/MPFSImg2.o: ../MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ../MPFSImg2.c  
	
${OBJECTDIR}/_ext/1472/MPFSImg.o: ../MPFSImg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg.o ../MPFSImg.c  
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ../CustomHTTPApp.c  
	
${OBJECTDIR}/_ext/1472/CustomSNMPApp.o: ../CustomSNMPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ../CustomSNMPApp.c  
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ../CustomSSLCert.c  
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	
${OBJECTDIR}/_ext/1472/Cerebot.o: ../Cerebot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Cerebot.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Cerebot.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/Cerebot.o.d" -o ${OBJECTDIR}/_ext/1472/Cerebot.o ../Cerebot.c  
	
${OBJECTDIR}/_ext/1295770447/MPFS2.o: ../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1295770447 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCerebot32MX4PmodNIC -I"../../Microchip/Include" -I"../.." -I".." -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS2.o "../../Microchip/TCPIP Stack/MPFS2.c"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PIC32MXSK=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PIC32MXSK=1,-L"..",-Map="${DISTDIR}/trafficlights-ethernet.X.${IMAGE_TYPE}.map",-Os  
else
dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-L"..",-Map="${DISTDIR}/trafficlights-ethernet.X.${IMAGE_TYPE}.map",-Os 
	${MP_CC_DIR}\\pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/trafficlights-ethernet.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
