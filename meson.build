project('rc-in-joypad', 'cpp',default_options : ['cpp_std=c++11'])

# Documentation: https://mesonbuild.com/Qt5-module.html
qt5 = import('qt5')
qt5dep = dependency('qt5', modules : ['Core', 'Widgets'])


generated_files = qt5.preprocess(
                            moc_headers : ['mainwindow.hpp', 'joypad.h'],
                            ui_files : 'mainwindow.ui',
                            dependencies: [qt5dep])

executable('rc-in-joypad'
        , 'main.cpp'
        , 'mainwindow.cpp'
        , 'joypad.cpp'
        , generated_files
        , dependencies : [qt5dep]
        , install : true)
