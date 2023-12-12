# Add a executable target named "Z-Stack-template"
# 设置编译的可执行文件的后缀名为.d51
set(CMAKE_EXECUTABLE_SUFFIX ".d51")

file(GLOB Source Source/*.c)

#zstack Components路径
set(Components "E:/clion/zstack-template/Components")
# zstack项目路径
set(Project_Zstack "E:/clion/zstack-template/Projects/zstack")
# cfg文件路径, 复制到项目中,便于修改
set(TOOLS_CFG "E:/clion/iar_project_template/CC2530DB_CONFIG")
# 设置编译类型为Debug
#set(BUILD_TYPE Release)
# 设置烧录软件路径Smart RF Flash Programmer
#set(SmartRFProgConsole "D:/Program Files (x86)/Texas Instruments/SmartRF Tools/Flash Programmer/bin/SmartRFProgConsole.exe")


add_executable(GenericApp
        ${Source}
        ${Components}/osal/mcu/cc2530/OSAL_Math.s51
        ${Project_Zstack}/ZMain/TI2530DB/chipcon_cstartup.s51
        ${Components}/stack/af/AF.c
        ${Components}/stack/bdb/bdb.c
        ${Components}/stack/bdb/bdb_FindingAndBinding.c
        ${Components}/stack/bdb/bdb_Reporting.c
        ${Components}/stack/bdb/bdb_tlCommissioning.c
        ${Components}/stack/bdb/bdb_touchlink.c
        ${Components}/stack/bdb/bdb_touchlink_initiator.c
        ${Components}/stack/bdb/bdb_touchlink_target.c
        ${Components}/stack/nwk/BindingTable.c
        ${Components}/mt/DebugTrace.c
        ${Components}/stack/GP/gp_common.c
        ${Components}/stack/GP/gp_proxyTbl.c
        ${Components}/hal/target/CC2530EB/hal_adc.c
        ${Components}/hal/common/hal_assert.c
        ${Components}/hal/target/CC2530EB/hal_dma.c
        ${Components}/hal/common/hal_drivers.c
        ${Components}/hal/target/CC2530EB/hal_flash.c
        ${Components}/hal/target/CC2530EB/hal_key.c
        ${Components}/hal/target/CC2530EB/hal_lcd.c
        ${Components}/hal/target/CC2530EB/hal_led.c
        ${Components}/hal/target/CC2530EB/hal_sleep.c
        ${Components}/hal/target/CC2530EB/hal_startup.c
        ${Components}/hal/target/CC2530EB/hal_timer.c
        ${Components}/hal/target/CC2530EB/hal_uart.c
        ${Components}/mac/low_level/srf04/mac_autopend.c
        ${Components}/mac/low_level/srf04/mac_backoff_timer.c
        ${Components}/mac/high_level/mac_cfg.c
        ${Components}/mac/low_level/srf04/single_chip/mac_csp_tx.c
        ${Components}/mac/low_level/srf04/mac_low_level.c
        ${Components}/mac/low_level/srf04/single_chip/mac_mcu.c
        ${Components}/mac/low_level/srf04/single_chip/mac_mem.c
        ${Components}/mac/high_level/mac_pib.c
        ${Components}/mac/low_level/srf04/mac_radio.c
        ${Components}/mac/low_level/srf04/single_chip/mac_radio_defs.c
        ${Components}/mac/low_level/srf04/single_chip/mac_rffrontend.c
        ${Components}/mac/low_level/srf04/mac_rx.c
        ${Components}/mac/low_level/srf04/mac_rx_onoff.c
        ${Components}/mac/low_level/srf04/mac_sleep.c
        ${Components}/mac/low_level/srf04/mac_tx.c
        ${Components}/mt/MT.c
        ${Components}/mt/MT_AF.c
        ${Components}/mt/MT_APP.c
        ${Components}/mt/MT_APP_CONFIG.c
        ${Components}/mt/MT_DEBUG.c
        ${Components}/mt/MT_GP.c
        ${Components}/mt/MT_NWK.c
        ${Components}/mt/MT_SAPI.c
        ${Components}/mt/MT_SYS.c
        ${Components}/mt/MT_TASK.c
        ${Components}/mt/MT_UART.c
        ${Components}/mt/MT_UTIL.c
        ${Components}/mt/MT_VERSION.c
        ${Components}/mt/MT_ZDO.c
        ${Components}/stack/nwk/nwk_globals.c
        ${Project_Zstack}/ZMain/TI2530DB/OnBoard.c
        ${Components}/osal/common/OSAL.c
        ${Components}/osal/common/OSAL_Clock.c
        ${Components}/osal/common/OSAL_Memory.c
        ${Components}/osal/mcu/cc2530/OSAL_Nv.c
        ${Components}/osal/common/OSAL_PwrMgr.c
        ${Components}/osal/common/OSAL_Timers.c
        ${Components}/services/saddr/saddr.c
        ${Components}/stack/nwk/stub_aps.c
        ${Components}/stack/zcl/zcl.c
        ${Components}/stack/zcl/zcl_general.c
        ${Components}/stack/zcl/zcl_green_power.c
        ${Project_Zstack}/Source/zcl_ha.c
        ${Components}/stack/zdo/ZDApp.c
        ${Components}/stack/zdo/ZDConfig.c
        ${Components}/stack/sys/ZDiags.c
        ${Components}/stack/zdo/ZDNwkMgr.c
        ${Components}/stack/zdo/ZDObject.c
        ${Components}/stack/zdo/ZDProfile.c
        ${Components}/stack/zdo/ZDSecMgr.c
        ${Components}/stack/sys/ZGlobals.c
        ${Components}/zmac/f8w/zmac.c
        ${Components}/zmac/f8w/zmac_cb.c
        ${Project_Zstack}/ZMain/TI2530DB/ZMain.c
)


# TODO: define Symbols, 预定义宏, 可以在iar软件中查看
target_compile_definitions(GenericApp PRIVATE
        SECURE=1
        TC_LINKKEY_JOIN
        xNV_INIT
        xNV_RESTORE
        xZTOOL_P1
        xMT_TASK
        xMT_APP_FUNC
        xMT_SYS_FUNC
        xMT_ZDO_FUNC
        xMT_ZDO_MGMT
        xMT_APP_CNF_FUNC
        xLEGACY_LCD_DEBUG
        xLCD_SUPPORTED=DEBUG
        MULTICAST_ENABLED=FALSE
        ZCL_READ
        ZCL_WRITE
        ZCL_BASIC
        ZCL_IDENTIFY
        ZCL_SCENES
        xZCL_GROUPS
        HAL_LCD=FALSE
        HAL_UART
        HAL_UART_DMA_RX_MAX=128
        INT_HEAP_LEN=2688
)

# 需要的z-stack库
target_include_directories(GenericApp PRIVATE
        Source
        ${Project_Zstack}/Source
        ${Project_Zstack}/ZMain/TI2530DB
        ${Components}/hal/include
        ${Components}/hal/target/CC2530EB
        ${Components}/mac/include
        ${Components}/mac/high_level
        ${Components}/mac/low_level/srf04
        ${Components}/mac/low_level/srf04/single_chip
        ${Components}/mt
        ${Components}/osal/include
        ${Components}/services/saddr
        ${Components}/services/sdata
        ${Components}/stack/af
        ${Components}/stack/bdb
        ${Components}/stack/gp
        ${Components}/stack/nwk
        ${Components}/stack/sapi
        ${Components}/stack/sec
        ${Components}/stack/sys
        ${Components}/stack/zcl
        ${Components}/stack/zdo
        ${Components}/zmac
        ${Components}/zmac/f8w
)

# 为“Z-Stack-template”目标设置编译器标志
target_compile_options(GenericApp PRIVATE
        $<$<COMPILE_LANGUAGE:C>:
        --core=plain
        --dptr=16,1
        --data_model=large
        --code_model=banked
        --calling_convention=xdata_reentrant
        --place_constants=data_rom
        --nr_virtual_regs 24 #  Specifies number of virtual registers (default 8)
        --clib
        -e #  Enable IAR C/C++ language extensions
        -f ${TOOLS_CFG}/f8wRouter.cfg # TODO: 对应的设备,修改对应的cfg名称,终端设备f8wEndev.cfg, 协调器: f8wCoord.cfg
        # --dlib --dlib_config ${TOOLKIT_DIR}/lib/dlib/dl8051Normal.h
        >
        #        参考地址:https://wwwfiles.iar.com/8051/webic/doc/EW8051_CompilerGuide.pdf
        #__CORE__: An integer that identifies the chip core in use. The value reflects the setting of the
        #--core option and is defined to 1 for Plain, 2 for Extended1, and 3 for Extended2 core.
        #These symbolic names can be used when testing the __CORE__ symbol:
        #__CORE_PLAIN__, __CORE_EXTENDED1__, or __CORE_EXTENDED2__..
        $<$<COMPILE_LANGUAGE:ASM>:
        #        -v0
        -D__CORE__=1 # 1: plain, 2: extended1, 3: extended2
        -D__CODE_MODEL__=2 # 1: near, 2: banked, 3: far, 4: banked extend2
        -D__DATA_MODEL__=2 # 0:tiny, 1: small, 2: large, 3: Generic 4: far 5: far generic
        -D__CALLING_CONVENTION__=4 # 0: data overlay, 1: idata overlay , 2:  idata reentrant, 3: r pdata reentrant, 4: xdata reentrant, 5:extended stack reentrant
        -D__NUMBER_OF_DPTRS__=1
        >
)

# 参数说明: iar安装路径/8051/doc/xlink.ENU.pdf, page: 51
# 为目标设置链接器标志, iar软件不同配置可以对应设置可以看通过iar软件编译输出的map文件的 Command line, 挨个对应修改
target_link_options(GenericApp PRIVATE
        # Create a map file from the target's UBROF
        -l $<TARGET_PROPERTY:NAME>.map
        # -xmsh:输出html格式, -xms: .map格式
        -xmsn
        #        "-ID:/Program Files (x86)/iar1030/8051/LIB/"
        #        -f "D:/Program Files (x86)/iar1030/8051/config/devices/Texas Instruments/lnk51ew_CC2530F256_banked.xcl"
        -f ${TOOLS_CFG}/f8w2530.xcl
        #        "-ID:/Program Files (x86)/iar1030/8051/CONFIG/"
        "SHELL:-D_NR_OF_VIRTUAL_REGISTERS=18"
        "SHELL:-D?PBANK=0x93"
        "SHELL:-D?CBANK=0x9F"
        "SHELL:-D?CBANK_MASK=0xFF"
        "SHELL:-e?BCALL_FF=?BCALL"
        "SHELL:-e?BRET_FF=?BRET"
        "SHELL:-e?BDISPATCH_FF=?BDISPATCH"
        "SHELL:-D_CODEBANK_START=0x8000"
        "SHELL:-D_CODEBANK_END=0xFFFF"
        "SHELL:-D_NR_OF_BANKS=0x07"
        #        -e_small_write=_formatted_write
        #        -e_medium_read=_formatted_read
        #        -we24=i
        -rt
        -Ointel-extended=.hex
        #        -s __program_start
        "D:/Program Files (x86)/iar1030/8051/LIB/CLIB/cl-pli-blxd-1e16x01.r51"
        "SHELL:-D_IDATA_STACK_SIZE=0xC0"
        "SHELL:-D?ESP=0"
        "SHELL:-D?ESP_MASK=0"
        "SHELL:-D_EXTENDED_STACK_START=0"
        "SHELL:-D_EXTENDED_STACK_SIZE=0"
        "SHELL:-D_PDATA_STACK_SIZE=0x80"
        "SHELL:-D_XDATA_STACK_SIZE=0x300"
        "SHELL:-D_XDATA_HEAP_SIZE=0x00"
        "SHELL:-D_FAR_HEAP_SIZE=0x000"
        "SHELL:-D_HUGE_HEAP_SIZE=000"
        "SHELL:-D_FAR22_HEAP_SIZE=0xFFF"
        -C ${Project_Zstack}/Libraries/TI2530DB/bin/Router-Pro.lib # TODO: 对应的设备,修改对应的lib名称,终端设备EndDevice-Pro.lib, 协调器和路由器:Router-Pro.lib
        -C ${Project_Zstack}/Libraries/TI2530DB/bin/Security.lib
        -C ${Project_Zstack}/Libraries/TIMAC/bin/TIMAC-CC2530.lib
)

# Link "Z-Stack-template" against the "myMath" library
#target_link_libraries(Z-Stack-template LINK_PUBLIC myMath)

#[[
# 烧录程序, 通过S(0)指定烧录板子, 通过F指定烧录文件
# 更多参数说明: 命令行运行 SmartRFProgConsole.exe查看
add_custom_command(TARGET GenericApp POST_BUILD
        COMMAND
        ${SmartRFProgConsole}
        "S(53)" EPV F=${CMAKE_CURRENT_BINARY_DIR}/${BUILD_TYPE}/$<TARGET_PROPERTY:NAME>.hex
        # S(n): n: Type S(n), where n is the board ID number, to select a specific EB.
        #      Otherwise, if there are multiple boards, the one to be programmed will be
        #      selected at random.
        # EPV: erase, program, verify
)
]]
