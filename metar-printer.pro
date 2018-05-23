TEMPLATE = subdirs


SUBDIRS += weather-lib
weather-lib.subdir = src/weather-lib

SUBDIRS += weather-qt
weather-qt.subdir = src/weather-qt
weather-qt.depends = weather-lib

SUBDIRS += weather-cmd
weather-cmd.subdir = src/weather-cmd
weather-cmd.depends = weather-lib
