project('iar_project_template', 'c', default_options : ['default_library=static', 'c_std=c99'])
icc8051 = find_program('icc8051', dirs : ['D:/Program Files (x86)/iar1030/8051/bin/'], required : true)
xlink = find_program('xlink', dirs : ['D:/Program Files (x86)/iar1030/8051/bin/'], required : true)
inc = include_directories('D:/Program Files (x86)/iar1030/8051/inc')

subdir('template')