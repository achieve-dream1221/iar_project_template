cc_args = [
    '--data_model=large',
    '--code_model=banked',
    '--calling_convention=xdata_reentrant',
    '--clib'
]

link_args = [
    '-l', '@BASENAME@.map',
    '-xms',
    '-I"D:/Program Files (x86)/iar1030/8051/LIB/"',
    '-f',
    'D:/Program Files (x86)/iar1030/8051/config/devices/Texas Instruments/lnk51ew_CC2530F256_banked.xcl',
    '-I"D:/Program Files (x86)/iar1030/8051/CONFIG/"',
    '-D_NR_OF_VIRTUAL_REGISTERS=8',
    '-D?PBANK=0x93',
    '-D?CBANK=0x9F',
    '-D?CBANK_MASK=0xFF',
    '-e?BCALL_FF=?BCALL',
    '-e?BRET_FF=?BRET',
    '-e?BDISPATCH_FF=?BDISPATCH',
    '-D_CODEBANK_START=0x8000',
    '-D_CODEBANK_END=0xFFFF',
    '-D_NR_OF_BANKS=0x07',
    '-rt',
    '-s', '__program_start',
    'D:/Program Files (x86)/iar1030/8051/LIB/CLIB/cl-pli-blxd-1e16x01.r51',
    '-D_IDATA_STACK_SIZE=0x40',
    '-D?ESP=0',
    '-D?ESP_MASK=0',
    '-D_EXTENDED_STACK_START=0',
    '-D_EXTENDED_STACK_SIZE=0',
    '-D_PDATA_STACK_SIZE=0x80',
    '-D_XDATA_STACK_SIZE=0x1FF',
    '-D_XDATA_HEAP_SIZE=0xFF',
    '-D_FAR_HEAP_SIZE=0xFFF',
    '-D_HUGE_HEAP_SIZE=0xFFF',
    '-D_FAR22_HEAP_SIZE=0xFFF',
]

compiler = generator(icc8051,
                     output : '@BASENAME@.r51',
                     arguments : cc_args + '@INPUT@' + ['-o', '@OUTPUT@'],
)
# 需要编译的文件
soureces = files('main.c')

r51 = compiler.process(soureces)
hex = custom_target('compile_hex',
                    input : r51,
                    output : '@BASENAME@.hex',
                    command : [xlink, '@INPUT@', link_args, '-Ointel-extended=@OUTPUT@'],
)