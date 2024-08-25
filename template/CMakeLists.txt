# Add a executable target named "template"
# 设置编译的可执行文件的后缀名为.d51
set(CMAKE_EXECUTABLE_SUFFIX ".d51")

add_executable(template main.c)

# 为“template”目标设置编译器标志
target_compile_options(template PRIVATE
        $<$<COMPILE_LANGUAGE:C>:
        --core=plain
        --dptr=16,1
        --data_model=large
        --code_model=banked
        --calling_convention=xdata_reentrant
        --place_constants=data_rom
        --nr_virtual_regs=16
        --clib
        # --dlib --dlib_config ${TOOLKIT_DIR}/lib/dlib/dl8051Normal.h
        >
)

# 参数说明: iar安装路径/8051/doc/xlink.ENU.pdf, page: 51
# 为目标设置链接器标志, iar软件不同配置可以对应设置可以看通过iar软件编译输出的map文件的 Command line, 挨个对应修改
target_link_options(template PRIVATE
        # Create a map file from the target's UBROF
        -l $<TARGET_PROPERTY:NAME>.html
        # -xmsh:输出html格式, -xms: .map格式
        -xmsh
        #        "-ID:/Program Files (x86)/iar1030/8051/LIB/"
        -f "D:/Program Files (x86)/iar1030/8051/config/devices/Texas Instruments/lnk51ew_CC2530F256_banked.xcl"
        #        "-ID:/Program Files (x86)/iar1030/8051/CONFIG/"
        "SHELL:-D_NR_OF_VIRTUAL_REGISTERS=8"
        "SHELL:-D?PBANK=0x93"
        "SHELL:-D?CBANK=0x9F"
        "SHELL:-D?CBANK_MASK=0xFF"
        "SHELL:-e?BCALL_FF=?BCALL"
        "SHELL:-e?BRET_FF=?BRET"
        "SHELL:-e?BDISPATCH_FF=?BDISPATCH"
        "SHELL:-D_CODEBANK_START=0x8000"
        "SHELL:-D_CODEBANK_END=0xFFFF"
        "SHELL:-D_NR_OF_BANKS=0x07"
        -rt
        -Ointel-extended=.hex
        #        -s __program_start
        "D:/Program Files (x86)/iar1030/8051/LIB/CLIB/cl-pli-blxd-1e16x01.r51"
        "SHELL:-D_IDATA_STACK_SIZE=0x40"
        "SHELL:-D?ESP=0"
        "SHELL:-D?ESP_MASK=0"
        "SHELL:-D_EXTENDED_STACK_START=0"
        "SHELL:-D_EXTENDED_STACK_SIZE=0"
        "SHELL:-D_PDATA_STACK_SIZE=0x80"
        "SHELL:-D_XDATA_STACK_SIZE=0x1FF"
        "SHELL:-D_XDATA_HEAP_SIZE=0xFF"
        "SHELL:-D_FAR_HEAP_SIZE=0xFFF"
        "SHELL:-D_HUGE_HEAP_SIZE=0xFFF"
        "SHELL:-D_FAR22_HEAP_SIZE=0xFFF"
)

# Link "template" against the "myMath" library
#target_link_libraries(template LINK_PUBLIC myMath)

#[[
# 设置编译类型为Debug
set(BUILD_TYPE Debug)
# 设置烧录软件路径
set(SmartRFProgConsole "D:/Program Files (x86)/Texas Instruments/SmartRF Tools/Flash Programmer/bin/SmartRFProgConsole.exe")

# 烧录程序, 通过S(0)指定烧录板子, 通过F指定烧录文件
# 更多参数说明: 命令行运行 SmartRFProgConsole.exe查看
add_custom_command(TARGET template POST_BUILD
        COMMAND
        ${SmartRFProgConsole}
        "S(53)" EPV F=${CMAKE_CURRENT_BINARY_DIR}/${BUILD_TYPE}/$<TARGET_PROPERTY:NAME>.hex
        # S(n): n: Type S(n), where n is the board ID number, to select a specific EB.
        #      Otherwise, if there are multiple boards, the one to be programmed will be
        #      selected at random.
        # EPV: erase, program, verify
)
]]
